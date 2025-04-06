// ShapeViewer.cpp

#include "ShapeViewer.h"
#include <IVtkTools_ShapeDataSource.hxx>
#include <IVtkOCC_Shape.hxx>

ShapeViewer::ShapeViewer() {
    renderer = vtkSmartPointer<vtkRenderer>::New();
    renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    interactorStyle = vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New();
    actor = vtkSmartPointer<vtkActor>::New();
    mapper = vtkSmartPointer<vtkPolyDataMapper>::New();

    renderWindow->AddRenderer(renderer);
    interactor->SetRenderWindow(renderWindow);
    interactor->SetInteractorStyle(interactorStyle);
}

void ShapeViewer::SetShape(const TopoDS_Shape& shape) {
    vtkNew<IVtkTools_ShapeDataSource> occSource;
    occSource->SetShape(new IVtkOCC_Shape(shape));
    mapper->SetInputConnection(occSource->GetOutputPort());
    actor->SetMapper(mapper);
    renderer->AddActor(actor);
}

void ShapeViewer::Show() {
    renderWindow->Render();
    interactor->Start();
}

