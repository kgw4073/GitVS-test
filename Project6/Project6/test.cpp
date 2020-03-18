#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
// Binary Search Tree Deletion & Insertion
struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* insertNode(Node* root, int data) {
	if (!root) {
		root = new Node;
		root->left = root->right = nullptr;
		root->data = data;
		return root;
	}
	else {
		if (root->data > data) {

			root->left = insertNode(root->left, data);
		}
		else {
			root->right = insertNode(root->right, data);
		}
	}
	return root;
}
Node* searchNode(Node* root, int data) {
	if (!root) return nullptr;
	if (root->data == data) return root;
	else if (root->data > data) return searchNode(root->left, data);
	else return searchNode(root->right, data);
}

Node* findMinNode(Node* root) {
	Node* node = root;
	while (node->left) {
		node = node->left;
	}
	return node;
}

Node* deleteNode(Node* root, int data) {
	Node* node = nullptr;
	if (!root) return nullptr;
	if (root->data > data) root->left = deleteNode(root->left, data);
	else if (root->data < data) root->right = deleteNode(root->right, data);
	else {
		if (root->left && root->right) {
			node = findMinNode(root->right);
			root->data = node->data;
			root->right = deleteNode(root->right, node->data);
		}
		else {
			node = (root->left != nullptr) ? root->left : root->right;
			free(root);
			return node;
		}
	}
	return root;
}
void preorder(Node* root) {
	if (root) {
		printf("%d   ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
int main() {
	Node* root = nullptr;
	root = insertNode(root, 30);
	root = insertNode(root, 17);
	root = insertNode(root, 48);
	root = insertNode(root, 5);
	root = insertNode(root, 23);
	root = insertNode(root, 37);
	root = insertNode(root, 50);
	root = deleteNode(root, 30);
	root = deleteNode(root, 48);
	preorder(root);
	printf("hi");
}