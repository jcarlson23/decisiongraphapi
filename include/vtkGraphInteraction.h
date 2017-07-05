#ifndef _VTK_GRAPH_INTERACTION_MODEL_H
#define _VTK_GRAPH_INTERACTION_MODEL_H

#include "DTGraph.h"

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

template<class NodeTy, class EdgeTy> 
class vtkGraphInteractionModel {
  
 public:
  vtkGraphInteractionModel() {
    dGraph = nullptr;
  }
  
  ~vtkGraphInteractionModel() {
    releaseGraph();
  }

  void setGraph(DTGraph<NodeTy,EdgeTy> * g) { dGraph = g; }
  void releaseGraph(void) { dGraph = nullptr; }
  
  vtkSmartPointer<vtkMutableDirectedGraph> generateVtkGraph(void) {
    return fetchGraphRepresentation();
  }
  

 private:
  DTGraph<NodeTy,EdgeTy>* dGraph;

  vtkSmartPointer<vtkMutableDirectedGraph> fetchGraphRepresentation(void);

};

#endif
