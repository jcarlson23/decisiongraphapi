#ifndef DTGRAPH_GENERIC_GRAPH_H
#define DTGRAPH_GENERIC_GRAPH_H

#include <list>
#include <set>
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

/*
 * Generic Graph
 */
template<class NodeTy,class EdgeTy> class GenericGraph {
 public:
  GenericGraph() {}
  
  typedef GenericNode<NodeTy,EdgeTy> GenericNodeTy;
  typedef std::map<NodeTy,NodeID> NodeMapTy;
  typedef std::map<EdgeTy,EdgeID> EdgeMapTy;


 private:

  std::set<GenericNodeTy> Nodes;
  NodeMapTy NodeMap;
  EdgeMapTy EdgeMap;
  
};

#endif
