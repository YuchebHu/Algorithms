#pragma once

#include <iostream>
#include <stack>
#include <queue>
#include <cassert>
#include <vector>

template <typename Graph>
class ShortestPath {
private:
	Graph& G;
	int s;
	bool* visited;
	int* from;
	int* ord;

public:
	ShortestPath(Graph& graph, int s) : G(graph) {
		
		// 初始化算法
		assert(s >= 0 && s < G.V());

		visited = new bool[G.V()];
		from = new int[G.V()];
		ord = new int[G.V()];

		for (int i = 0; i < G.V(); ++i) {
			visited[i] = false;
			from[i] = -1;
			ord[i] = -1;
		}

		this->s = s;

		std::queue<int> q;

		// 无向图最短路径算法, 从s开始广度优先遍历整张图
		q.push(s);
		visited[s] = true;
		ord[s] = 0;

		while (!q.empty()) {
			int v = q.front();
			q.pop();

			typename Graph::adjIterator adj(G, v);
			for (int i = adj.begin(); !adj.end(); i = adj.next()) {
				if (!visited[i]) {
					q.push(i);
					visited[i] = true;
					from[i] = v;
					ord[i] = ord[v] + 1;
				}
				
			}
		}
	}

	~ShortestPath() {
		delete[] visited;
		delete[] from;
		delete[] ord;
	}

	bool hasPath(int w) {
		assert(w >= 0 && w < G.V());
		return visited[w];
	}

	void path(int w, std::vector<int>& vec) {
		assert(w >= 0 && w < G.V());

		std::stack<int> stack;

		int p = w;
		while (p != -1) {
			stack.push(p);
			p = from[p];
		}
		
		vec.clear();
		while (!stack.empty()) {
			vec.push_back(stack.top());
			stack.pop();
		}
	}

	void ShowPath(int w) {
		std::vector<int> vec;
		path(w, vec);

		for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); ++i) {
			std::cout << *i;
			if (i != --vec.end())
				std::cout << " -> ";
			else
				std::cout << std::endl;
		}
	}

	int length(int w) {
		assert(w >= 0 && w < G.V());
		return ord[w];
	}
};