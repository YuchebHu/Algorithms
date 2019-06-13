#pragma once

#include <iostream>
#include <vector>
#include <cassert>

// ����ͼ - �ڽӾ���
class DenseGraph {
private:
	int numNode; // ����ĸ���
	int numEdge; // �ߵĸ���
	bool isDirected; //�Ƿ�������ͼ
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

