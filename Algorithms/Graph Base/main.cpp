#include <iostream>
#include <ctime>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"

//int main() {
//	int N = 20;
//	int M = 100;
//
//	srand(time(NULL));
//
//	SparseGraph graph1(N, false);
//
//	for (int i = 0; i < M; ++i) {
//		int a = rand() % N;
//		int b = rand() % N;
//		graph1.addEdge(a, b);
//	}
//
//	for (int v = 0; v < N; ++v) {
//		std::cout << v << " : ";
//		SparseGraph::adjIterator adj(graph1, v);
//		for (int w = adj.begin(); !adj.end(); w = adj.next())
//			std::cout << w << " ";
//		std::cout << std::endl;
//	}
//	std::cout << std::endl;
//	
//
//	DenseGraph graph2(N, false);
//
//	for (int i = 0; i < M; ++i) {
//		int a = rand() % N;
//		int b = rand() % N;
//		graph2.addEdge(a, b);
//	}
//
//	for (int v = 0; v < N; ++v) {
//		std::cout << v << " : ";
//		DenseGraph::adjIterator adj(graph2, v);
//		for (int w = adj.begin(); !adj.end(); w = adj.next())
//			std::cout << w << " ";
//		std::cout << std::endl;
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

int main() {
	std::string filename = "C:\\Users\\yucheb\\source\\repos\\Algorithms\\Algorithms\\Graph Base\\textG1.txt";

	std::cout << "SparseGraph\n";
	SparseGraph G1(13, false);
	ReadGraph<SparseGraph> readGraph1(G1, filename);
	G1.show();

	std::cout << "\n\nDenseGraph\n";
	DenseGraph G2(13, false);
	ReadGraph<DenseGraph> readGraph2(G2, filename);
	G2.show();
}