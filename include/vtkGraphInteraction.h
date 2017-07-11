#ifndef _VTK_GRAPH_INTERACTION_MODEL_H
#define _VTK_GRAPH_INTERACTION_MODEL_H

#include <exception>
#include <iostream>

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

  vtkSmartPointer<vtkMutableDirectedGraph> fetchGraphRepresentation(void) {
    if ( dGraph == nullptr )
      return nullptr;

    size_t numEdges = dGraph->edgeNum;
    size_t numNodes = dGraph->nodeNum;

    vtkSmartPointer<vtkMutableDirectedGraph> directedGraph = vtkMutableDirectedGraph::New();
    vtkSmartPointer<vtkStringArray> labels = vtkStringArray::New();
    labels->SetName("Labels");

    // for each node, we want to iterate through them and label them accordingly
    // which is wihtin the graph representation
    for (auto dgi = dGraph->begin(), dge = dGraph->end(); dgi != dge; dgi++) {
      auto node = dgi->second;
      vtkIdType idNode = directedGraph->AddVertex();
      labels->InsertValue( idNode, node->Label() );

      // for each node we want to walk down it's outgoing edges and add the destination 
      // as a child 
      for ( auto outEdgeIterStart = node->outEdgeBegin(), outEdgeIterStop = node->outEdgeEnd();
	    outEdgeIterStart != outEdgeIterStop; 
	    outEdgeIterStart++ ) {
	GenericEdge<NodeTy,EdgeTy> * edge = dynamic_cast< GenericEdge<NodeTy,EdgeTy>* >(*outEdgeIterStart);
	if ( edge ) {
	  GenericNode<NodeTy,EdgeTy> * destination = edge->getDstNode();
	  vtkIdType child = directedGraph->AddChild(idNode);
	  labels->InsertValue(child, destination->Label());
	}
      }
      
    } // end of for-each node in the graph...

    directedGraph->GetVertexData()->AddArray(labels);

    return directedGraph;
  }

};

#endif
