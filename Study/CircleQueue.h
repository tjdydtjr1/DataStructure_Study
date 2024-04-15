#pragma once

/* ================================
			CircelQueue
 ================================ */

#define MAX_ARRAY_SIZE 10

template<typename T>
class CircleQueue
{
public:
	CircleQueue() 
		: _queue(nullptr)
		, _size(-1)
		, _front(0)
		, _rear(0)
		, _limitIdx(MAX_ARRAY_SIZE)
	{}
	~CircleQueue()
	{
		if (_size)
		{
			delete[] _size;
		}
	}

	void push(T data);
	void pop();
	int64 size();
	bool empty();
	bool full();

private:
	T*			_queue;
	int64		_size;
	int64		_front;
	int64		_rear;
	int64		_limitIdx;
};

template<typename T>
inline void CircleQueue<T>::push(T data)
{
}

template<typename T>
inline void CircleQueue<T>::pop()
{
}

template<typename T>
inline int64 CircleQueue<T>::size()
{
	return _size;
}

template<typename T>
inline bool CircleQueue<T>::empty()
{
	if (_front == _rear)
	{
		return true;
	}

	return false;
}

template<typename T>
inline bool CircleQueue<T>::full()
{
	if()

	return false;
}
