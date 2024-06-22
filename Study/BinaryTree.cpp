#include "pch.h"
#include "BinaryTree.h"

void BinaryTree::insert(int data)
{
	_node = insertRecursive(_node, data);
}

bool BinaryTree::search(int data)
{
	return searchInorder(_node, data);
}

void BinaryTree::erase(int data)
{

}

void BinaryTree::dataPrint(int order)
{
	switch (order)
	{
		case 0:
			inOrder(_node);
			break;
		case 1:
			preOrder(_node);
			break;
		case 2:
			postOrder(_node);
		break;
		default:
			preOrder(_node);
			break;
	}

}

void BinaryTree::preOrder(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	cout << node->data << endl;
	preOrder(node->left);
	preOrder(node->right);
}


void BinaryTree::inOrder(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	inOrder(node->left);
	cout << node->data << endl;
	inOrder(node->right);
}

void BinaryTree::postOrder(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	postOrder(node->left);
	postOrder(node->right);
	cout << node->data << endl;
}

Node* BinaryTree::insertRecursive(Node* node, int data)
{
	// 루트일 때 비어있으니까 바로 삽입
	if (node == nullptr)
	{
		Node* newNode = new Node();
		newNode->data = data;
		newNode->left = nullptr;
		newNode->right = nullptr;
		
		return newNode;
	}

	// 루트부터 값을 기준으로 좌 우 비교해서 삽입
	if (node->data > data)
	{
		node->left = insertRecursive(node->left, data);
	}
	else
	{
		node->right = insertRecursive(node->right, data);
	}

	return node;
}

bool BinaryTree::searchInorder(Node* node, int data)
{
	if (node == nullptr)
	{
		return false;
	}

	if (searchInorder(node->left, data))
	{
		return true;
	}
	
	if (node->data == data)
	{
		return true;
	}

	if (searchInorder(node->right, data))
	{
		return true;
	}

	return false;
}
