// Crile Staudt
// CIS 2207 101
// November 26, 2023
// Impliment an ADT graph as an adj. matrix and list.
#include"MatrixGraph.cpp"
#include"ListGraph.cpp"
#include<iostream>

using namespace std;

template<class LabelType>
void printNode(LabelType &item) {
	cout << item << " ";
}

int main() {

	// Add to the matrix graph
	MatrixGraph<int> matrixGraph(5);

	matrixGraph.add(0, 4, 1);
	matrixGraph.add(0, 1, 1);
	matrixGraph.add(0, 3, 1);
	matrixGraph.add(1, 2, 1);
	matrixGraph.add(1, 4, 1);
	matrixGraph.add(2, 3, 1);
	matrixGraph.printMatrix();

	// Remove an edge
	cout << "\n\nAfter removing the 0, 1 edge...\n";
	matrixGraph.remove(0, 1);
	matrixGraph.printMatrix();

	// Add to the list graph
	ListGraph<int> listGraph;
	listGraph.add(0, 4, 1);
	listGraph.add(0, 1, 1);
	listGraph.add(0, 3, 1);
	listGraph.add(1, 2, 1);
	listGraph.add(1, 4, 1);
	listGraph.add(2, 3, 1);
	cout << "\n";
	listGraph.printListGraph();

	// Remove an edge
	cout << "\n\nAfter removing the 0, 1 edge...\n";
	listGraph.remove(0, 1);
	listGraph.printListGraph();

	system("pause");
	return 0;

}