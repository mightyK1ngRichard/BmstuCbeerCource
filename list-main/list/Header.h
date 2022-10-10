#pragma once
#include <iostream>

template <class T>
class list {
public:
	list();
	~list();
	T& operator[](const size_t& index);
	T operator[](const size_t& index) const;
	template <class T1>
	friend std::ostream& operator<<(std::ostream& fin, const list<T1>& inf);
	void push_back(const T& data);
	void push_front(const T& data);
	void pop_back();
	void pop_front();
	void clear();
	bool empty();
	void insert(const size_t& index, const T& data);
	void removeIndex(const size_t& index);
	size_t size() const;

protected:
	template <class T>
	class Node {
	public:
		Node* _pNext;
		T _data;
		Node(const T& data = 0, Node* adress = nullptr) : _pNext(adress), _data(data) {}
		~Node() = default;
	};

private:
	Node<T>* _head;
	size_t _size;
};
template <class T>
list<T>::list() : _size(0) {
	_head = nullptr;
}
template<class T>
list<T>::~list() {
	clear();
}
template<class T1>
std::ostream& operator<<(std::ostream& fin, const list<T1>& inf) {
	for (size_t i = 0; i < inf.size(); ++i)
		fin << inf[i] << ' ';
	return fin;
}
template<class T>
T& list<T>::operator[](const size_t& index) {
	size_t counter = 0;
	Node<T>* temp = _head;
	while (temp != nullptr) {
		if (counter == index) {
			return temp->_data;
		}
		else {
			temp = temp->_pNext;
			++counter;
		}
	}
}
template<class T>
T list<T>::operator[](const size_t& index) const {
	size_t counter = 0;
	Node<T>* temp = _head;
	while (temp != nullptr) {
		if (counter == index) {
			return temp->_data;
		}
		else {
			temp = temp->_pNext;
			++counter;
		}
	}
}
template<class T>
void list<T>::push_back(const T& data) {
	if (_head == nullptr) {
		_head = new Node<T>(data);
		++_size;
	}
	else {
		Node<T>* temp = _head;
		while (temp->_pNext != nullptr) {
			temp = temp->_pNext;
		}
		temp->_pNext = new Node<T>(data);
		++_size;
	}
}
template<class T>
void list<T>::push_front(const T& data) {
	_head = new Node<T>(data, _head);
	++_size;
}
template<class T>
void list<T>::pop_back() {
	if (!empty()) {
		removeIndex(_size - 1);
	}
}
template<class T>
void list<T>::pop_front() {
	Node<T>* temp = _head;
	_head = _head->_pNext;
	delete temp;
	--_size;
}
template<class T>
inline size_t list<T>::size() const {
	return _size;
}
template<class T>
void list<T>::clear() {
	while (_size) {
		pop_front();
	}
}
template<class T>
bool list<T>::empty() {
	return _size == 0 ? true : false;
}
template<class T>
void list<T>::insert(const size_t& index, const T& data) {
	if (index == 0) {
		push_front(data);
	}
	else {
		Node<T>* temp = _head;
		for (size_t i = 0; i < index - 1; ++i) {
			temp = temp->_pNext;
		}
		Node<T>* newNode = new Node<T>(data, temp->_pNext);
		temp->_pNext = newNode;
		++_size;
	}
}
template<class T>
void list<T>::removeIndex(const size_t& index) {
	if (index == 0) {
		pop_front();
	}
	else {
		Node<T>* temp = _head;
		for (size_t i = 0; i < index - 1; ++i) {
			temp = temp->_pNext;
		}
		Node<T>* forDelete = temp->_pNext;
		temp->_pNext = forDelete->_pNext;
		delete forDelete;
		--_size;
	}
}
