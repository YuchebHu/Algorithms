#include <iostream>
#include <vector>
#include <fstream>
#include <string>


int main() {
	std::ifstream fs("textG3.txt");
	std::vector<std::pair<std::string, int>> students;
	char input;

	while (!fs.eof()) {
		std::string Key, value;
		input = fs.get();
		while (input != ' ') {
			Key += input;
			input = fs.get();
		}
		input = fs.get();

		while (input != '\n') {
			value += input;
			if (fs.eof())
				break;
			input = fs.get();
		}
		int Value = std::stoi(value, 0, 10);
		students.push_back({ Key, Value });
	}

	std::cout << "students\t\tnumber\n";
	for (auto student : students) {
		std::cout << student.first << "\t\t" << student.second << std::endl;
	}

	std::vector<int>count(6);
	
	for (auto student : students) 
		count[student.second + 1]++;
	
	for (int i = 0; i < 5; ++i)
		count[i + 1] += count[i];
	std::vector<std::pair<std::string, int>> aux(11);
	
	for (auto student : students)
		aux[count[student.second]++] = student;

	for (int i = 0; i < 11; ++i)
		students[i] = aux[i];
	
	std::cout << "After Sort\nstudents\t\tnumber\n";
	for (auto student : students) {
		std::cout << student.first << "\t\t" << student.second << std::endl;
	} 
}