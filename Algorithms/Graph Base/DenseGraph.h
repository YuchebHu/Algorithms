#pragma once

#include <vector>
#include <cassert>
#include <iostream>

// ����ͼ -- �ڽӾ���
class DenseGraph {

private:
	int n; // ���ĸ���
	int m; // �ߵĸ���
	bool directed; // �ǲ�������ͼ
	std::vector<std::vector<bool>> graph; // �ڽӾ���

public:
	/*
		int n : �ڵ�ĸ���
		bool directed : �ǲ�������ͼ
	*/
	DenseGraph(int n, bool directed)
		: n(n), m(0), directed(directed) {
		graph = std::vector<std::vector<bool>>(n, std::vector<bool>(n, false));
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

	void show() const {
		for (int i = 0; i < n; ++i) {
			std::cout << "vertex " << i << ":\t";
			for (int j = 0; j < n; ++j) {
				if (graph[i][j])
					std::cout << j << "\t";
			}
			std::cout << std::endl;
		}
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