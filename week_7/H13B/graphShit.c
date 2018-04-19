///// Adjacency list graph representation

struct graphRep {
    int nV;       // #vertices
    int nE;       // #edges
    Vertex edges[100];  // array of Vertex lists
};


// (e.v < e.w)
Edge *edges(Graph g, int *nE) {
  int i = 0;
  int j =0;
  Edge *edges = malloc(sizeof(Edge)*g->nE);
  for(i=0; i < g->nV; i++) {
    Vertex curr = graph->edges[i];
    while (curr != NULL) {
        edges[j] = curr->edge;
    }
    curr = curr->next;
  }
  *nE = j;
  return edges;
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
    int i = 0;
    int j = 0;
    int k = 1;
    while(i < v) {
      j += (g->nv-k);
      i++;
      k++;
    }
    return j+w-(i+1);
}
