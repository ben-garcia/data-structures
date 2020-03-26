#ifndef MAIN_SAVITCH_UNDIRECTED_WEIGHTED_GRAPH_H
#define MAIN_SAVITCH_UNDIRECTED_WEIGHTED_GRAPH_H

#include <cstdlib>       // Provides size_t
#include <forward_list>  // Provides list
#include <set>           // Provides set
#include <utility>       // Provides pair
#include <vector>        // Provides vector

namespace main_savitch_15 {
template <class Item>
class UndirectedWeightedGraph {
 public:
  // MEMBER CONSTANTS
  static const std::size_t MAXIMUM = 20;

  // CONSTRUCTOR
  UndirectedWeightedGraph() {
    manyVertices = 0;
    labels.reserve(MAXIMUM);
  }

  // MODIFICATION MEMBER FUNCTIONS
  void addVertex(const Item& label);
  void addEdge(const Item& source, const Item& target, int weight);
  void removeEdge(const Item& source, const Item& target);

  // CONSTANT MEMBER FUNCTIONS
  std::size_t size() const { return manyVertices; }
  bool isEdge(const Item& source, const Item& target) const;
  std::set<std::pair<Item, int>> neighbors(const Item& vertex) const;
  void dfs(const Item& source);
  void bfs(const Item& source);
  void dijkstra(const Item& source);

 private:
  std::forward_list<std::pair<Item, int>> adjacencyList[MAXIMUM];
  std::vector<Item> labels;
  std::size_t manyVertices;

  void recDfs(const Item& source, bool visited[]);
};
}  // namespace main_savitch_15

#include "UndirectedWeightedGraph.template"  // Include the implementation.
#endif