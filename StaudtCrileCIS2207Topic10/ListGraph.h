#pragma once
#include "GraphInterface.h"
#include <list>
#include <unordered_map>
#include <vector>



template<class LabelType>
class ListGraph : public GraphInterface<LabelType> {
private:
    // Use a map that holds a list of connections for each item
    std::unordered_map<LabelType, std::list<LabelType>> adjacencyLists;
    int numVertices;
    int numEdges;

public:
    // Constructor
    ListGraph();

    // Getters
    int getNumVertices() const override;
    int getNumEdges() const override;
    int getEdgeWeight(LabelType start, LabelType end) const override;
    
    // Graph Functions
    bool remove(LabelType start, LabelType end) override;
    bool add(LabelType start, LabelType end, int edgeWeight) override;

    // Traversals and Display
    void depthFirstTraversal(LabelType start, void visit(LabelType&)) override;
    void breadthFirstTraversal(LabelType start, void visit(LabelType&)) override;
    void printListGraph();
};
