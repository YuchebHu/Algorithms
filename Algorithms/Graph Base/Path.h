#pragma once

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>

template <typename Graph>
class Path {
private:
	Graph& G;
	int s;
	bool* visited;
	int* from;

	void dfs(int v) {
		visited[v] = true;

		typename Graph::adjIterator adj(G, v);
		for (int i = adj.begin(); !adj.end(); i = adj.next()) {
			if (!visited[i]) {
				from[i] = v;
				dfs(i);
			}
		}
	}

public:
	Path(Graph& graph, int s) : G(graph) {

		// 初始化算法
		assert(s >= 0 && s < G.V());

		visited = new bool[graph.V()];
		from = new int[graph.V()];

		for (int i = 0; i < graph.V(); ++i) {
			visited[i] = false;
			from[i] = -1;
		}

		this->s = s;

		dfs(s);
	}

	~Path() {
		delete[] visited;
		delete[] from;
	}

	bool hasPath(int w) {
		assert(w >= 0 && w < G.V());
		return visited[w];
	}

	void path(int w, std::vector<int>& vec) {
		std::stack<int> s;
		int p = w;
		while (p != -1) {
			s.push(p);
			p = from[p];
		}

		vec.clear();
		while (!s.empty()) {
			vec.push_back(s.top());
			s.pop();
		}
	}

	void showPath(int w) {
		std::vector<int> vec;
		path(w, vec);
		for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); ++i) {
			std::cout << *i;
			if (i == --vec.end())
				std::cout << std::endl;
			else
				std::cout << " -> ";
		}
	}


};