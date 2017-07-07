#ifndef _DTGRAPH_H
#define _DTGRAPH_H

#include "DTGraph/Graph.h"
#include "DTGraph/GenericGraph.h"
#include "DTGraph/Node.h"
#include "Util/BasicTypes.h"
#include <memory>
#include <string>
#include <utility>
#include <vector>

template <class NodeTy,class EdgeTy> class DTGraph : public GenericGraph<NodeTy,EdgeTy>{

 public:
  /*
   * This is the public API
   */
  typedef GenericGraph<NodeTy,EdgeTy> GenericGraphTy;

  DTGraph(void) {
  }


  const char *getNodeName(NodeID id);
  std::vector< std::pair<NodeID,NodeID> > getEdgeIDs(void);

  // virtual void AddNode( DTNode<NodeTy,EdgeTy> * node ) = 0;
    /*
      {
    this->addGNode( node->getId(), node );
  }
    */


};



#endif
