#pragma once

#include <iostream>
#include <cassert>
#include <vector>

// 计算一个图中有多少个连通分量
template <typename Graph>
class Component {
private:
	Graph& G;
	bool* visited;
	int ccount;

	void dfs(int v) {
		visited[v] = true;

		typename Graph::adjIterator adj(G, v);
		for (int i = adj.begin(); !adj.end(); i = adj.next()) {
			if (!visited[i])
				dfs(i);
		}
	}
public:
	Component(Graph& graph) : G(graph) {
		visited = new bool[G.V()];

		ccount = 0;
		for (int i = 0; i < G.V(); ++i)
			visited[i] = false;

		for (int i = 0; i < G.V(); ++i)
			if (!visited[i]) {
				dfs(i);
				++ccount;
			}
	}

	~Component() {
		delete[] visited;
	}

	int count() {
		return ccount;
	}
};