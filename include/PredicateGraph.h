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
  
};

typedef DTEdge<PredicateNode, Direction> PredicateEdgeTy;
class PredicateEdge : PredicateEdgeTy {

};

typedef DTNode<PredicateNode,PredicateEdge> PredicateNodeTy;
class PredicateNode : public PredicateNodeTy {

};

typedef DTGraph<PredicateNode,PredicateEdge> PredicateGraphTy;
class PredicateGraph : public PredicateGraphTy {

};


// end of file

#endif
