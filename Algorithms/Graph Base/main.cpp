#include <iostream>
#include <ctime>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Component.h"
#include "Path.h"
#include "ShortestPath.h"

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

//int main() {
//	// TextG1.txt
//	std::string filename1 = "C:\\Users\\yucheb\\source\\repos\\Algorithms\\Algorithms\\Graph Base\\textG1.txt";
//	SparseGraph G1(13, false);
//	ReadGraph<SparseGraph> readGraph1(G1, filename1);
//	Component<SparseGraph> component1(G1);
//	std::cout << "TextG1.txt, Component Count: " << component1.count() << std::endl;
//	std::cout << std::endl;
//
//	// TextG2.txt
//	std::string filename2 = "C:\\Users\\yucheb\\source\\repos\\Algorithms\\Algorithms\\Graph Base\\textG2.txt";
//	SparseGraph G2(7, false);
//	ReadGraph<SparseGraph> readGraph2(G2, filename2);
//	Component<SparseGraph> component2(G2);
//	std::cout << "TextG2.txt, Component Count: " << component2.count() << std::endl;
//	
//	return 0;
//}

int main() {
	std::string filename = "C:\\Users\\yucheb\\source\\repos\\Algorithms\\Algorithms\\Graph Base\\textG2.txt";
	SparseGraph G1(7, false);
	ReadGraph<SparseGraph> readGraph(G1, filename);
	G1.show();
	std::cout << std::endl;

	Path<SparseGraph> dfs(G1, 0);
	std::cout << "DFS: ";
	dfs.showPath(6);

	ShortestPath<SparseGraph> bfs(G1, 0);
	std::cout << "BFS: ";
	bfs.ShowPath(6);

	return 0;
}