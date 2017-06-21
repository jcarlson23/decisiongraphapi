## Goals

The design of this library is to make a decision graph more interactive, to
be query, traverse and view the conditions of the decision (or branch point)
as well as the consequences.

## API

API design is written in C++; with possible extensions to Python and Ruby
to be considered later as needed or wanted.

## API Design

The API is centered around the idea of providing the simplest, complete
subgraph as necessary.  The entire graph can be interacted with, viewed, 
and so forth, but it always presented as a subgraph.  Viewing the entire
graph is just a special case, and generally discouraged for the case 
when we have large numbers of nodes (there should be a warning and
associated memory and other checks prior to realizing the given subgraph.

### Generic Graph

Borrowing from both LLVM and SVF (which itself is made for LLVM based analyssi),
we have the following class structure.

We define abstract node, edge pairs as such:

```typedef GenericGraph <Node,Edge> GenericDTGraphTy;```

The Graph itself will contain a set of maps from the nodeID to the node, as
well as from the decision id to the decision node, and the view id to the 
view type.

The purpose of these are:

* NodeID tracks unique nodes for each decision point.
* Decision ID allows us to map a decision to a node.
* View ID to a view type, allowing a reference for viewing.

