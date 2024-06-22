#pragma once

/* ================================
			CircelQueue
 ================================ */

/*
isFull() 꽉 찼는지?
isEmpty() 비었는지?
push()	 값 넣기
pop()	값 빼기
peek()  현재 가리키고 있는 값 확인


*/


#define MAX_ARRAY_SIZE 10

template<typename T>
class CircleQueue
{
public:
	CircleQueue() 
		: _queue(nullptr)
		, _size(0)
		, _front(0)
		, _rear(0)
		, _limitIdx(MAX_ARRAY_SIZE)
	{
		_queue = new T[_limitIdx];
	}
	~CircleQueue()
	{
		if (_queue)
		{
			delete[] _queue;
		}
	}

	void push(T data);
	void pop();
	int64 size();
	int64 maxSize();
	bool empty(); 
	bool full();
	T peek();


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
	// 꽉찼으면
	if (full())
	{
		cout << "빈 공간 없음" << endl;
		return;
	}

	_rear = (_rear + 1) % (_limitIdx);

	_queue[_rear] = data;

	++_size;
}

template<typename T>
inline void CircleQueue<T>::pop()
{
	// 비었으면
	if (empty())
	{
		cout << "비어있는 상태" << endl;
		return;
	}

	_front = (_front + 1) % (_limitIdx);

	--_size;
}

template<typename T>
inline int64 CircleQueue<T>::size()
{
	return _size;
}

template<typename T>
inline int64 CircleQueue<T>::maxSize()
{
	return _limitIdx + 1;
}

template<typename T>
inline bool CircleQueue<T>::empty()
{
	if (_front == _rear)
	{
		cout << "빈 상태" << endl;
		return true;
	}

	cout << "값이 있는 상태" << endl;

	return false;
}

template<typename T>
inline bool CircleQueue<T>::full()
{
	if ((_rear + 1) % _limitIdx == _front)
	{
		cout << "꽉찬 상태" << endl;
		return true;
	}

	cout << "공간 남은 상태" << endl;

	return false;
}

template<typename T>
inline T CircleQueue<T>::peek()
{
	return _queue[(_front + 1) % (_limitIdx)];
}
