#pragma once
#include "ShapeBase.h"
#include <BRepBuilderAPI_MakePolygon.hxx>

#include "GeometryIO.h"

class CustomShape : public ShapeBase {
public:
    CustomShape() {
        m_shape = TopoDS_Shape();  // 初始化为空形状
    }
    CustomShape() {
        BRepBuilderAPI_MakePolygon poly;
        poly.Add(gp_Pnt(0, 0, 0));
        poly.Add(gp_Pnt(10, 0, 0));
        poly.Add(gp_Pnt(5, 10, 0));
        poly.Close(); // 闭合线

        m_shape = poly.Shape();
    }

    TopoDS_Shape GetShape() const override {
        return m_shape;
    }

    bool Save(const std::string& filename) const override {
        return GeometryIO::Save(m_shape, filename);
    }

    bool Load(const std::string& filename) override {
        m_shape = GeometryIO::Load(filename);
        return !m_shape.IsNull();
    }

private:
    TopoDS_Shape m_shape;
};
