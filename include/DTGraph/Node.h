#ifndef DTGRAPH_NODE_H
#define DTGRAPH_NODE_H

#include "Util/BasicTypes.h"
#include "DTGraph/GenericGraph.h"
#include "DTGraph/Edge.h"
#include <memory.h>
#include <list>

/*
 * Typedef for a generic DTNode
 */

template<class NodeTy, class EdgeTy> 
  class DTNode : public GenericNode<NodeTy,EdgeTy> {

 public:
  enum DTNodeE {
    Branch, Result, Decision, Empty
  };
  

 public:
  // Constructor
   DTNode(NodeID id, DTNodeE en) : GenericNode<NodeTy,EdgeTy>(id,en) {

  }

  
  
};

#endif
