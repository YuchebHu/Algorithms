#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

template <typename Graph>
class ReadGraph {
public:
	ReadGraph(Graph& graph, const std::string& filename) {
		std::ifstream file(filename);
		std::string line;
		int V;
		int E;
		
		assert(file.is_open());
		assert(getline(file, line));
	
		std::stringstream ss(line);
		ss >> V >> E;
	
		assert(V == graph.V());

		for (int i = 0; i < E; ++i) {
			assert(getline(file, line));

			std::stringstream ss(line);
			int a;
			int b;
			ss >> a >> b;

			assert(a >= 0 && a < V);
			assert(b >= 0 && b < V);
			graph.addEdge(a, b);
		}
	}
};