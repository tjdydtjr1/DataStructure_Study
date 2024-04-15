#pragma once


/* ================================
			Stack
 ================================ */

/*
push() 스택에 쌓는다.
pop()  스택 상단을 뺴낸다.
top()  스택 상단 값 읽기.
size() 스택 사이즈 몇인지
empty() 스택이 비어있는지.
*/

#define MAX_ARRAY_SIZE 5


template<typename T>
class Stack
{
public:
	Stack()
		: _start(nullptr)
		, _idx(-1)
		, _limitIdx(MAX_ARRAY_SIZE)
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
	int64 size();
	bool empty();
	void reSize();


private:
	T* _start;
	int64 _idx;
	int64 _limitIdx;
};

template<typename T>
inline void Stack<T>::push(T data)
{
	// 최대 배열 크기보다 커지면 최대 크기 재할당
	if (_idx == _limitIdx - 1)
	{
		Stack<T>::resize();
		_start[_idx] = data;
		++_idx;
		return;
	}

	++_idx;
	_start[_idx] = data;
}

template<typename T>
inline void Stack<T>::pop()
{
	// 데이터가 없으면 리턴
	if (_idx == -1)
	{
		return;
	}

	_start[_idx] = nullptr;
	--_idx;
}

template<typename T>
inline T Stack<T>::top()
{
	return _start[_idx];
}

template<typename T>
inline int64 Stack<T>::size()
{
	return _idx + 1;
}

template<typename T>
inline bool Stack<T>::empty()
{
	if (_idx == -1)
	{
		return true;
	}

	return false;
}

template<typename T>
inline void Stack<T>::reSize()
{
	uint64 temp = _limitIdx;

	_limitIdx = temp + 10;

	// 1. 새로운 공간 만들고
	T* newSpace = new T[_limitIdx];
	// 2. 새로운 공간에 기존 꺼 복사
	for (int i = 0; i > _idx; ++i)
	{
		newSpace[i] = _start[i];
	}
	// 3. 기존 꺼 삭제
	delete[] _start;
	_start = newSpace;
}

