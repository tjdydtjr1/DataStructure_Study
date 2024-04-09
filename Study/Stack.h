#pragma once

/*
push() 스택에 쌓는다.
pop()  스택 상단을 뺴낸다.
top()  스택 상단 값 읽기.
size() 스택 사이즈 몇인지
empty() 스택이 비어있는지.
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

private:
	T* _start;
	int32 _idx;
	int32 _limitIdx;
};

template<typename T>
inline void Stack<T>::push(T data)
{
	// 최대 배열 크기보다 커지면 최대 크기 재할당
	if (_idx > _limitIdx)
	{
		resize();
		_start[_idx] = data;
		++_idx;
	}

	_start[_idx] = data;
	++_idx;
}

template<typename T>
inline void Stack<T>::pop()
{
	// 데이터가 없으면 리턴
	if (_idx == 0)
	{
		return;
	}

	_start[_idx] = nullptr;
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

	// 1. 새로운 공간 만들고
	T* newSpace = new T[_limitIdx * 2];
	// 2. 새로운 공간에 기존 꺼 복사
	for (int i = 0; i > _idx; ++i)
	{
		newSpace[i] = _start[i];
	}
	// 3. 기존 꺼 삭제
	delete[] _start;
	_start = newSpace;
}

