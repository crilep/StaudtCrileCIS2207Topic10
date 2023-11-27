#pragma once
#include "GraphInterface.h"
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

template<class LabelType>
class MatrixGraph : public GraphInterface<LabelType> {
private:
    std::vector<bool> visited;
    std::vector<int> distance;
    std::vector<LabelType> vertices;
    std::vector<std::vector<int>> adjMatrix;
    int numEdges;
    int size;

public:
    // Constructors
    MatrixGraph();
    MatrixGraph(int num);

    // Getters and setters
    int getNumVertices() const override;
    int getNumEdges() const override;
    int getEdgeWeight(LabelType start, LabelType end) const override;

    // Matrix functions
    bool add(LabelType start, LabelType end, int edgeWeight);
    bool remove(LabelType start, LabelType end) override;

    // Traversals and display
    void depthFirstTraversal(LabelType start, void visit(LabelType&)) override;
    void breadthFirstTraversal(LabelType start, void visit(LabelType&)) override;
    void printMatrix() const;
};