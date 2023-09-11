#include <iostream>
#include <string>

template<typename T>
struct Node
{
	Node() 
	{
		
	}

	Node(T data) : _data(data)
	{

	}

	Node(T data, Node* prev, Node* next) : _data(data), _prev(prev), _next(next)
	{

	}

	T _data;
	Node* _prev = nullptr;
	Node* _next = nullptr;
};

template<typename T>
class Deque
{
public:
	Deque()
	{
		_head = new Node<T>();
		_tail = new Node<T>();

		_head->_next = _tail;
		_tail->_prev = _head;
	}

	~Deque()
	{
		while (empty())
		{
			Delete(_head->_next);
		}

		Delete(_head);
		Delete(_tail);
	}

	int size()
	{
		return _size;
	}

	bool empty()
	{
		bool ret = false;
		if (_size != 0)
			ret = true;

		return ret;
	}

	void push_front(T data_)
	{
		Node<T>* node = new Node<T>(data_);
		Push(node, _head->_next);
	}

	void push_back(T data_)
	{
		Node<T>* node = new Node<T>(data_);
		Push(node, _tail);
	}

	bool pop_front()
	{
		Node<T>* frontData = front();
		if (frontData == _head)
			return false;

		return Delete(frontData);
	}

	bool pop_back()
	{
		Node<T>* backData = back();
		if (backData == _tail)
			return false;

		return Delete(backData);
	}

	Node<T>* front()
	{
		if (_head->_next == _tail)
			return nullptr;

		return _head->_next;
	}

	Node<T>* back()
	{
		if (_tail->_prev == _head)
			return nullptr;

		return _tail->_prev;
	}

private:
	void Push(Node<T>* node_, Node<T>* nextNode_)
	{
		Node<T>* prevNode = nextNode_->_prev;
		prevNode->_next = node_;
		node_->_prev = prevNode;

		node_->_next = nextNode_;
		nextNode_->_prev = node_;

		++_size;
	}

	bool Delete(Node<T>* node)
	{
		if (node->_data == NULL)
			return false;

		Node<T>* prevNode = node->_prev;
		Node<T>* nextNode = node->_next;

		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;

		delete node;
		--_size;
		return true;
	}

private:
	Node<T>* _head = nullptr;
	Node<T>* _tail = nullptr;
	int _size = 0;
};


int main()
{
	Deque<int>* deq = new Deque<int>();

	int num;
	std::cin >> num;
	std::cin.ignore();

	for (int i = 0; i < num; ++i)
	{
		std::string str;
		int data;
		getline(std::cin, str);
		int spaceIdx = -1;
		for (unsigned int i = 0; i < str.length(); ++i)
		{
			if (str[i] == ' ')
			{
				spaceIdx = i;
			}
		}
		std::string str1;
		if (spaceIdx != -1)
		{
			str1 = str.substr(0, spaceIdx);
			std::string str2 = str.substr(spaceIdx + 1, str.length());
			

			str = str1;
			data = atoi(str2.c_str());
		}

/*
push_front *
push_back *
pop_front
pop_back
size *
empty *
front
back
0x00D5FA18
[ebp-54h]
*/

		if (str == "push_front")
		{
			deq->push_front(data);
		}
		else if (str == "push_back")
		{
			deq->push_back(data);
		}
		else if (str == "pop_front")
		{
			Node<int>* node = deq->front();
			if (node == nullptr)
				std::cout << -1 << std::endl;
			else
			{
				std::cout << node->_data << std::endl;
				deq->pop_front();
			}
		}
		else if (str == "pop_back")
		{
			Node<int>* node = deq->back();
			if (node == nullptr)
				std::cout << -1 << std::endl;
			else
			{
				std::cout << node->_data << std::endl;
				deq->pop_back();
			}
		}
		else if (str == "size")
		{
			std::cout << deq->size() << std::endl;
		}
		else if (str == "empty")
		{
			int ret = deq->empty() ? 0 : 1;
			std::cout << ret << std::endl;
		}
		else if (str == "front")
		{
			Node<int>* node = deq->front();
			if (node == nullptr)
				std::cout << -1 << std::endl;
			else
				std::cout << node->_data << std::endl;
		}
		else if (str == "back")
		{
			Node<int>* node = deq->back();
			if (node == nullptr)
				std::cout << -1 << std::endl;
			else
				std::cout << node->_data << std::endl;
		}
	}

	delete deq;
}