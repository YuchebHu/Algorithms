#pragma once

#include <iostream>
#include <vector>
#include <cassert>
#include <set>
// Ï¡ÊèÍ¼ - ÁÚ½Ó±í
class SpareseGraph {
private:
	int numNode;
	int numEdge;
	bool isDirected;
	std::vector<std::vector<int>> graph;
  
public:
	SpareseGraph(int n, bool directed)
		: numNode(n), numEdge(0), isDirected(directed) {
		for (int i = 0; i < n; ++i)
			graph.push_back(std::vector<int>());
	}

	~SpareseGraph() {}

	int V() { return numNode; }

	int E() { return numEdge; }

	void addEdge(int v, int w) {
		assert(v >= 0 && v < numNode);
		assert(w >= 0 && w < numEdge);

		graph[v].push_back(w);
		if (!isDirected)
			graph[w].push_back(v);

		++numEdge;
	}

	bool hasEdge(int v, int w) { // O(n)
		assert(v >= 0 && v < numNode);
		assert(w >= 0 && w < numEdge);
		
		for (int i : graph[v]) {
			if (i == w)
				return true;
		}
		return false;
	}
};