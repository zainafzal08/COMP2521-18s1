#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

void sortedEdgeList(Graph g, Edge edges[]) {
  // write dis
  getEdges(g,edges);
  int nE = numEdges(g);

}

int main(int argc, char* argv[]) {
  Graph g = newGraph(8);
  // 1
  addEdge(g,0,2,2);
  addEdge(g,0,4,1);
  addEdge(g,0,3,4);
  // 2
  addEdge(g,2,5,10);
  // 3
  addEdge(g,3,6,5);
  // 4
  addEdge(g,4,3,2);
  addEdge(g,4,6,8);
  addEdge(g,4,7,4);
  addEdge(g,4,5,7);
  addEdge(g,4,2,3);
  // 5
  addEdge(g,5,7,6);
  // 6
  addEdge(g,6,7,1);

  Edge* edges = malloc(sizeof(Edge)*numEdges(g));
  sortedEdgeList(g,edges);
  int i = 0;
  for(i=0; i<numEdges(g); i++) {
    printf("%d <-[%d]-> %d\n",edges[i].v,edges[i].w,edges[i].t);
  }
  killGraph(g);
}
