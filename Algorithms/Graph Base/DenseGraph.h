#pragma once

#include <vector>
#include <cassert>
#include <iostream>

// 稠密图 -- 邻接矩阵
class DenseGraph {

private:
	int n; // 结点的个数
	int m; // 边的个数
	bool directed; // 是不是有向图
	std::vector<std::vector<bool>> graph; // 邻接矩阵

public:
	/*
		int n : 节点的个数
		bool directed : 是不是有向图
	*/
	DenseGraph(int n, bool directed)
		: n(n), m(0), directed(directed) {
		for (int i = 0; i < n; ++i) {
			graph.push_back(std::vector<bool>(n, false));
		}
	}

	~DenseGraph() {}

	int V() { return n; }

	int E() { return m; }

	void addEdge(int v, int w) {
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		if (hasEdge(v, w))
			return;

		graph[v][w] = true;

		if (!directed) {
			graph[w][v] = true;
		}

		++m;
	}

	bool hasEdge(int v, int w) {
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		return graph[v][w];
	}

	class adjIterator {
	private:
		DenseGraph& G;
		int v;
		int index;
	public:
		adjIterator(DenseGraph& graph, int v) : G(graph), v(v), index(-1) {}

		~adjIterator() {}

		int begin() {
			index = -1;
			return next();
		}

		int next() {
			for (index += 1; index < G.V(); ++index)
				if (G.graph[v][index])
					return index;
			return -1;
		}

		bool end() {
			return index >= G.V();
		}
	};
};