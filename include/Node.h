#ifndef DTGRAPH_NODE_H
#define DTGRAPH_NODE_H

#include "Util/BasicTypes.h"
#include <memory.h>
#include <list>

class DTNode;
class DTEdge;

typedef GenericNode<DTNode, DTEdge> GenericNodeTy;

class DTNode : public GenericNodeTy {

 public:
  enum DTNodeE {
    Branch, Result, Decision, Empty
  };
  

 public:
  // Constructor
  DTNode(NodeID id, DTNodeE en); GenericNodeTy(id,en) {

  }

  
  
};

#endif
