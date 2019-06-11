#pragma once

#include <iostream>
#include <cassert>

namespace UF5 {
	// 在UF4的基础上修改find函数，添加路径压缩
	class UnionFind {
	private:
		int* parent;
		int* rank;
		int count;

	public:
		UnionFind(int n) : count(n) {
			parent = new int[n];
			rank = new int[n];
			for (int i = 0; i < n; ++i) {
				parent[i] = i;
				rank[i] = 1;
			}
		}

		~UnionFind() {
			delete[] parent;
			delete[] rank;
		}

		int find(int p) {
			assert(p >= 0 && p < count);
			while (p != parent[p]) {
				parent[p] = parent[parent[p]];
				p = parent[p];
			}
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

			if (rank[pRoot] > rank[qRoot])
				parent[qRoot] = pRoot;
			else if (rank[pRoot] < rank[qRoot])
				parent[pRoot] = qRoot;
			else {
				parent[pRoot] = qRoot;
				rank[qRoot] += 1;
			}
		}
	};
}