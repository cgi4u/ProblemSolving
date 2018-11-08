#include <iostream>
#include <algorithm>

using namespace std;

class Custom_heap {
protected:
	int	nodes[1000];
	int last;
public:
	Custom_heap() { last = 0; }
	
	void push(int n) {
		nodes[last] = n;

		int child = last;
		int parent = (child - 1) / 2;
		while (parent >= 0 && child - 1 >= 0) {
			if (nodes[child] > nodes[parent]) {
				int temp = nodes[child];
				nodes[child] = nodes[parent];
				nodes[parent] = temp;

				child = parent;
				parent = (child - 1) / 2;
			}
			else
				break;
		}

		last += 1;

	}

	int pop() {
		if (last == 0) return -1;
		int ret = nodes[0];

		//이 부분 몰랐음(맨 마지막 노드를 처음으로 돌림)
		nodes[0] = nodes[--last];
		int parent = 0;
		int left = 2 * parent + 1;
		int right = 2 * parent + 2;
		while (left < last) {
			int temp;
			
			if (right < last && nodes[parent] < nodes[right] && nodes[left] < nodes[right]) {
				temp = nodes[right];
				nodes[right] = nodes[parent];
				nodes[parent] = temp;

				parent = right;
			}
			else if (nodes[parent] < nodes[left] && nodes[right] <= nodes[left]) {
				temp = nodes[left];
				nodes[left] = nodes[parent];
				nodes[parent] = temp;

				parent = left;
			}
			else break;

			left = 2 * parent + 1;
			right = 2 * parent + 2;
		}

		return ret;
	}
};

int main(void) {
	int N;
	cout << "N: ";
	cin >> N;

	int *nums = new int[N];
	cout << "numbers: ";
	for (int i = 0; i < N; i++)
		cin >> nums[i];


	Custom_heap h;
	for (int i = 0; i < N; i++) {
		h.push(nums[i]);
	}
	for (int i = 0; i < N; i++) {
		cout << h.pop() << " ";
	}

	delete(nums);
	return 0;
}