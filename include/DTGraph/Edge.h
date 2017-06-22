#ifndef _DTGRAPH_EDGE_H
#define _DTGRAPH_EDGE_H

#include "DTGraph/GenericGraph.h"
#include "DTGraph/Node.h"
#include "Util/BasicTypes.h"

template <class NodeTy, class T> class DTEdge : public GenericEdge<NodeTy, T> {

 public:
   DTEdge(NodeTy *s, NodeTy *d, T e) : GenericEdge<NodeTy,T>(s,d,e) {

  }

 private:
  
};

#endif
