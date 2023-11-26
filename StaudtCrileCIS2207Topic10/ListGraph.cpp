#include"ListGraph.h"

template<class LabelType>
ListGraph<LabelType>::ListGraph() : numVertices(0), numEdges(0) {

}

template<class LabelType>
int ListGraph<LabelType>::getNumVertices() const {
    return numVertices;
}

template<class LabelType>
int ListGraph<LabelType>::getNumEdges() const {
    return numEdges;
}

template<class LabelType>
bool ListGraph<LabelType>::add(LabelType start, LabelType end, int edgeWeight) {
    // Add the edge from start to end
    adjacencyLists[start].push_back(end);
    // If undirected, add the edge from end to start as well
    adjacencyLists[end].push_back(start);
    ++numEdges;
    return true;
}

template<class LabelType>
bool ListGraph<LabelType>::remove(LabelType start, LabelType end)  {
    auto startIter = adjacencyLists.find(start);
    auto endIter = adjacencyLists.find(end);

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