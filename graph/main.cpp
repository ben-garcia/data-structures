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

  g.addEdge(0, 1);
  g.addEdge(0, 2);

  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(1, 5);

  g.addEdge(2, 0);
  g.addEdge(2, 1);
  g.addEdge(2, 3);
  g.addEdge(2, 4);

  g.addEdge(3, 1);
  g.addEdge(3, 2);
  g.addEdge(3, 4);
  g.addEdge(3, 5);

  g.addEdge(4, 2);
  g.addEdge(4, 3);
  g.addEdge(4, 5);

  g.addEdge(5, 3);
  g.addEdge(5, 4);

  std::cout << "--------------------bfs----------------\n";
  main_savitch_15::breadth_first([](std::size_t i) { std::cout << (char)i << " "; }, g, 0);
  std::cout << std::endl;
  std::cout << "--------------------dfs----------------\n";
  main_savitch_15::depth_first([](std::size_t i) { std::cout << (char)i << " "; }, g, 0);

  return 0;
}