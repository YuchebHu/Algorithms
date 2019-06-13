#pragma once

#include <iostream>
#include <vector>
#include <cassert>

// 稠密图 - 邻接矩阵
class DenseGraph {
private:
	int numNode; // 顶点的个数
	int numEdge; // 边的个数
	bool isDirected; //是否是有向图
	std::vector<std::vector<bool>> graph;
public:
	DenseGraph(int n, bool directed)
		: numNode(n), numEdge(0), isDirected(directed) {
		for (int i = 0; i < n; ++i) {
			graph.push_back(std::vector<bool>(n, false));
		}
	}

	~DenseGraph() {

	}

	int V() { return numNode; }

	int E() { return numEdge; }

	void addEdge(int v, int w) {
		assert(v >= 0 && v < numNode);
		assert(w >= 0 && v < numEdge);
		
		if (hasEdge(v, w))
			return;

		graph[v][w] = true;
		if (!isDirected) {
			graph[w][v] = true;
		}

		++numEdge;
	}

	bool hasEdge(int v, int w) {
		assert(v >= 0 && v < numNode);
		assert(w >= 0 && w < numEdge);
		return graph[v][w];
	}
};

