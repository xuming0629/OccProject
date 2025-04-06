#include "ShapeViewer.h"
#include "ShapeBase.h"
#include "BoxShape.h"
#include "CylinderShape.h"
#include "ConeShape.h"
#include "CustomShape.h"

#include <memory>
#include <vtkAutoInit.h>

VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);

int main() {
    // 使用不同形状，只需替换这一行
    //std::unique_ptr<ShapeBase> shape = std::make_unique<CylinderShape>(1.0, 2.0);
    // std::unique_ptr<ShapeBase> shape = std::make_unique<BoxShape>(1.0, 2.0, 3.0);
    // std::unique_ptr<ShapeBase> shape = std::make_unique<ConeShape>(1.0, 0.5, 2.0);
    std::unique_ptr<ShapeBase> shape = std::make_unique<CustomShape>();

    ShapeViewer viewer;
    viewer.SetShape(shape->GetShape());
    viewer.Show();

    return 0;
}
