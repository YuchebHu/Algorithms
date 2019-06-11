#pragma once

#include <iostream>
#include <ctime>
#include "UnionFind1.h"
#include "UnionFind2.h"

namespace UnionFindTestHelper {

	void testUF1(int n) {
		srand(time(NULL));

		UF1::UnionFind uf = UF1::UnionFind(n);

		time_t start = clock();
		for (int i = 0; i < n; ++i) {
			int a = rand() % n;
			int b = rand() % n;
			uf.unionElement(a, b);
		}

		for (int i = 0; i < n; ++i) {
			int a = rand() % n;
			int b = rand() % n;
			uf.isConnected(a, b);
		}

		time_t end = clock();

		std::cout << "UF1, " << 2 * n << " ops, " << double(end - start) / CLOCKS_PER_SEC << " s\n";
	}

	void testUF2(int n) {
		srand(time(NULL));

		UF2::UnionFind uf = UF2::UnionFind(n);

		time_t start = clock();
		for (int i = 0; i < n; ++i) {
			int a = rand() % n;
			int b = rand() % n;
			uf.unionElement(a, b);
		}

		for (int i = 0; i < n; ++i) {
			int a = rand() % n;
			int b = rand() % n;
			uf.isConnected(a, b);
		}

		time_t end = clock();

		std::cout << "UF2, " << 2 * n << " ops, " << double(end - start) / CLOCKS_PER_SEC << " s\n";
	}
}