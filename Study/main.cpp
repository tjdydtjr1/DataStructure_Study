#pragma once
#include "pch.h"
#include "LinkedList.h" 
#include "Stack.h"
#include "Queue.h"
#include "CircleQueue.h"
#include "BinaryTree.h"


int main()
{
	BinaryTree a;

	a.insert(5);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	a.insert(7);
	a.insert(6);

	a.dataPrint();


	return 0;
}