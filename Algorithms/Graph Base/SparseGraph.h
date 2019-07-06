#pragma once

#include <iostream>
#include <vector>
#include <cassert>
#include <set>

// ϡ��ͼ -- �ڽӱ�
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

		for (int i = 0; i < graph[v].size(); ++i) {
			if (graph[v][i] == w)
				return true;
		}
		return false;
	}

	class adjIterator {
	private:
		SparseGraph& G;
		int v;
		int index;
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