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
    std::unordered_map<LabelType, int> labelToIndex;
    std::vector<LabelType> indexToLabel;
    std::vector<std::vector<int>> adjMatrix;
    int numEdges;
    int size;

    int getOrCreateIndex(const LabelType& label);

public:
    MatrixGraph();
    MatrixGraph(int num);

    int getNumVertices() const override;

    int getNumEdges() const override;

    bool add(LabelType start, LabelType end, int edgeWeight);

    bool remove(LabelType start, LabelType end) override;

    int getEdgeWeight(LabelType start, LabelType end) const override;
    void depthFirstTraversal(LabelType start, void visit(LabelType&)) override;
    void breadthFirstTraversal(LabelType start, void visit(LabelType&)) override;

    void printMatrix() const;
};