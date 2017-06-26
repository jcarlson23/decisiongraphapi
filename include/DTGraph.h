#ifndef _DTGRAPH_H
#define _DTGRAPH_H

#include "DTGraph/Graph.h"
#include "DTGraph/GenericGraph.h"
#include "Util/BasicTypes.h"
#include <memory>

template <class NodeTy,class EdgeTy> class DTGraph {

 public:
  /*
   * This is the public API
   */
  typedef GenericGraph<NodeTy,EdgeTy> GenericGraphTy;

  DTGraph(void) {
    std::cout << "Creating generic graph" << std::endl;
    gImplementation = std::make_unique<GenericGraphTy>();
    std::cout << "Should have called the generic constructor." << std::endl;
  }

  size_t edgeNum(void) { return gImplementation->edgeNum; }
  size_t nodeNum(void) { return gImplementation->nodeNum; }

 private:
  std::unique_ptr<GenericGraphTy> gImplementation;
  


};



#endif
