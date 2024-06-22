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

#define IN_ORDER   0
#define PRE_ORDER  1
#define POST_ORDER 2

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
	void dataPrint(int order = IN_ORDER);

private:
	Node* insertRecursive(Node* node, int data);
	bool searchInorder(Node* node, int data);

	void preOrder(Node* node);
	void inOrder(Node* node);
	void postOrder(Node* node);

private:
	Node* _node = nullptr;
};

