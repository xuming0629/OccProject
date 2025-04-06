#pragma once
#include "ShapeBase.h"
#include <BRepPrimAPI_MakeBox.hxx>

class BoxShape : public ShapeBase {
public:
    BoxShape(double dx, double dy, double dz)
        : shape(BRepPrimAPI_MakeBox(dx, dy, dz).Shape()) {
    }

    TopoDS_Shape GetShape() const override {
        return shape;
    }

private:
    TopoDS_Shape shape;
};
