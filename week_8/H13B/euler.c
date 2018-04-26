int isEulerPath(Graph g, Edge e[], int nE) {
  if (nE != g->nE) {
    return FALSE;
  }
  int i = 0;
  int j = 0;
  for(i = 0; i < nE-1; i++) {
    if (e[i].w != e[i+1].v)
      return FALSE;
  }
  // classic duplicate test
  for(i = 0; i < nE; i++) {
    for(j = 0; j < nE; j++) {
      if(i == j) continue;
      if(e[i] == e[j]) return FALSE;
    }
  }
  return TRUE;
}
