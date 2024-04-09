#pragma once
#include "pch.h"
#include "LinkedList.h" 
#include "Stack.h"


int main()
{
	Stack<int> test;

	test.push(1);
	test.push(2);
	test.push(3);
	test.push(4);

	test.print();
	
	test.pop();
	std::cout << "TOP: " << test.top() << std::endl;

	return 0;
}