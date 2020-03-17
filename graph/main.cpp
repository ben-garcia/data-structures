#include <iostream>

#include "Graph.h"

int main() {
  main_savitch_15::Graph<char> g = main_savitch_15::Graph<char>();

  g.addVertex('A');
  g.addVertex('B');
  g.addVertex('C');
  g.addVertex('D');
  g.addVertex('E');
  g.addVertex('F');

  g.addEdge('A', 'B');
  g.addEdge('A', 'C');

  g.addEdge('B', 'C');
  g.addEdge('B', 'D');
  g.addEdge('B', 'F');

  g.addEdge('C', 'A');
  g.addEdge('C', 'B');
  g.addEdge('C', 'D');
  g.addEdge('C', 'E');

  g.addEdge('D', 'B');
  g.addEdge('D', 'C');
  g.addEdge('D', 'E');
  g.addEdge('D', 'F');

  g.addEdge('E', 'C');
  g.addEdge('E', 'D');
  g.addEdge('E', 'F');

  g.addEdge('F', 'D');
  g.addEdge('F', 'E');

  return 0;
}