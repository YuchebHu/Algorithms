#pragma once

#include <iostream>
#include <vector>
#include <cassert>

namespace UF1 {
	// quick find
	class UnionFind {
	private:
		//std::vector<int> id;
		int* id;
		int count;

	public:
		UnionFind(int n) : count(n){
			id = new int[n];
			for (int i = 0; i < n; ++i)
				id[i] = i;
		}

		~UnionFind() {
			delete[] id;
		}

		int find(int p) {
			assert(p >= 0 && p < count);
			return id[p];
		}

		bool isConnected(int p, int q) {
			return find(p) == find(q);
		}

		void unionElement(int p, int q) {
			int pID = find(p);
			int qID = find(q);

			if (qID == pID)
				return;

			for (int i = 0; i < count; ++i) {
				if (id[i] == pID)
					id[i] = qID;
			}

		}
	};
}