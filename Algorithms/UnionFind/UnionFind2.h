#pragma once

#include <iostream>
#include <vector>
#include <cassert>

namespace UF2 {
	class UnionFind {
	private:
		int* parent;
		//std::vector<int> parent;
		int count;

	public:
		UnionFind(int n) : count(n) {
			parent = new int[n];
			for (int i = 0; i < n; ++i)
				parent[i] = i;
				//parent.push_back(i);
		}

		~UnionFind() {
			delete[] parent;
			//std::vector<int>().swap(parent);
		}

		int find(int p) {
			assert(p >= 0 && p < count);
			while (p != parent[p])
				p = parent[p]; 
			return p;
		}

		bool isConnected(int p, int q) {
			return find(p) == find(q);
		}

		void unionElement(int p, int q) {
			int pRoot = find(p);
			int qRoot = find(q);

			if (pRoot == qRoot)
				return;

			parent[pRoot] = qRoot;
		}
	};
}