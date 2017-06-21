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

