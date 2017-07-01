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
#include "vtkGlyph2D.h"
#include "vtkGlyphSource2D.h"
#include "vtkPolyData.h"
#include "vtkSmartPointer.h"
#include "vtkInteractorStyleRubberBand2D.h"
#include "vtkSelection.h"
#include "vtkSelectionNode.h"
#include "vtkDataRepresentation.h"
#include "vtkAnnotationLink.h"
#include "vtkRenderedGraphRepresentation.h"

class RubberBandStyle : public vtkInteractorStyleRubberBand2D {
public:
  static RubberBandStyle * New();
  vtkTypeMacro(RubberBandStyle, vtkInteractorStyleRubberBand2D);

  virtual void OnLeftButtonUp() override {
    vtkInteractorStyleRubberBand2D::OnLeftButtonUp();
    vtkSelection * selection = this->view->GetRepresentation()->GetAnnotationLink()->GetCurrentSelection();
    vtkSelectionNode * vertices;
    vtkSelectionNode * edges;
    
    if ( selection->GetNode(0)->GetFieldType() == vtkSelectionNode::VERTEX)
      vertices = selection->GetNode(0);
    else if ( selection->GetNode(0)->GetFieldType() == vtkSelectionNode::EDGE )
      edges = selection->GetNode(0);

    if ( selection->GetNode(1)->GetFieldType() == vtkSelectionNode::VERTEX)
      vertices = selection->GetNode(1);
    else if ( selection->GetNode(1)->GetFieldType() == vtkSelectionNode::EDGE )
      edges = selection->GetNode(1);
    
    vtkIdTypeArray * vertexList = vtkIdTypeArray::SafeDownCast(vertices->GetSelectionList());
    std::cout << "There are " << vertexList->GetNumberOfTuples() << " vertices selected." << std::endl;
    
    if ( vertexList->GetNumberOfTuples() > 0)
      std::cout << "Vertex ID's: ";
    for ( vtkIdType i = 0; i<vertexList->GetNumberOfTuples(); i++)
      std::cout << vertexList->GetValue(i) << " ";

    std::cout << std::endl;

    vtkIdTypeArray * edgeList = vtkIdTypeArray::SafeDownCast(edges->GetSelectionList());
    std::cout << "There are " << edgeList->GetNumberOfTuples() << " edges selected." << std::endl;
    if ( edgeList->GetNumberOfTuples() > 0 )
      std::cout << "Edge ID's: ";
    for (vtkIdType i = 0; i< edgeList->GetNumberOfTuples(); i++)
      std::cout << edgeList->GetValue(i) << " ";

    std::cout << std::endl;

  }

  vtkGraphLayoutView * view;

};

vtkStandardNewMacro(RubberBandStyle);

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
  theme->SetLineWidth(8.0);
  theme->SetPointSize(10.0);

  vtkSmartPointer<RubberBandStyle> style = vtkSmartPointer<RubberBandStyle>::New();
  style->view = view;
 
  view->SetInteractorStyle(style);
  
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
  view->SetGlyphType(2);
  view->ResetCamera();
  view->GetInteractor()->Start();

  graph->Delete();
  labels->Delete();
  tree->Delete();
  view->Delete();

  
  return EXIT_SUCCESS;;
}
