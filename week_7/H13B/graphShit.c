///// Adjacency list graph representation

struct graphRep {
    int nV;       // #vertices
    int nE;       // #edges
    List *edges;  // array of Vertex lists
};


// (e.v < e.w)
Edge *edges(Graph g, int *nE) {

}



// =============================================================================


// Upper-triangluar adjacency matrix graph representation

struct graphRep {
    int   nV;     // #vertices
    int   nE;     // #edges
    bool *edges;  // array of booleans (0 or 1)
};

int indexOf(Graph g, Vertex v, Vertex w)
{
    assert(v != w); // no self-edges
    if (v > w) { Vertex tmp = v; v = w; v = tmp; }

}
