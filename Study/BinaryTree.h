#pragma once

/*=================================
		 BinaryTree
=================================*/

/*
insert() ����
search() ã��
erase() ����

��ȸ�ϱ�
����, ����, ����
*/


struct Node
{
	int data;
	Node* left;
	Node* right;
};

class BinaryTree
{
public:
	BinaryTree() {}
	~BinaryTree() {}

	void insert(int data);
	bool search(int data);
	void erase(int data);
	void dataPrint(string name = "PREORDER");

private:
	Node* insertRecursive(Node* node, int data);
	bool searchInorder(Node* node, int data);

	void preOrder(Node* node);
	void inOrder(Node* node);
	void postOrder(Node* node);

private:
	Node* _node = nullptr;
};

