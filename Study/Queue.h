#pragma once

/*
push() 스택에 쌓는다.
pop()  스택 상단을 뺴낸다.
top()  스택 상단 값 읽기.
size() 스택 사이즈 몇인지
empty() 스택이 비어있는지.
*/

template<typename T>
class Queue
{
public:
	Queue()
		: _start(nullptr)
		, _idx(-1)
		, _limitIdx(5)
	{
		_start = new T[_limitIdx];
	}

	~Queue()
	{
		if (_start)
		{
			delete[] _start;
		}
	}

	void		push(T data);
	void		pop();
	T*			back();
	T*			front();
	int64		size();
	bool		empty();
	void		reSize();


private:
	T*			_start;
	uint64		_idx;
	uint64		_limitIdx;
};

template<typename T>
inline void Queue<T>::push(T data)
{
	// 최대 배열 크기보다 커지면 최대 크기 재할당
	if (_idx == _limitIdx - 1)
	{
		Queue<T>::reSize();
		_start[_idx] = data;
		++_idx;
		return;
	}

	++_idx;
	_start[_idx] = data;
}

template<typename T>
inline void Queue<T>::pop()
{
	// 데이터가 없으면 리턴
	if (_idx == -1)
	{
		return;
	}


	for (int i = 0; i < _limitIdx; ++i)
	{
		_start[i] = _start[i + 1];
	}

	_start[_limitIdx - 1] = NULL;
	--_idx;
}

template<typename T>
inline T* Queue<T>::back()
{
	return &_start[_idx];
}

template<typename T>
inline T* Queue<T>::front()
{
	return &_start[0];
}

template<typename T>
inline int64 Queue<T>::size()
{
	return _idx + 1;
}

template<typename T>
inline bool Queue<T>::empty()
{
	if (_idx == -1)
	{
		return true;
	}

	return false;
}

template<typename T>
inline void Queue<T>::reSize()
{
	uint64 temp = _limitIdx;

	_limitIdx = temp + 10;

	// 1. 새로운 공간 만들고
	T* newSpace = new T[_limitIdx];
	// 2. 새로운 공간에 기존 꺼 복사
	for (uint64 i = 0; i <= _idx; ++i)
	{
		newSpace[i] = _start[i];
	}
	// 3. 기존 꺼 삭제
	delete[] _start;
	_start = newSpace;
}

