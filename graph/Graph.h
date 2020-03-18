/**
 * FILE: Graph.h (part of the namespace main_savitch_15)
 * TEMPLATE CLASS PROVIDED: Graph<Item> (a class for labeled graphs)
 *  The vertices of an n-vertex graph are numbered from 0  to n - 1. Each vertex has a
 *  label of type Item. It may be any of the C++ built-in types (int, char, etc.), or any
 *  class with a default constructor and an assignment operator. The graph may not have
 *  multiple edges.
 * 
 * MEMBER CONSTANTS for the Graph<Item> template class:
 *  static const size_t MAXIMUM = ______
 *    Graph::MAXIMUM is the maximum number of vertices that a graph can have.
 * 
 * CONSTRUCTOR for the Graph<Item> template class:
 *   Graph()
 *    Postcondition: The graph has been initialized with no vertices and no edges.
 * 
 * MODIFICATION MEMBER FUNCTIONS for the Graph<Item> template class:
 *   void addVertex(const Item& label)
 *    Precondition: size() < MAXIMUM.
 *    Postcondition: The size of the graph has been increased by adding one new vertex.
 *    This new vertex has the specified label and no edges.
 * 
 *   void addEdge(size_t source, size_t target)
 *    Precondition: (source < size()) and (target < size()).
 *    Postcondition: The graph has all the edges that it originally had, and it also has
 *    another edge from the specified source to the specified target. (If this edge was
 *    already present, then the graph is unchanged.)
 * 
 *   void removeEdge(size_t source, size_t target)
 *    Precondition: (source < size()) and (target < size()).
 *    Postcondition: The graph has all the edges that it originally has except for the edge
 *    from the specified source to the specified target. (If this edge was not originally
 *    present, then the graph is unchanged.)
 * 
 *   Item& operator [] (size_t vertex)
 *    Precondition: vertex < size()
 *    Postcondition: The return value is a reference to the label of the specified vertex.
 * 
 * CONSTANT MEMBER FUNCTIONS for the Graph<Item> template class:
 *  size_t size() const
 *    Postcondition: The return value is the number of vertices in the graph.
 * 
 *  bool isEdge(size_t source, size_t target) const
 *    Precondition: (source < size()) and (target < size()).
 *    Postcodition: The return value is true if the graph has an edge from soure to target.
 *    Otherwise the return value is false.
 * 
 *  set<size_t> neighbors(size_t vertex) const
 *    Precondition: (vertex < size()).
 *    Postcondition: The return value is a set that contains all the vertex numbers of
 *    vertices that are the target of an edge whose source is at the specified vertex.
 * 
 *  Item operator [] (size_t vertex) const
 *    Precondition: vertex < size().
 *    Postcondition: The return value is a reference to the label of the specified vertex.
 *    NOTE: This function differs from the other operator [] because its return value is
 *    simply a copy of the item (rather than a reference of type Item&). Since this function
 *    returns only a copy of the Item, it is a const member function.
 * 
 * VALUE SEMANTICS for the Graph<Item> template class:
 *   Assignments and the copy constructor may be used with Graph<Item> objects.
 */

#ifndef MAIN_SAVITCH_GRAPH_H
#define MAIN_SAVITCH_GRAPH_H

#include <cstdlib>  // Provides size_t
#include <set>      // Provides set
#include <vector>

namespace main_savitch_15 {
template <class Item>
class Graph {
 public:
  // MEMBER CONSTANTS
  static const std::size_t MAXIMUM = 20;

  // CONSTRUCTOR
  Graph() {
    manyVertices = 0;
    labels.reserve(MAXIMUM);
  }

  // MODIFICATION MEMBER FUNCTIONS
  void addVertex(const Item& label);
  void addEdge(const Item& source, const Item& target);
  void removeEdge(const Item& source, const Item& target);
  Item& operator[](std::size_t vertex);

  // CONSTANT MEMBER FUNCTIONS
  std::size_t size() const { return manyVertices; }
  bool isEdge(const Item& source, const Item& target) const;
  std::set<Item> neighbors(const Item& vertex) const;
  Item operator[](std::size_t vertex) const;
  void bfs(const Item& source);

 private:
  bool edges[MAXIMUM][MAXIMUM];
  std::vector<Item> labels;
  std::size_t manyVertices;
};
}  // namespace main_savitch_15

#include "Graph.template"  // Include the implementation.
#endif