#include <iostream>
#include "DTGraph.h"
#include "PredicateGraph.h"

								 

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
  PredicateEdge * edge1= new PredicateEdge( root, alpha, Direction("down") );
  PredicateEdge * edge2= new PredicateEdge( root, beta, Direction("down") );
  root->AddOutGoingEdge( edge1 );
  root->AddOutGoingEdge( edge2 );
  predicateGraph->AddNode( root );
  predicateGraph->AddNode( alpha );
  predicateGraph->AddNode( beta );

  std::cout << "Created a bare bones (empty) simple graph" << std::endl;
  std::cout << "There are " << predicateGraph->edgeNum << " # of edges" << std::endl;
  std::cout << "There are " << predicateGraph->nodeNum << " # of nodes" << std::endl;

  delete predicateGraph;

  return 0;

}
