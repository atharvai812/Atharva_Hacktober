#define MAX_VERTICES 100

int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];

int main() {
  int num_vertices, num_edges;

  // Read in the number of vertices and edges
  scanf("%d %d", &num_vertices, &num_edges);

  // Initialize the adjacency matrix
  for (int i = 0; i < num_vertices; i++) {
    for (int j = 0; j < num_vertices; j++) {
      adjacency_matrix[i][j] = 0;
    }
  }
 // Read in the edges
  for (int i = 0; i < num_edges; i++) {
    int from, to;
    scanf("%d %d", &from, &to);
    adjacency_matrix[from][to] = 1;
  }

  // Print out the adjacency matrix
  for (int i = 0; i < num_vertices; i++) {
    for (int j = 0; j < num_vertices; j++) {
      printf("%d ", adjacency_matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}
//Output
4 4
0 1
1 2
2 3
3 0

0 1 0 1
0 0 1 0
0 0 0 1
1 0 0 0


  0  1  2  3
---------
0| 0  1  0  1
1| 0  0  1  0
2| 0  0  0  1
3| 1  0  0  0
