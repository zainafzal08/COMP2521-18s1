#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "Set.h"

#define MAX_V 6

Vertex *getNeighbours(Graph g, Vertex v, int *size) {
  int i = 0;
  int j = 0;
  int result = malloc(sizeof(int)*100);
  for(i=0; i<g->nV; i++) {
    if(g->matrix[v][i]) {
      result[j] = i;
      j++;
    }
  }
  *size = j;
  return result;
}

Set reachable(Graph g, Vertex v) {
  Set result = newSet(MAX_V);
  Queue toVisit = newQueue(MAX_V);
  addToQueue(toVisit,v);
  while (!empty(toVisit)) {
    Vertex curr = leaveQueue(toVisit);
    if (inSet(result, curr))
      continue;
    addToSet(result, curr);
    int size = 0;
    Vertex *neighbours = getNeighbours(g, curr, &size);
    int i = 0;
    for(i=0; i < size; i++) {
      addToQueue(toVisit, neighbours[i]);
    }
  }
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
