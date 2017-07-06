#include "vtkGraphInteraction.h"


template<class NodeTy,class EdgeTy>
vtkSmartPointer<vtkMutableDirectedGraph> vtkGraphInteractionModel<NodeTy,EdgeTy>::fetchGraphRepresentation(void) {
  if ( dGraph == nullptr )
    return nullptr;

  size_t numEdges = dGraph->edgeNum();
  size_t numNodes = dGraph->nodeNum();

  vtkSmartPointer<vtkMutableDirectedGraph> directedGraph = vtkMutableDirectedGraph::New();
  vtkSmartPointer<vtkStringArray> labels = vtkStringArray::New();
  labels->SetName("Labels");

  // for each node, we want to iterate through them and label them accordingly
  // which is wihtin the graph representation
  for (auto dgi = dGraph->beginNode(), dge = dGraph->endNode(); dgi != dge; dgi++) {
    auto node = *dgi;
    vtkIdType idNode = directedGraph->AddVertex();
    labels->InsertValue( idNode, dgi->Label() );

    // for each node we want to walk down it's outgoing edges and add the destination 
    // as a child 
    for ( auto outEdgeIterStart = dgi->outEdgeBegin(), outEdgeIterStop = dgi->outEdgeEnd();
	  outEdgeIterStart != outEdgeIterStop; 
	  outEdgeIterStart++ ) {
      auto destination = outEdgeIterStart->getDstNode();
      vtkIdType child = directedGraph->AddChild(idNode);
      labels->InsertValue(child, destination->Label());

      
    }
    
   
  } // end of for-each node in the graph...

  directedGraph->GetVertexData()->AddArray(labels);

  return directedGraph;
}
