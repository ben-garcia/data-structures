#include <iostream>
#include <set>

#include "DirectedUnweightedGraph.h"
#include "UndirectedWeightedGraph.h"

int main() {
  // directed unweighted graph
  main_savitch_15::DirectedUnweightedGraph<char> g = main_savitch_15::DirectedUnweightedGraph<char>();
  // undirected unweighted graph
  main_savitch_15::UndirectedWeightedGraph<char> wg = main_savitch_15::UndirectedWeightedGraph<char>();

  std::cout << "===============Directed Unweighted Graph============\n";
  g.addVertex('A');
  g.addVertex('B');
  g.addVertex('C');
  g.addVertex('D');
  g.addVertex('E');

  g.addEdge('A', 'B');
  g.addEdge('A', 'C');

  g.addEdge('B', 'A');
  g.addEdge('B', 'C');
  g.addEdge('B', 'E');

  g.addEdge('C', 'A');
  g.addEdge('C', 'B');
  g.addEdge('C', 'D');

  std::cout << "bfs: ";
  g.bfs('A');
  std::cout << std::endl;
  std::cout << "dfs: ";
  g.dfs('A');

  std::cout << "\n===============Undirected Weighted Graph============\n";
  wg.addVertex('A');
  wg.addVertex('B');
  wg.addVertex('C');
  wg.addVertex('D');
  wg.addVertex('E');

  wg.addEdge('A', 'B', 4);
  wg.addEdge('A', 'D', 3);
  wg.addEdge('B', 'C', 2);
  wg.addEdge('C', 'E', 8);
  wg.addEdge('D', 'C', 6);

  std::cout << "bfs: ";
  wg.bfs('A');
  std::cout << std::endl;
  std::cout << "dfs: ";
  wg.dfs('A');
  std::cout << std::endl;
  std::cout << "dijkstra's algorithm from vertex A: \n";
  wg.dijkstra('A');
  std::cout << "====================================================\n";
  return 0;
}