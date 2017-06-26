#include <iostream>
#include "DTGraph.h"
#include "DTGraph/GenericGraph.h"
#include "DTGraph/Node.h"
#include "DTGraph/Edge.h"

/*
 * Declare our types
 */

class SimpleNode;

typedef DTEdge<SimpleNode,int> SimpleEdgeTy;

class SimpleEdge : public SimpleEdgeTy {
  
};


typedef DTNode<SimpleNode,SimpleEdge> SimpleNodeTy;
class SimpleNode : public SimpleNodeTy {
  
};

typedef DTGraph<SimpleNode,SimpleEdge> SimpleGraphTy;
class SimpleGraph : public SimpleGraphTy {

};


template <> DTGraph<SimpleNode,SimpleEdge>::DTGraph() {
  gImplementation = std::make_unique<GenericGraphTy>();
}

/*
 * Main
 */
int main(int argc, char *argv[])
{
  
  std::cout << "Exercising Simple Creation test" << std::endl;

  SimpleGraph * simpleGraph = new SimpleGraph;

  std::cout << "Created a bare bones (empty) simple graph" << std::endl;
  std::cout << "There are " << simpleGraph->edgeNum() << " # of edges" << std::endl;
  std::cout << "There are " << simpleGraph->nodeNum() << " # of nodes" << std::endl;

  delete simpleGraph;

  return 0;

}
