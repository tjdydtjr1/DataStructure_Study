#pragma once

/*
push() ���ÿ� �״´�.
pop()  ���� ����� ������.
top()  ���� ��� �� �б�.
size() ���� ������ ������
empty() ������ ����ִ���.
*/

template<typename T>
class Stack
{
public:
	Stack()
		: _start(nullptr)
		, _idx(0)
		, _limitIdx(5)
	{
		_start = new T[_limitIdx];
	}

	~Stack() 
	{
		if (_start)
		{
			delete[] _start;
		}
	}

	void push(T data);
	void pop();
	T top();
	int32 size();
	bool empty();
	void reSize();
	void print();


private:
	T* _start;
	int32 _idx;
	int32 _limitIdx;
};

template<typename T>
inline void Stack<T>::push(T data)
{
	// �ִ� �迭 ũ�⺸�� Ŀ���� ����
	if (_idx > _limitIdx)
	{
		return;
	}

	_start[_idx] = data;
	++_idx;
}

template<typename T>
inline void Stack<T>::pop()
{
	// �����Ͱ� ������ ����
	if (_idx == 0)
	{
		return;
	}

	_start[_idx] = 0;
	--_idx;
}

template<typename T>
inline T Stack<T>::top()
{
	return _start[_limitIdx];
}

template<typename T>
inline int32 Stack<T>::size()
{
	return _idx;
}

template<typename T>
inline bool Stack<T>::empty()
{
	if (_idx == 0)
	{
		return true;
	}

	return false;
}

template<typename T>
inline void Stack<T>::reSize()
{

	// 1. ���ο� ���� �����
	T* newSpace = new T[_limitIdx * 2];
	// 2. ���ο� ������ ���� �� ����
	for (int i = 0; i > _idx; ++i)
	{
		newSpace[i] = _start[i];
	}
	// 3. ���� �� ����
	delete[] _start;
	_start = newSpace;
}

template<typename T>
inline void Stack<T>::print()
{
	for (int i = 0; i < _idx; ++i)
	{
		std::cout << _start[i] << std::endl;
	}
}

