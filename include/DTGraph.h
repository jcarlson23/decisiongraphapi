#ifndef _DTGRAPH_H
#define _DTGRAPH_H

#include "DTGraph/Graph.h"
#include "DTGraph/GenericGraph.h"
#include "Util/BasicTypes.h"
#include <memory>
#include <string>
#include <utility>
#include <vector>

template <class NodeTy,class EdgeTy> class DTGraph {

 public:
  /*
   * This is the public API
   */
  typedef GenericGraph<NodeTy,EdgeTy> GenericGraphTy;

  DTGraph(void) {
    gImplementation = std::make_unique<GenericGraphTy>();
  }

  size_t edgeNum(void) { return gImplementation->edgeNum; }
  size_t nodeNum(void) { return gImplementation->nodeNum; }

  const char *getNodeName(NodeID id);
  std::vector< std::pair<NodeID,NodeID> > getEdgeIDs(void);

  inline typename GenericGraphTy::iterator beginNode() { return gImplementation->begin(); }
  inline typename GenericGraphTy::const_iterator beginNode() const { return gImplementation->begin(); }
  inline typename GenericGraphTy::iterator endNode() { return gImplementation->end(); }
  inline typename GenericGraphTy::const_iterator endNode() const { return gImplementation->end(); }

 private:
  std::unique_ptr<GenericGraphTy> gImplementation;

};



#endif
