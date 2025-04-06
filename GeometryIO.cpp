
#include "GeometryIO.h"
#include <BRepTools.hxx>
#include <BRep_Builder.hxx>
#include <STEPControl_Reader.hxx>
#include <STEPControl_Writer.hxx>
#include <IGESControl_Reader.hxx>
#include <IGESControl_Writer.hxx>
#include <Interface_Static.hxx>
#include <filesystem>
#include <iostream>

TopoDS_Shape GeometryIO::Load(const std::string& filename) {
    std::string ext = std::filesystem::path(filename).extension().string();

    if (ext == ".brep") {
        TopoDS_Shape shape;
        BRep_Builder builder;
        if (!BRepTools::Read(shape, filename.c_str(), builder)) {
            std::cerr << "Failed to load BREP file: " << filename << std::endl;
        }
        return shape;
    }
    else if (ext == ".step" || ext == ".stp") {
        STEPControl_Reader reader;
        IFSelect_ReturnStatus stat = reader.ReadFile(filename.c_str());
        if (stat == IFSelect_RetDone) {
            reader.TransferRoots();
            return reader.OneShape();
        }
        else {
            std::cerr << "Failed to read STEP file: " << filename << std::endl;
        }
    }
    else if (ext == ".iges" || ext == ".igs") {
        IGESControl_Reader reader;
        IFSelect_ReturnStatus stat = reader.ReadFile(filename.c_str());
        if (stat == IFSelect_RetDone) {
            reader.TransferRoots();
            return reader.OneShape();
        }
        else {
            std::cerr << "Failed to read IGES file: " << filename << std::endl;
        }
    }

    std::cerr << "Unsupported file format: " << ext << std::endl;
    return TopoDS_Shape();
}

bool GeometryIO::Save(const TopoDS_Shape& shape, const std::string& filename) {
    std::string ext = std::filesystem::path(filename).extension().string();

    if (ext == ".brep") {
        return BRepTools::Write(shape, filename.c_str());
    }
    else if (ext == ".step" || ext == ".stp") {
        STEPControl_Writer writer;
        writer.Transfer(shape, STEPControl_AsIs);
        IFSelect_ReturnStatus stat = writer.Write(filename.c_str());
        return stat == IFSelect_RetDone;
    }
    else if (ext == ".iges" || ext == ".igs") {
        IGESControl_Writer writer;
        writer.AddShape(shape);
        writer.ComputeModel();
        return writer.Write(filename.c_str());
    }

    std::cerr << "Unsupported file format for saving: " << ext << std::endl;
    return false;
}
