#pragma once

template<typename T>
class LinkedList
{
	struct Node
	{
		T data;
		Node* nextNode;
	};

public:
	LinkedList() : _head(nullptr) {}
	~LinkedList() {}

public:
	class iterator;

	// iterator용 함수
	iterator begin()
	{
		return iterator(this->_head, 0);
	}

	iterator end()
	{
		Node* temp = _head;
		int idx = 0;
		while (temp != nullptr)
		{
			temp = temp->nextNode;
			++idx;
		}

		return iterator(temp, idx);
	}


public:
	void push_back(T value);

	void pop_back();

	bool find(T value);

	void print();

private:
	// 시작점 노드
	Node* _head;


public:
	class iterator
	{
	public:
		iterator()
			: _head(nullptr)
			, _idx(-1)

		{}
		iterator(Node* node, int idx)
			: _head(node)
			, _idx(idx)
		{}

		~iterator() {}

		iterator& operator ++()
		{
			if (_head)
			{
				_head = _head->nextNode;
				++_idx;
			}

			return *this;
		}

		bool operator !=(const iterator& other) // 복사생성자
		{
			return _head != other._head;
		}

		T operator*()
		{
			return _head->data;
		}

	private:
		Node* _head;
		int _idx;
	};

};


template<typename T>
void LinkedList<T>::push_back(T value)
{
	// 새로 추가 되는 노드
	Node* newNode = new Node();
	newNode->data = value;
	newNode->nextNode = nullptr;

	// 시작이 아무것도 없으면 바로 넣기
	if (_head == nullptr)
	{
		_head = newNode;
		return;
	}

	// _head부터 시작해서 넘어갈 임시 Node
	Node* tempNode = _head;

	// 다음노드 주소가 있는지 순회
	while (tempNode->nextNode != nullptr)
	{
		tempNode = tempNode->nextNode;
	}

	//nullptr이 나올 때까지 다음주소로 이동 된 상태 다음 노드로 새 노드 가르키기
	tempNode->nextNode = newNode;
}

template<typename T>
void LinkedList<T>::pop_back()
{
	// 없으면 바로 리턴
	if (!_head)
	{
		return;
	}

	// 노드가 하나만 있는 경우 바로 삭제
	if (_head->nextNode == nullptr)
	{
		delete _head;
		_head = nullptr;
		return;
	}

	// 마지막 이전 노드 찾기
	Node* tempNode = _head;
	while (tempNode->nextNode->nextNode != nullptr)
	{
		tempNode = tempNode->nextNode;
	}

	// 마지막 노드 삭제
	delete tempNode->nextNode;

	// 이렇게 하지않으면 문제 생길수도 있다고 함
	tempNode->nextNode = nullptr;
}

template<typename T>
bool LinkedList<T>::find(T value)
{
	Node* tempNode = _head;

	// 마지막 노드도 포함하려면 자기 자신이 nullptr 인지 확인
	while (tempNode != nullptr)
	{
		if (tempNode->data == value)
		{
			std::cout << "찾은 값 : " << tempNode->data << std::endl;
			return true;
		}

		tempNode = tempNode->nextNode;
	}

	std::cout << value << " 값이 존재하지 않음" << std::endl;

	return false;
}


template<typename T>
void LinkedList<T>::print()
{
	Node* tempNode = _head;

	// 마지막 노드도 포함하려면 자기 자신이 nullptr 인지 확인
	while (tempNode != nullptr)
	{
		std::cout << tempNode->data << std::endl;

		tempNode = tempNode->nextNode;
	}
}