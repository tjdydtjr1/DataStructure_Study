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

	// iterator�� �Լ�
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
	// ������ ���
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

		bool operator !=(const iterator& other) // ���������
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
	// ���� �߰� �Ǵ� ���
	Node* newNode = new Node();
	newNode->data = value;
	newNode->nextNode = nullptr;

	// ������ �ƹ��͵� ������ �ٷ� �ֱ�
	if (_head == nullptr)
	{
		_head = newNode;
		return;
	}

	// _head���� �����ؼ� �Ѿ �ӽ� Node
	Node* tempNode = _head;

	// ������� �ּҰ� �ִ��� ��ȸ
	while (tempNode->nextNode != nullptr)
	{
		tempNode = tempNode->nextNode;
	}

	//nullptr�� ���� ������ �����ּҷ� �̵� �� ���� ���� ���� �� ��� ����Ű��
	tempNode->nextNode = newNode;
}

template<typename T>
void LinkedList<T>::pop_back()
{
	// ������ �ٷ� ����
	if (!_head)
	{
		return;
	}

	// ��尡 �ϳ��� �ִ� ��� �ٷ� ����
	if (_head->nextNode == nullptr)
	{
		delete _head;
		_head = nullptr;
		return;
	}

	// ������ ���� ��� ã��
	Node* tempNode = _head;
	while (tempNode->nextNode->nextNode != nullptr)
	{
		tempNode = tempNode->nextNode;
	}

	// ������ ��� ����
	delete tempNode->nextNode;

	// �̷��� ���������� ���� ������� �ִٰ� ��
	tempNode->nextNode = nullptr;
}

template<typename T>
bool LinkedList<T>::find(T value)
{
	Node* tempNode = _head;

	// ������ ��嵵 �����Ϸ��� �ڱ� �ڽ��� nullptr ���� Ȯ��
	while (tempNode != nullptr)
	{
		if (tempNode->data == value)
		{
			std::cout << "ã�� �� : " << tempNode->data << std::endl;
			return true;
		}

		tempNode = tempNode->nextNode;
	}

	std::cout << value << " ���� �������� ����" << std::endl;

	return false;
}


template<typename T>
void LinkedList<T>::print()
{
	Node* tempNode = _head;

	// ������ ��嵵 �����Ϸ��� �ڱ� �ڽ��� nullptr ���� Ȯ��
	while (tempNode != nullptr)
	{
		std::cout << tempNode->data << std::endl;

		tempNode = tempNode->nextNode;
	}
}