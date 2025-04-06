#pragma once
#include "ShapeBase.h"
#include <BRepPrimAPI_MakeCylinder.hxx>

class CylinderShape : public ShapeBase {
public:
    CylinderShape(double radius, double height)
        : shape(BRepPrimAPI_MakeCylinder(radius, height).Shape()) {
    }

    TopoDS_Shape GetShape() const override {
        return shape;
    }

private:
    TopoDS_Shape shape;
};
