#include"MatrixGraph.h"
#include <iomanip>
#include<iostream>
#include <stack>
#include <vector>

// Display the matrix
template<class LabelType>
void MatrixGraph<LabelType>::printMatrix() const {
    
    const int WIDTH = 2; 
    int size = adjMatrix.size();

    for (int row = 0; row < size; ++row) {
        // Print the row 
        for (int col = 0; col < size; ++col) {
            // Print each cell value
            std::cout << std::setw(WIDTH) << adjMatrix[row][col];
        }
        // New row
        std::cout << '\n';
    }
}

// Constructor
template<class LabelType>
MatrixGraph<LabelType>::MatrixGraph() : numEdges(0) {

}

// Constructor
template<class LabelType>
MatrixGraph<LabelType>::MatrixGraph(int size) : size(size), adjMatrix(size, std::vector<int>(size, 0)) {
  
}

// Traverse using depth first
template<class LabelType>
void MatrixGraph<LabelType>::depthFirstTraversal(LabelType start, void visit(LabelType&)) {
    
    // Check if start is in bounds
    if (start < 0 || start >= size) return; 

    // Create an all false vector
    std::stack<LabelType> stack;
    std::vector<bool> visited(size, false);

    // Set first as visited and push it to the stack
    visited[start] = true;
    stack.push(start);

    // Loop through the matrix using depth first
    while (!stack.empty()) {

        // Set the current to the top of the stack, then pop the vaule and visit it
        LabelType currentVertex = stack.top();
        stack.pop();
        visit(currentVertex);

        // Loop through each unvisited and add them to the stack
        for (int adjacent = 0; adjacent < size; adjacent++) {
            if (adjMatrix[currentVertex][adjacent] && !visited[adjacent]) {
                visited[adjacent] = true;
                stack.push(adjacent);
            }
        }
    }
}

// Traverse using breadth first
template<class LabelType>
void MatrixGraph<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&)) {
    
    // Check if start is in bounds
    if (start < 0 || start >= size) return;

    // Start with a vector of all visited being false
    std::vector<bool> visited(size, false);
    std::queue<LabelType> q;

    // Enqueue the start and mark as visited
    q.push(start);
    visited[start] = true;

    // Loop until all are visited
    while (!q.empty()) {
       
        // Set the current and dequeue it, then visit
        LabelType current = q.front();
        q.pop();
        visit(current); 

        // Loop all unvisited
        for (int i = 0; i < size; ++i) {
            if (adjMatrix[current][i] != 0 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

// Returns the number of vertices
template<class LabelType>
int MatrixGraph<LabelType>::getNumVertices() const {
    return vertices.size();
}

// Returns the number of edges
template<class LabelType>
int MatrixGraph<LabelType>::getNumEdges() const  {
    return numEdges;
}

// Add to the matrix
template<class LabelType>
bool MatrixGraph<LabelType>::add(LabelType start, LabelType end, int edgeWeight) {

    // Check if both start and end are in bounds
    if (start >= 0 && start < size && end >= 0 && end < size) {
        // Add to the matrix with a 1 for connected
        adjMatrix[start][end] = 1; 
        adjMatrix[end][start] = 1; 
        return true;
    }
    return false; 
}

// Removes from the matrix
template<class LabelType>
bool MatrixGraph<LabelType>::remove(LabelType start, LabelType end) {

    // Check if both start and end are in bounds
    if (start >= 0 && start < size && end >= 0 && end < size) {

        // Check if there is an edge to remove
        if (adjMatrix[start][end] == 1) {
            // Remove the edge both ways
            adjMatrix[start][end] = 0; 
            adjMatrix[end][start] = 0; 
            return true;
        }
    }
    return false;
}

// Return the edgeweight of 1, because this is unweighted
template<class LabelType>
int MatrixGraph<LabelType>::getEdgeWeight(LabelType start, LabelType end) const {
    return 1;
}