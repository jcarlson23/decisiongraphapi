#include <iostream>
#include "DTGraph.h"
#include "PredicateGraph.h"
#include "vtkGraphInteraction.h"



/*
 * Modify to include the DTGraph to VTK interactivity
 */
#include "vtkGraphInteraction.h"

int main(int argc, char *argv[]) {
  
  std::cout << "Exercising simple predicate graph creation." << std::endl;
  
  PredicateGraph * predicateGraph = new PredicateGraph;
  PredicateNode * root = new PredicateNode( 0, PredicateNodeTy::Root );
  PredicateNode * alpha= new PredicateNode( 1, PredicateNodeTy::Regular );
  PredicateNode * beta = new PredicateNode( 2, PredicateNodeTy::Regular );
  Direction down = Direction("down");
  PredicateEdge * edge1= new PredicateEdge( root, alpha, down );
  PredicateEdge * edge2= new PredicateEdge( root, beta, down );

  predicateGraph->AddEdge( root, alpha, down );
  predicateGraph->AddEdge( root, beta, down );

  std::cout << "Created a bare bones (empty) simple graph" << std::endl;
  std::cout << "There are " << predicateGraph->getTotalEdgeNum() << " # of edges" << std::endl;
  std::cout << "There are " << predicateGraph->getTotalNodeNum() << " # of nodes" << std::endl;

  vtkGraphInteractionModel<PredicateNode,PredicateEdge> * interactionModel =
    new vtkGraphInteractionModel<PredicateNode,PredicateEdge>();

  interactionModel->setGraph( predicateGraph );
  vtkSmartPointer<vtkMutableDirectedGraph> directedGraph = interactionModel->generateVtkGraph();
  
  
  delete interactionModel;
  delete predicateGraph;

  return 0;

}
