#include"MatrixGraph.h"
#include <iomanip>
#include<iostream>
#include <stack>
#include <vector>

template<class LabelType>
void MatrixGraph<LabelType>::printMatrix() const {
    const int width = 2; // Adjust width as needed

    // Assuming your matrix is square and uses a vector of vectors.
    int size = adjMatrix.size();

    // Print the column headers
    std::cout << std::setw(width) << " ";
    for (int col = 0; col < size; ++col) {
        std::cout << std::setw(width) << col;
    }
    std::cout << '\n';

    for (int row = 0; row < size; ++row) {
        // Print the row header
        std::cout << std::setw(width) << row;
        for (int col = 0; col < size; ++col) {
            // Print each cell value
            std::cout << std::setw(width) << adjMatrix[row][col];
        }
        std::cout << '\n';
    }
}


template<class LabelType>
MatrixGraph<LabelType>::MatrixGraph() : numEdges(0) {

}

template<class LabelType>
MatrixGraph<LabelType>::MatrixGraph(int size) : size(size), adjMatrix(size, std::vector<int>(size, 0)) {
    // The adjacency matrix is now a size x size matrix filled with zeros.
}


template<class LabelType>
void MatrixGraph<LabelType>::depthFirstTraversal(LabelType start, void visit(LabelType&)) {
    if (start < 0 || start >= size) return; // Start vertex must be within bounds.

    std::stack<LabelType> stack;
    std::vector<bool> visited(size, false);

    visited[start] = true;
    stack.push(start);

    while (!stack.empty()) {
        LabelType currentVertex = stack.top();
        stack.pop();
        visit(currentVertex);

        for (int adjacent = 0; adjacent < size; ++adjacent) {
            if (adjMatrix[currentVertex][adjacent] && !visited[adjacent]) {
                visited[adjacent] = true;
                stack.push(adjacent);
            }
        }
    }
}

template<class LabelType>
void MatrixGraph<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&)) {
    // Resetting visited and distance vectors
    visited.assign(getNumVertices(), false);
    distance.assign(getNumVertices(), 0);

    // Getting the index of the start node
    int startIdx = labelToIndex[start];

    std::queue<int> q;
    q.push(startIdx);
    visited[startIdx] = true;
    distance[startIdx] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        LabelType currLabel = indexToLabel[curr];
        visit(currLabel); // Calling the visit function on the current node

        for (int i = 0; i < getNumVertices(); ++i) {
            if (adjMatrix[curr][i] != 0 && !visited[i]) { // Checking for an edge and if the node is not visited
                q.push(i);
                distance[i] = distance[curr] + 1;
                visited[i] = true;

                LabelType childLabel = indexToLabel[i];
                std::cout << "node: " << currLabel << " child: " << childLabel << "\n";
            }
        }
    }
}

template<class LabelType>
int MatrixGraph<LabelType>::getOrCreateIndex(const LabelType& label) {
    auto it = labelToIndex.find(label);
    if (it == labelToIndex.end()) {
        int index = indexToLabel.size();
            indexToLabel.push_back(label);
            labelToIndex[label] = index;
            for (auto& row : adjMatrix) {
                row.push_back(0);
            }
            adjMatrix.push_back(std::vector<int>(indexToLabel.size(), 0));
            return index;
        }
        return it->second;
    }

template<class LabelType>
int MatrixGraph<LabelType>::getNumVertices() const {
    return indexToLabel.size();
}

template<class LabelType>
int MatrixGraph<LabelType>::getNumEdges() const  {
    return numEdges;
}

template<class LabelType>
bool MatrixGraph<LabelType>::add(LabelType start, LabelType end, int edgeWeight) {
    // Check if the indices are within bounds
    if (start >= 0 && start < size && end >= 0 && end < size) {
        adjMatrix[start][end] = 1; // Add edge from start to end
        adjMatrix[end][start] = 1; // Add edge from end to start, for undirected graph
        return true;
    }
    return false; // Return false if the indices are out of bounds
}


template<class LabelType>
bool MatrixGraph<LabelType>::remove(LabelType start, LabelType end) {
    // Check if both start and end indices are within bounds
    if (start >= 0 && start < size && end >= 0 && end < size) {
        // Check if there is an edge to remove
        if (adjMatrix[start][end] == 1) {
            adjMatrix[start][end] = 0; // Remove edge from start to end
            adjMatrix[end][start] = 0; // Remove edge from end to start for undirected graph
            return true;
        }
    }
    return false;
}

template<class LabelType>
int MatrixGraph<LabelType>::getEdgeWeight(LabelType start, LabelType end) const {
    auto itStart = labelToIndex.find(start);
    auto itEnd = labelToIndex.find(end);
    if (itStart != labelToIndex.end() && itEnd != labelToIndex.end()) {
        return adjMatrix[itStart->second][itEnd->second];
    }
    
    return -1;
}