#pragma once
#include "ShapeBase.h"
#include <BRepPrimAPI_MakeCylinder.hxx>

#include "GeometryIO.h"

class CylinderShape : public ShapeBase {
public:
    CylinderShape() {
        m_shape = TopoDS_Shape();  // 初始化为空形状
    }
    CylinderShape(double radius, double height)
        : m_shape(BRepPrimAPI_MakeCylinder(radius, height).Shape()) {
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
