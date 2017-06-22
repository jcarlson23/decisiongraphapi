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
  DTGraph(void) {}

 private:
  std::unique_ptr<GenericGraph<NodeTy,EdgeTy> > gImplementation;
  
};



#endif
