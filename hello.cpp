#include <BRepPrimAPI_MakeBox.hxx>
#include <TopoDS_Shape.hxx>


#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleTrackballCamera.h>

#include <IVtkTools_ShapeDataSource.hxx>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>


#include <vtkAutoInit.h> 
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);

int main()
{
	BRepPrimAPI_MakeBox mkBox(1.0, 2.0, 3.0);
	const TopoDS_Shape& mShape = mkBox.Shape();

	vtkNew<vtkRenderWindow> renwin;
	vtkNew<vtkRenderer> ren;
	renwin->AddRenderer(ren);

	vtkNew<vtkInteractorStyleTrackballCamera> istyle;
	vtkNew<vtkRenderWindowInteractor> iren;
	iren->SetRenderWindow(renwin);
	iren->SetInteractorStyle(istyle);

	// Domain data (TopoDs_Shape) -> vtkPolyData -> mapper ->actor

	vtkNew< IVtkTools_ShapeDataSource> occSource;
	occSource->SetShape(new IVtkOCC_Shape(mShape));
	vtkNew<vtkPolyDataMapper> mapper;
	mapper->SetInputConnection(occSource->GetOutputPort());
	vtkNew<vtkActor> actor;

	actor->SetMapper(mapper);
	ren->AddActor(actor);



	renwin->Render();
	iren->Start();



	return 0;
}