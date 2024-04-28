#pragma once
#include "pch.h"
#include "LinkedList.h" 
#include "Stack.h"
#include "Queue.h"


// �����ڿ��� �Ҵ�������
// �Ҹ��ڿ��� ��������
template <typename T>
class SmartPtr
{
public:
    explicit SmartPtr(T* ptr = nullptr)  
    {}

    ~SmartPtr()
    {
        delete _data;  
    }

private:
    T* _data;
};


int main()
{
	{
		int* a = new int(42); 
		SmartPtr<int> b(a);    

	}

	return 0;
}