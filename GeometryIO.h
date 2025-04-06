#pragma once
#ifndef GEOMETRY_IO_H
#define GEOMETRY_IO_H

#include <iostream>
#include <string>
#include <filesystem>
#include <TopoDS_Shape.hxx>
#include <string>

class GeometryIO {
public:
    // 加载几何模型：支持 .brep, .step/.stp, .iges/.igs
    static TopoDS_Shape Load(const std::string& filename);

    // 保存几何模型：支持 .brep, .step/.stp, .iges/.igs
    static bool Save(const TopoDS_Shape& shape, const std::string& filename);
};

#endif // GEOMETRY_IO_H
