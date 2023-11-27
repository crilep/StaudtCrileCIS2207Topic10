#include"ListGraph.h"
#include <iostream>
#include<queue>
#include <stack>

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

// Removes from the graph
template<class LabelType>
bool ListGraph<LabelType>::remove(LabelType start, LabelType end)  {

    // Find the entry in the map and then find the edge to delete
    auto startIter = adjacencyLists.find(start);
    auto endIter = adjacencyLists.find(end);

    // Check if the item is available to remove
    if (startIter != adjacencyLists.end() && endIter != adjacencyLists.end()) {
        
        // Remove the connection from the starting iterator and then from the end iterator
        startIter->second.remove(end);
        endIter->second.remove(start);
        numEdges--;
        return true;
    }

    return false;
}

// Returns edgeweight, but this is unweighted so return 1
template<class LabelType>
int ListGraph<LabelType>::getEdgeWeight(LabelType start, LabelType end) const {
    return 1;

}

template<class LabelType>
void ListGraph<LabelType>::depthFirstTraversal(LabelType start, void visit(LabelType&)) {
    // Mark all the vertices as not visited
    std::vector<bool> visited;
    visited.resize(adjacencyLists.size(), false);

    // Create a stack for DFS
    std::stack<LabelType> stack;

    // Start by pushing the start vertex onto the stack
    stack.push(start);

    while (!stack.empty()) {
        // Pop a vertex from stack
        LabelType current = stack.top();
        stack.pop();

        // If the popped vertex has not been visited, visit it
        if (!visited[current]) {
            visited[current] = true;
            visit(current);

            // Push all adjacent vertices of the visited vertex onto the stack
            for (const auto& adjacent : adjacencyLists[current]) {
                if (!visited[adjacent]) {
                    stack.push(adjacent);
                }
            }
        }
    }
}


template<class LabelType>
void ListGraph<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&)) {
    // Mark all the vertices as not visited
    std::vector<bool> visited;
    visited.resize(adjacencyLists.size(), false);

    // Create a queue for BFS
    std::queue<LabelType> queue;

    // Mark the starting node as visited and enqueue it
    visited[start] = true;
    queue.push(start);

    while (!queue.empty()) {
        // Dequeue a vertex from queue
        LabelType current = queue.front();
        queue.pop();

        // Visit the dequeued vertex
        visit(current);

        // Get all adjacent vertices of the dequeued vertex
        for (const auto& adjacent : adjacencyLists[current]) {
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                queue.push(adjacent);
            }
        }
    }
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