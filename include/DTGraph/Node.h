#ifndef DTGRAPH_NODE_H
#define DTGRAPH_NODE_H

#include "Util/BasicTypes.h"
#include "DTGraph/GenericGraph.h"
#include <memory.h>
#include <list>

class DTNode;
class DTEdge;

/*
 * Typedef for a generic DTNode
 */
typedef GenericNode<DTNode, DTEdge> GenericDTNodeTy;

class DTNode : public GenericDTNodeTy {

 public:
  enum DTNodeE {
    Branch, Result, Decision, Empty
  };
  

 public:
  // Constructor
    DTNode(NodeID id, DTNodeE en) : GenericNode(id,en) {

  }

  
  
};

#endif
