#pragma once

#include <iostream>
#include <vector>
#include <cassert>
#include <set>

// 稀疏图 -- 邻接表
class SparseGraph {
private:
	int n;
	int m;
	bool directed;
	std::vector<std::vector<int>> graph;

public:
	SparseGraph(int n, bool directed)
		: n(n), m(0), directed(directed) {
		graph = std::vector<std::vector<int>>(n, std::vector<int>());
	}

	~SparseGraph() {}

	int V() { return n; }

	int E() { return m; }

	void addEdge(int v, int w) {
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		/*if (hasEdge(v, w))
			return;*/

		graph[v].push_back(w);

		if (v != w && !directed) {
			graph[w].push_back(v);
		}

		++m;
	}

	bool hasEdge(int v, int w) {
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		for (size_t i = 0; i < graph[v].size(); ++i) {
			if (graph[v][i] == w)
				return true;
		}
		return false;
	}

	void show() const {
		for (int i = 0; i < n; ++i) {
			std::cout << "Vertex " << i << ":\t";
			for (size_t j = 0; j < graph[i].size(); ++j)
				std::cout << graph[i][j] << "\t";
			std::cout << std::endl;
		}
	}

	class adjIterator {
	private:
		SparseGraph& G;
		int v;
		size_t index;
	public:
		adjIterator(SparseGraph& graph, int v) : G(graph), v(v), index(0) {}

		~adjIterator() {}

		int begin() {
			index = 0;
			if (G.graph[v].size())
				return G.graph[v][index];
			return -1;
		}

		int next() {
			++index;
			if (index < G.graph[v].size())
				return G.graph[v][index];
			return -1;
		}

		bool end() {
			return index >= G.graph[v].size();
		}
	};
};