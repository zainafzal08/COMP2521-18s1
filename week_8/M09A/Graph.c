#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>

Graph newGraph(int max){
  Graph g = malloc(sizeof(struct graphRep));
  g->nV = max;
  g->nE = 0;
  g->edges = malloc(sizeof(int*)*max);
  int i = 0;
  for(i=0;i<max;i++)
    g->edges[i] = malloc(sizeof(int)*max);
  return g;
}

void killGraph(Graph g) {
  int i = 0;
  for(i=0;i<g->nV;i++)
    free(g->edges[i]);
  free(g->edges);
  free(g);
}

void addEdge(Graph g, int v, int w) {
  if (!g->edges[v][w]) g->nE++;
  g->edges[v][w] = 1;
  g->edges[w][v] = 1;
}

int hasEdge(Graph g, int v, int w) {
  return g->edges[v][w];
}
