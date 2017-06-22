#ifndef _DTGRAPH_GRAPH_TRAITS_H
#define _DTGRAPH_GRAPH_TRAITS_H

#include <list>
#include <memory>
#include <algorithm>

/*
 * Let's directly borrow from the LLVM GraphTraits model so that we are
 * compatible with the LLVM infrastructure.
 */
namespace dgapi {

  // we create an inverse to reach up
  template <class GraphType> struct Inverse {
    const GraphType &Graph;
    
    inline Inverse(const GraphType& G) : Graph(G) {}
  };
  
  template <class T> struct GraphTraits<Inverse<Inverse<T> > > {
    typedef typename GraphTraits<T>::NodeType NodeType;
    typedef typename GraphTraits<T>::ChildIteratorType ChildIteratorType;
    
    static NodeType * getEntryNode(Inverse<Inverse<T> > *G) {
      return GraphTraits<T>::getEntryNode( G->Graph.Graph );
    }

    static ChildIteratorType child_begin(NodeType *N) {
      return GraphTraits<T>::child_begin(N);
    }

    static ChildIteratorType child_end(NodeType *N) {
      return GraphTraits<T>::child_end(N);
    }

  };

} // end of dgapi namespace

#endif
