#include <iostream>

#include "DTGraph.h"

template<class NodeTy,class EdgeTy> 
DTGraph<NodeTy,EdgeTy>::DTGraph(void) {
  std::cout << "Creating generic graph" << std::endl;
  gImplementation = std::make_unique<GenericGraphTy>();
  std::cout << "Should have called the generic constructor." << std::endl;

}
