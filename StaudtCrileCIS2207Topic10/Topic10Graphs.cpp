#include"MatrixGraph.cpp"
#include"ListGraph.cpp"
#include<iostream>

using namespace std;

template<class LabelType>
void printNode(LabelType &item) {
	cout << item << " ";
}

int main() {

	MatrixGraph<int> matrixGraph(5);

	matrixGraph.add(0, 4, 1);
	matrixGraph.add(0, 1, 1);
	matrixGraph.add(0, 3, 1);
	matrixGraph.add(1, 2, 1);
	matrixGraph.add(1, 4, 1);
	matrixGraph.add(2, 3, 1);
	matrixGraph.printMatrix();

	cout << "\n\nAfter removing the 0, 1 edge...\n";
	matrixGraph.remove(0, 1);
	matrixGraph.printMatrix();
	cout << "\n\n\n";
	

	ListGraph<int> listGraph;
	listGraph.add(0, 4, 1);
	listGraph.add(0, 1, 1);
	listGraph.add(0, 3, 1);
	listGraph.add(1, 2, 1);
	listGraph.add(1, 4, 1);
	listGraph.add(2, 3, 1);
	listGraph.printListGraph();

	cout << "\n\nAfter removing the 0, 1 edge...\n";
	listGraph.remove(0, 1);
	listGraph.printListGraph();
	cout << "\n\n\n";



}