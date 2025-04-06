#pragma once
#include "ShapeBase.h"
#include <BRepBuilderAPI_MakePolygon.hxx>

class CustomShape : public ShapeBase {
public:
    CustomShape() {
        BRepBuilderAPI_MakePolygon poly;
        poly.Add(gp_Pnt(0, 0, 0));
        poly.Add(gp_Pnt(10, 0, 0));
        poly.Add(gp_Pnt(5, 10, 0));
        poly.Close(); // ±ÕºÏÏß

        shape = poly.Shape();
    }

    TopoDS_Shape GetShape() const override {
        return shape;
    }

private:
    TopoDS_Shape shape;
};
