#ifndef _PREDICATE_GRAPH_H
#define _PREDICATE_GRAPH_H

#include "DTGraph/Graph.h"
#include "DTGraph/Node.h"
#include "DTGraph/Edge.h"
#include "DTGraph/GenericGraph.h"
#include "Util/BasicTypes.h"
#include "DTGraph.h"

class PredicateNode;
class Direction {
 public:
  Direction(const std::string& s) {
    label = s;
  }

 private:
  std::string label;
};


typedef DTEdge<PredicateNode, Direction> PredicateEdgeTy;

class PredicateEdge : public PredicateEdgeTy {
 public: 
 PredicateEdge(PredicateNode* src, PredicateNode * dst, Direction k) : PredicateEdgeTy(src,dst,k) {
    
  }

};

typedef DTNode<PredicateNode,PredicateEdge> PredicateNodeTy;
class PredicateNode : public PredicateNodeTy {
 public:
 PredicateNode(NodeID id, DTNode::DTNodeE en) : PredicateNodeTy(id,en)  {

  }


};

typedef DTGraph<PredicateNode,PredicateEdge> PredicateGraphTy;
class PredicateGraph : public PredicateGraphTy {
 public:
  PredicateGraph() : DTGraph()  {

  }

  void AddNode( PredicateNode* node ) {
    (this)->addGNode( node->getId(), node);
  }

  void AddEdge( PredicateEdge* edge ) {
    this->addGNode( edge->getSrcID(), edge->getSrcNode() );
    this->addGNode( edge->getDstID(), edge->getDstNode() );
  }

  void AddEdge( PredicateNode *src, PredicateNode *dst, Direction &direction ) {
    PredicateEdge * edge = new PredicateEdge( src, dst, direction );
    src->AddOutGoingEdge( edge );
    
    this->addGNode( src->getId(), src );
    this->addGNode( dst->getId(), dst );
    
  }

};


  



// end of file

#endif
