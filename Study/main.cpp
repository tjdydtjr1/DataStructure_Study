#pragma once
#include "pch.h"
#include "LinkedList.h" 
#include "Stack.h"
#include "Queue.h"



int main()
{
	Queue<int> test;

	test.push(1);
	test.push(2);
	test.push(3);
	test.push(4);
	test.push(5);

	for (int i = 0; i < 5; ++i)
	{
		cout << *test.front() << endl;
	}

	cout << test.size() << endl;

	return 0;
}