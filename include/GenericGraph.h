#ifndef DTGRAPH_GENERIC_GRAPH_H
#define DTGRAPH_GENERIC_GRAPH_H

#include "Util/BasicTypes.h"

/*
 * Generic Node 
 */
template<class NodeTy,class EdgeTy>   
class GenericNode {
 public:
  typedef NodeTy NodeType;
  typedef EdgeTy EdgeType;
  typedef unsigned GNodeEnum;

 private:
  NodeID id;
  
 public:
  // Constructor
 GenericNode(NodeID id, GNodeEnum en) : id(id) {

  }



};

#endif
