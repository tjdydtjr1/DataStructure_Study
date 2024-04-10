#pragma once

/*
push() ���ÿ� �״´�.
pop()  ���� ����� ������.
top()  ���� ��� �� �б�.
size() ���� ������ ������
empty() ������ ����ִ���.
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
	// �ִ� �迭 ũ�⺸�� Ŀ���� �ִ� ũ�� ���Ҵ�
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
	// �����Ͱ� ������ ����
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

	// 1. ���ο� ���� �����
	T* newSpace = new T[_limitIdx];
	// 2. ���ο� ������ ���� �� ����
	for (uint64 i = 0; i <= _idx; ++i)
	{
		newSpace[i] = _start[i];
	}
	// 3. ���� �� ����
	delete[] _start;
	_start = newSpace;
}

