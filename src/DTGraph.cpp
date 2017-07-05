#include <iostream>

#include "DTGraph.h"

template<class NodeTy,class EdgeTy>
const char * DTGraph<NodeTy,EdgeTy>::getNodeName(NodeID id) {
  return nullptr;
}

template <class NodeTy,class EdgeTy>
std::vector< std::pair<NodeID,NodeID> > DTGraph<NodeTy,EdgeTy>::getEdgeIDs(void) {
  std::vector< std::pair<NodeID,NodeID> > edgePairs;

  for (auto ie = gImplementation->begin(), ee = gImplementation->end(); ie != ee; ie++) {

    // for each node create the edge... and return the pair.
  }
  
  return edgePairs;
}

