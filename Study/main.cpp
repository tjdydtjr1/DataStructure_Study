#pragma once
#include "pch.h"
#include "LinkedList.h" 

int main()
{
	LinkedList<int> a;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	
	a.print();
	
	
	return 0;
}