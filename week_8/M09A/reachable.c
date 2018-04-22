#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "Set.h"

#define MAX_V 6

Set reachable(Graph g, Vertex v) {
  Set result = newSet(MAX_V);

  return result;
}

int main(int argc, char* argv[]) {
  Graph g = newGraph(MAX_V);
  addEdge(g,0,1);
  addEdge(g,1,2);
  addEdge(g,2,0);
  addEdge(g,3,4);
  addEdge(g,4,5);
  Set r = reachable(g,0);
  Set r2 = reachable(g,3);
  show(r);
  show(r2);
  killSet(r);
  killSet(r2);
  killGraph(g);
  return EXIT_SUCCESS;
}
