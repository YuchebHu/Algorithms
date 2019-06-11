#pragma once

#include <iostream>
#include <cassert>

namespace UF4 {
	//
	class UnionFind {
	private:
		int* parent;
		int* sz;
		int count;

	public:
		UnionFind(int n) : count(n) {
			parent = new int[n];
			sz = new int[n];
			for (int i = 0; i < n; ++i) {
				parent[i] = i;
				sz[i] = 1;
			}
		}

		~UnionFind() {
			delete[] parent;
			delete[] sz;
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

			if (sz[pRoot] > sz[qRoot]) {
				parent[qRoot] = pRoot;
				sz[pRoot] += sz[qRoot];
			}
			else {
				parent[pRoot] = qRoot;
				sz[qRoot] += sz[pRoot];
		};
}