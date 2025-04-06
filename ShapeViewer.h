// ShapeViewer.hpp
#pragma once

#include <TopoDS_Shape.hxx>
#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkActor.h>
#include <vtkPolyDataMapper.h>
#include <vtkInteractorStyleTrackballCamera.h>

class ShapeViewer {
public:
    ShapeViewer();
    void SetShape(const TopoDS_Shape& shape);
    void Show();

private:
    vtkSmartPointer<vtkRenderer> renderer;
    vtkSmartPointer<vtkRenderWindow> renderWindow;
    vtkSmartPointer<vtkRenderWindowInteractor> interactor;
    vtkSmartPointer<vtkInteractorStyleTrackballCamera> interactorStyle;
    vtkSmartPointer<vtkActor> actor;
    vtkSmartPointer<vtkPolyDataMapper> mapper;
};
