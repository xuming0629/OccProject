#pragma once
#pragma once
#include <TopoDS_Shape.hxx>

class ShapeBase {
public:
    virtual ~ShapeBase() = default;
    virtual TopoDS_Shape GetShape() const = 0;
};
