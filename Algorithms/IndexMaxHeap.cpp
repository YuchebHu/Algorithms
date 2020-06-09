#include <iostream>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cassert>
#include <string>

using namespace std;

template <typename Item>
class IndexMaxHeap {
private:
	Item* data;
	int* indexes;
	int* reverse;
	int count;

	void shiftUp(int k) {
		while (k > 1 && data[indexes[k] / 2] < data[indexes[k]]) {
			swap(indexes[k], indexes[k / 2]);
			reverse[indexes[k / 2]] = k / 2;
			reverse[indexes[k]] = k;
			k /= 2;
		}
	}

	void shiftDown(int k) {
		while (2 * k <= count) {
			int j = 2 * k;
			if (j + 1 <= count && data[indexes[j] + 1] > data[indexes[j]])
				++j;
			if (data[indexes[k]] >= data[indexes[j])
				break;
			swap(indexes[k], indexes[j]);
			reverse[indexes[k]] = k;
			reverse[indexes[j]] = j;
			k = j;
		}
	}

public:
	IndexMaxHeap(int capacity) {
		data = new Item[count + 1];
		indexes = new int[count + 1];
		reverse = new int[count + 1];
		for (int i = 0; i < count + 1; ++i) {
			reverse[i] = 0;
		}
		count = 0;
	}

	~MaxHeap() {
		delete[] data;
		delete[] indexes;
		delete[] reverse;
	}

	int size() {
		return count;
	}

	bool isEmpty() {
		return count == 0;
	}

	void insert(int i, Item item) {
		i += 1;
		data[i] = item;
		indexes[count + 1] = i;
		reverse[i] = count + 1;
		++count;
		shiftUp(count);
	}

	Item extractMax() {
		assert(count > 0);
		Item ret = data[indexes[1]];
		swap(indexes[1], indexes[count]);
		reverse[indexes[1]] = 1;
		reverse[indexes[count]] = 0;
		--count;
		shiftDown(1);
		return ret;
	}

	int extractMaxIndex() {
		int ret = indexes[1] - 1;
		swap(indexes[1], indexes[count]);
		reverse[indexes[1]] = 1;
		reverse[indexes[count]] = 0;
		--count;
		shiftDown(1);
		return ret;
	}

	Item getItem(int i) {
		return data[i + 1];
	}

	bool contain(int i) {
		assert(i + 1 >= 1 && i <= count);
		return reverse[i + 1] != 0;
	}

	void change(int i, Item newItem) {
		assert(contain(i));
		i += 1;
		data[i] = newItem;
		/* for (int j = 1; i <= count; ++j) {
			 if (indexes[j] == i) {
				 shiftUp(j);
				 shiftDown(j);
				 return;
			}

		 }*/
		int j = reverse[i];
		shiftUp(j);
		shiftDown(j);
	}
public:
	// ����״��ӡ�����ѽṹ
	void testPrint() {

		// ���ǵ�testPrintֻ�ܴ�ӡ100��Ԫ�����ڵĶѵ���״��Ϣ
		if (size() >= 100) {
			cout << "This print function can only work for less than 100 int";
			return;
		}

		// ���ǵ�testPrintֻ�ܴ���������Ϣ
		if (typeid(Item) != typeid(int)) {
			cout << "This print function can only work for int item";
			return;
		}

		cout << "The max heap size is: " << size() << endl;
		cout << "Data in the max heap: ";
		for (int i = 1; i <= size(); i++) {
			// ���ǵ�testPrintҪ����е�����������[0, 100)�ķ�Χ��
			assert(data[i] >= 0 && data[i] < 100);
			cout << data[i] << " ";
		}
		cout << endl;
		cout << endl;

		int n = size();
		int max_level = 0;
		int number_per_level = 1;
		while (n > 0) {
			max_level += 1;
			n -= number_per_level;
			number_per_level *= 2;
		}

		int max_level_number = int(pow(2, max_level - 1));
		int cur_tree_max_level_number = max_level_number;
		int index = 1;
		for (int level = 0; level < max_level; level++) {
			string line1 = string(max_level_number * 3 - 1, ' ');

			int cur_level_number = min(count - int(pow(2, level)) + 1, int(pow(2, level)));
			bool isLeft = true;
			for (int index_cur_level = 0; index_cur_level < cur_level_number; index++, index_cur_level++) {
				putNumberInLine(data[index], line1, index_cur_level, cur_tree_max_level_number * 3 - 1, isLeft);
				isLeft = !isLeft;
			}
			cout << line1 << endl;

			if (level == max_level - 1)
				break;

			string line2 = string(max_level_number * 3 - 1, ' ');
			for (int index_cur_level = 0; index_cur_level < cur_level_number; index_cur_level++)
				putBranchInLine(line2, index_cur_level, cur_tree_max_level_number * 3 - 1);
			cout << line2 << endl;

			cur_tree_max_level_number /= 2;
		}
	}

private:
	void putNumberInLine(int num, string& line, int index_cur_level, int cur_tree_width, bool isLeft) {

		int sub_tree_width = (cur_tree_width - 1) / 2;
		int offset = index_cur_level * (cur_tree_width + 1) + sub_tree_width;
		assert(offset + 1 < line.size());
		if (num >= 10) {
			line[offset + 0] = '0' + num / 10;
			line[offset + 1] = '0' + num % 10;
		}
		else {
			if (isLeft)
				line[offset + 0] = '0' + num;
			else
				line[offset + 1] = '0' + num;
		}
	}

	void putBranchInLine(string& line, int index_cur_level, int cur_tree_width) {

		int sub_tree_width = (cur_tree_width - 1) / 2;
		int sub_sub_tree_width = (sub_tree_width - 1) / 2;
		int offset_left = index_cur_level * (cur_tree_width + 1) + sub_sub_tree_width;
		assert(offset_left + 1 < line.size());
		int offset_right = index_cur_level * (cur_tree_width + 1) + sub_tree_width + 1 + sub_sub_tree_width;
		assert(offset_right < line.size());

		line[offset_left + 1] = '/';
		line[offset_right + 0] = '\\';
	}
};


//int main() {
//	MaxHeap<int> maxHeap = MaxHeap<int>(100);
//	//cout << maxHeap.size() << endl;
//	srand(time(NULL));
//	for (int i = 0; i < 50; i++) {
//		maxHeap.insert(rand() % 100);
//	}
//    while (!maxHeap.isEmpty()) {
//        cout << maxHeap.extractMax() << " ";
//    }
//    cout << endl;
//    //maxHeap.testPrint();
//	return 0; 
//}