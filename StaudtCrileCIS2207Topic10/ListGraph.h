#pragma once
#include "GraphInterface.h"
#include <list>
#include <unordered_map>
#include <vector>



template<class LabelType>
class ListGraph : public GraphInterface<LabelType> {
private:
    std::unordered_map<LabelType, std::list<LabelType>> adjacencyLists;
    int numVertices;
    int numEdges;

public:
    ListGraph();
    int getNumVertices() const override;
    int getNumEdges() const override;
    bool add(LabelType start, LabelType end, int edgeWeight) override;
    bool remove(LabelType start, LabelType end) override;
    int getEdgeWeight(LabelType start, LabelType end) const override;
    void depthFirstTraversal(LabelType start, void visit(LabelType&)) override;
    void breadthFirstTraversal(LabelType start, void visit(LabelType&)) override;
    
};
