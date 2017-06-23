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

/*
 * Main
 */
int main(int argc, char *argv[])
{
  
  std::cout << "Exercising Simple Creation test" << std::endl;

  SimpleGraph * simpleGraph;

  std::cout << "Created a bare bones (empty) simple graph" << std::endl;
  
  delete simpleGraph;

  return 0;

}
