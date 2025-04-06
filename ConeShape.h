#pragma once
#include "ShapeBase.h"
#include <BRepPrimAPI_MakeCone.hxx>

#include "GeometryIO.h"

class ConeShape : public ShapeBase {
public:

    ConeShape() {
        m_shape = TopoDS_Shape();  // 初始化为空形状
    }
    ConeShape(double radius1, double radius2, double height)
        : m_shape(BRepPrimAPI_MakeCone(radius1, radius2, height).Shape()) {
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
