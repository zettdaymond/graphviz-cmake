/* anonymize the graph */
BEG_G {
  node_t map[node_t];
  graph_t dup;
  int id = 0;
  char* gtype;
  node_t n;
  edge_t e;
  char* l;

  if ($.directed) gtype = "D";
  else gtype = "U";
  if ($.strict) gtype = gtype + "S";
  dup = graph ($.name, gtype);
  $tvtype = TV_ne;
}

N {
  n = node(dup, (char*)id);
  n.label=$.name;
  map[$] = n; 
  id++;
}

E {
  edge (map[$.tail],map[$.head],"");
}

END_G {
  write (dup);
  delete (dup,dup);
}
