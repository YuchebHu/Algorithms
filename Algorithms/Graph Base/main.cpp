#include <iostream>
#include <ctime>
#include "SparseGraph.h"
#include "DenseGraph.h"

int main() {
	int N = 20;
	int M = 100;

	srand(time(NULL));

	SparseGraph graph1(N, false);

	for (int i = 0; i < M; ++i) {
		int a = rand() % N;
		int b = rand() % N;
		graph1.addEdge(a, b);
	}

	for (int v = 0; v < N; ++v) {
		std::cout << v << " : ";
		SparseGraph::adjIterator adj(graph1, v);
		for (int w = adj.begin(); !adj.end(); w = adj.next())
			std::cout << w << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	

	DenseGraph graph2(N, false);

	for (int i = 0; i < M; ++i) {
		int a = rand() % N;
		int b = rand() % N;
		graph2.addEdge(a, b);
	}

	for (int v = 0; v < N; ++v) {
		std::cout << v << " : ";
		DenseGraph::adjIterator adj(graph2, v);
		for (int w = adj.begin(); !adj.end(); w = adj.next())
			std::cout << w << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;

	return 0;
}