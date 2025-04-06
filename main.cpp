//#include "ShapeViewer.h"
//#include "ShapeBase.h"
//#include "BoxShape.h"
//#include "CylinderShape.h"
//#include "ConeShape.h"
//#include "CustomShape.h"
//
//#include <memory>
//#include <vtkAutoInit.h>
//
//VTK_MODULE_INIT(vtkRenderingOpenGL2);
//VTK_MODULE_INIT(vtkInteractionStyle);
//
//int main() {
//    // 使用不同形状，只需替换这一行
//    //std::unique_ptr<ShapeBase> shape = std::make_unique<CylinderShape>(1.0, 2.0);
//    // std::unique_ptr<ShapeBase> shape = std::make_unique<BoxShape>(1.0, 2.0, 3.0);
//    // std::unique_ptr<ShapeBase> shape = std::make_unique<ConeShape>(1.0, 0.5, 2.0);
//    std::unique_ptr<ShapeBase> shape = std::make_unique<CustomShape>();
//
//    ShapeViewer viewer;
//    viewer.SetShape(shape->GetShape());
//    viewer.Show();
//
//    return 0;
//}

//#include "ShapeViewer.h"
//#include "ShapeBase.h"
//#include "BoxShape.h"
//#include "CylinderShape.h"
//#include "ConeShape.h"
//#include "CustomShape.h"
//
//#include <memory>
//#include <vtkAutoInit.h>
//
//VTK_MODULE_INIT(vtkRenderingOpenGL2);
//VTK_MODULE_INIT(vtkInteractionStyle);
//
//int main() {
//    // 创建并保存 BoxShape
//    std::unique_ptr<ShapeBase> boxShape = std::make_unique<BoxShape>(1.0, 2.0, 3.0);
//    boxShape->Save("box.brep");
//
//    // 创建并保存 CylinderShape
//    std::unique_ptr<ShapeBase> cylinderShape = std::make_unique<CylinderShape>(1.0, 2.0);
//    cylinderShape->Save("cylinder.brep");
//
//    // 创建并保存 ConeShape
//    std::unique_ptr<ShapeBase> coneShape = std::make_unique<ConeShape>(1.0, 0.5, 2.0);
//    coneShape->Save("cone.brep");
//
//    // 创建并保存 CustomShape
//    std::unique_ptr<ShapeBase> customShape = std::make_unique<CustomShape>();
//    customShape->Save("custom_shape.brep");
//
//    // 加载并显示保存的 BoxShape
//    std::unique_ptr<ShapeBase> loadedShape = std::make_unique<BoxShape>();
//    loadedShape->Load("box.brep");
//
//    ShapeViewer viewer;
//    viewer.SetShape(loadedShape->GetShape());
//    viewer.Show();
//
//    return 0;
//}

// 加载并显示保存的 BoxShape
#include "ShapeViewer.h"
#include "ShapeBase.h"
#include "BoxShape.h"
#include "CylinderShape.h"
#include "ConeShape.h"
#include "CustomShape.h"

#include <memory>
#include <vtkAutoInit.h>
#include <iostream>

VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);

int main() {
    // 创建并保存 BoxShape
    std::unique_ptr<ShapeBase> boxShape = std::make_unique<BoxShape>(1.0, 2.0, 3.0);
    if (boxShape->Save("box.brep")) {
        std::cout << "Box shape saved successfully." << std::endl;
    }
    else {
        std::cerr << "Failed to save Box shape." << std::endl;
    }

    // 创建并保存 CylinderShape
    std::unique_ptr<ShapeBase> cylinderShape = std::make_unique<CylinderShape>(1.0, 2.0);
    if (cylinderShape->Save("cylinder.brep")) {
        std::cout << "Cylinder shape saved successfully." << std::endl;
    }
    else {
        std::cerr << "Failed to save Cylinder shape." << std::endl;
    }

    // 创建并保存 ConeShape
    std::unique_ptr<ShapeBase> coneShape = std::make_unique<ConeShape>(1.0, 0.5, 2.0);
    if (coneShape->Save("cone.brep")) {
        std::cout << "Cone shape saved successfully." << std::endl;
    }
    else {
        std::cerr << "Failed to save Cone shape." << std::endl;
    }

    // 创建并保存 CustomShape
    std::unique_ptr<ShapeBase> customShape = std::make_unique<CustomShape>();
    if (customShape->Save("custom_shape.brep")) {
        std::cout << "Custom shape saved successfully." << std::endl;
    }
    else {
        std::cerr << "Failed to save Custom shape." << std::endl;
    }

    // 加载并显示保存的 BoxShape
    std::unique_ptr<ShapeBase> loadedShape = std::make_unique<BoxShape>();
    if (loadedShape->Load("box.brep")) {
        std::cout << "Box shape loaded successfully." << std::endl;
        ShapeViewer viewer;
        viewer.SetShape(loadedShape->GetShape());
        viewer.Show();
    }
    else {
        std::cerr << "Failed to load Box shape." << std::endl;
    }

    return 0;
}
