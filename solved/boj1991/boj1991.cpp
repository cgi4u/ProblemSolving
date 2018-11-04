#include <iostream>

using namespace std;

class BNode {
protected:
	BNode * left;
	BNode * right;
	char data;
public:
	BNode() {
		data = '\0';
		left = NULL;
		right = NULL;
	}

	BNode(char _data) {
		data = _data;
		left = NULL;
		right = NULL;
	}

	char getData() { return data; }
	BNode *getLeft() { return left; }
	BNode *getRight() { return right; }

	void setData(char _data) { data = _data; }
	void setRight(BNode *_right) { right = _right; }
	void setLeft(BNode *_left) { left = _left; }
};

void Preorder(BNode *cur) {
	if (cur == NULL) return;

	cout << cur->getData();
	Preorder(cur->getLeft());
	Preorder(cur->getRight());
}

void Inorder(BNode *cur) {
	if (cur == NULL) return;

	Inorder(cur->getLeft());
	cout << cur->getData();
	Inorder(cur->getRight());
}

void Postorder(BNode *cur) {
	if (cur == NULL) return;

	Postorder(cur->getLeft());
	Postorder(cur->getRight());
	cout << cur->getData();
}

int main(void) {
	int N;
	cin >> N;

	BNode *nodes[26];
	for (int i = 0; i < N; i++) {
		nodes[i] = new BNode();
	}
	
	for (int i = 0; i < N; i++) {
		char curData, leftData, rightData;
		cin >> curData >> leftData >> rightData;

		nodes[curData - 'A']->setData(curData);
		if (leftData != '.')
			nodes[curData - 'A']->setLeft(nodes[leftData - 'A']);
		if (rightData != '.')
			nodes[curData - 'A']->setRight(nodes[rightData - 'A']);
	}

	Preorder(nodes[0]);
	cout << endl;
	Inorder(nodes[0]);
	cout << endl;
	Postorder(nodes[0]);
	cout << endl;

	for (int i = 0; i < N; i++) {
		delete(nodes[i]);
	}

	return 0;
}

