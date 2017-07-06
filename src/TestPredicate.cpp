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

  std::cout << "Created a bare bones (empty) simple graph" << std::endl;
  std::cout << "There are " << predicateGraph->edgeNum() << " # of edges" << std::endl;
  std::cout << "There are " << predicateGraph->nodeNum() << " # of nodes" << std::endl;

  delete predicateGraph;

  return 0;

}
