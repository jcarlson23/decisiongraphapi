#ifndef DTGRAPH_GENERIC_GRAPH_H
#define DTGRAPH_GENERIC_GRAPH_H

#include <iostream>

#include <list>
#include <set>
#include "Util/BasicTypes.h"

/*
 * Generic Edge on the graph
 */
template<class NodeTy,class EdgeK> class GenericEdge {

 public:
  typedef NodeTy NodeType;
  
 protected:
  NodeTy * src;   // the source node of the edge
  NodeTy * dst;   // the destination node of the endge

  EdgeK edgeFlag; // the kind of edge we have here
  
 public:
   GenericEdge(NodeTy *s, NodeTy *d, EdgeK k) : src(s), dst(d), edgeFlag(k) {
  }
  
  virtual ~GenericEdge() {
  }

  inline NodeID getSrcID() const {
    return src->getId();
  }

  inline NodeID getDstID() const {
    return dst->getId();
  }

  NodeTy *getSrcNode() const {
    return src;
  }

  NodeTy *getDstNode() const {
    return dst;
  }

};
 

/*
 * Generic Node 
 */
template<class NodeTy,class EdgeTy>   
class GenericNode {
 public:
  typedef NodeTy NodeType;
  typedef EdgeTy EdgeType;
  typedef unsigned GNodeEnum;
  
  typedef std::set<EdgeTy*> GEdgeSetTy;

  typedef typename GEdgeSetTy::iterator iterator;
  typedef typename GEdgeSetTy::const_iterator const_iterator;
  
 private:
  NodeID id;
  
  GEdgeSetTy InEdges;
  GEdgeSetTy OutEdges;
  
 public:
  // Constructor
  GenericNode(NodeID id, GNodeEnum en) : id(id) {

  }

  virtual ~GenericNode() {
    for (iterator it = InEdges.begin(), eit = InEdges.end(); it != eit; ++it )
      delete *it;
  }

  inline NodeID getId() const {
    return id;
  }
  
};

/*
 * Generic Graph
 */
template<class NodeTy,class EdgeTy> class GenericGraph {
 public:
  
  typedef GenericNode<NodeTy,EdgeTy> GenericNodeTy;
  typedef std::map<NodeID,NodeTy> NodeMapTy;
  typedef std::map<EdgeID,EdgeTy> EdgeMapTy;

  typedef typename NodeMapTy::iterator iterator;
  typedef typename NodeMapTy::const_iterator const_iterator;

  GenericGraph() : edgeNum(0), nodeNum(0) {
    std::cout << "Created Generic Graph..." << std::endl;
  }

  virtual ~GenericGraph() {
    destroy();
  }


 protected:
  void destroy() {
  }

  std::set<GenericNodeTy> Nodes;
  NodeMapTy NodeMap;
  EdgeMapTy EdgeMap;

 public:
  size_t edgeNum;
  size_t nodeNum;
  
};

#endif
