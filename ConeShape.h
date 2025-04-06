#pragma once
#include "ShapeBase.h"
#include <BRepPrimAPI_MakeCone.hxx>

class ConeShape : public ShapeBase {
public:
    ConeShape(double radius1, double radius2, double height)
        : shape(BRepPrimAPI_MakeCone(radius1, radius2, height).Shape()) {
    }

    TopoDS_Shape GetShape() const override {
        return shape;
    }

private:
    TopoDS_Shape shape;
};
