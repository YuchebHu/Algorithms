#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void sort(std::vector<std::string>& array, int W);

int main() {
	std::ifstream fs("textG4.txt");
	std::vector<std::string> array;
	
	while (!fs.eof()) {
		std::string temp;
		while (fs.peek() != '\n' && !fs.eof())
			temp += fs.get();
		fs.get();
		array.push_back(temp);
	}

	for (auto line : array)
		std::cout << line << std::endl;

	sort(array, 7);
	std::cout << "After Sorting: \n";

	for (auto line : array)
		std::cout << line << std::endl;
}


void sort(std::vector<std::string>& array, int W) {
	int R = 256;
	int N = array.size();
	std::vector<std::string>temp(N);

	for (int d = W - 1; d >= 0; --d) {
		std::vector<int>count(R + 1);

		for (int i = 0; i < N; ++i)
			count[array[i][d] + 1]++;

		for (int i = 0; i < R; ++i)
			count[i + 1] += count[i];
		
		for (int i = 0; i < N; ++i)
			temp[count[int(array[i][d])]++] = array[i];

		for (int i = 0; i < N; ++i)
			array[i] = temp[i];
		
	}
}
