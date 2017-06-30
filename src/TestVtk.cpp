#include "vtkAutoInit.h" 
VTK_MODULE_INIT(vtkRenderingOpenGL2); 

#include "vtkActor.h"
#include "vtkDataSetAttributes.h"
#include "vtkGraphLayoutView.h"
#include "vtkMutableDirectedGraph.h"
#include "vtkRandomGraphSource.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkStringArray.h"
#include "vtkTree.h"
#include "vtkViewTheme.h"
#include "vtkGraphMapper.h"

int main(int, char*[])
{
  vtkMutableDirectedGraph* graph = vtkMutableDirectedGraph::New();
  vtkIdType a = graph->AddVertex();
  vtkIdType b = graph->AddChild(a);
  vtkIdType c = graph->AddChild(a);
  vtkIdType d = graph->AddChild(b);
  vtkIdType e = graph->AddChild(c);
  vtkIdType f = graph->AddChild(c);
  vtkIdType g = graph->AddChild(c);
  vtkIdType h = graph->AddChild(g);

  vtkSmartPointer<vtkGraphMapper> mapper = vtkSmartPointer<vtkGraphMapper>::New();
  mapper->SetVertexPointSize(24);

  vtkStringArray* labels = vtkStringArray::New();
  labels->SetName("Label");
  labels->InsertValue(a, "a");
  labels->InsertValue(b, "b");
  labels->InsertValue(c, "c");
  labels->InsertValue(d, "d");
  labels->InsertValue(e, "e");
  labels->InsertValue(f, "f");
  labels->InsertValue(g, "g");
  labels->InsertValue(h, "h");

  graph->GetVertexData()->AddArray(labels);

  vtkTree* tree = vtkTree::New();
  bool validTree = tree->CheckedShallowCopy(graph);
  if (!validTree)
  {
    std::cout << "Invalid tree" << std::endl;
    graph->Delete();
    labels->Delete();
    tree->Delete();
    return EXIT_FAILURE;
  }

  vtkGraphLayoutView* view = vtkGraphLayoutView::New();
  view->SetRepresentationFromInput(tree);
  vtkViewTheme* theme = vtkViewTheme::CreateMellowTheme();
  theme->SetLineWidth(10.0);
  theme->SetPointSize(25.0);

  view->ApplyViewTheme(theme);
  theme->Delete();
  view->SetVertexColorArrayName("VertexDegree");
  view->SetColorVertices(true);
  view->SetColorEdges(true);
  view->SetVertexLabelArrayName("Label");
  view->SetVertexLabelVisibility(true);
  view->EdgeLabelVisibilityOn();
  view->SetLayoutStrategyToForceDirected();
  view->SetVertexLabelFontSize(34);



  view->ResetCamera();
  view->GetInteractor()->Start();

  graph->Delete();
  labels->Delete();
  tree->Delete();
  view->Delete();

  return EXIT_SUCCESS;;
}
