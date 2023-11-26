#include"ListGraph.h"
#include <iostream>

// Constructor
template<class LabelType>
ListGraph<LabelType>::ListGraph() : numVertices(0), numEdges(0) {

}

// Returns the number of vertices
template<class LabelType>
int ListGraph<LabelType>::getNumVertices() const {
    return numVertices;
}

// Returns the number of edges
template<class LabelType>
int ListGraph<LabelType>::getNumEdges() const {
    return numEdges;
}

// Adds to the graph
template<class LabelType>
bool ListGraph<LabelType>::add(LabelType start, LabelType end, int edgeWeight) {

    // Add the edge from the start node to the end node by adding the the given entry's list of connections
    adjacencyLists[start].push_back(end);

    // For undirected, add the edge from end to start as well
    adjacencyLists[end].push_back(start);

    // Add an edge
    numEdges++;
    return true;
}

template<class LabelType>
bool ListGraph<LabelType>::remove(LabelType start, LabelType end)  {

    // Find the entry in the map and then find the edge to delete
    auto startIter = adjacencyLists.find(start);
    auto endIter = adjacencyLists.find(end);

    // Check if the item is available to remove
    if (startIter != adjacencyLists.end() && endIter != adjacencyLists.end()) {
        
        startIter->second.remove(end);
        endIter->second.remove(start);
        --numEdges;
        return true;
    }

    return false;
}

template<class LabelType>
int ListGraph<LabelType>::getEdgeWeight(LabelType start, LabelType end) const {
    // In an unweighted graph, just return 1 if there is an edge, otherwise 0
    const auto& list = adjacencyLists.at(start);
    for (const auto& vertex : list) {
        if (vertex == end) {
            return 1; // Edge exists
        }
    }
    return 0; // No edge found
}

template<class LabelType>
void ListGraph<LabelType>::depthFirstTraversal(LabelType start, void visit(LabelType&)) {
    // Implement DFS using adjacency list
}

template<class LabelType>
void ListGraph<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&)) {
    // Implement BFS using adjacency list
}

template<class LabelType>
void ListGraph<LabelType>::printListGraph() {

    for (const auto& pair : adjacencyLists) {
        std::cout << pair.first << "-> ";
        for (const auto& adjacent : pair.second) {
            std::cout << adjacent << ", ";
        }
        std::cout << std::endl;
    }

}