#pragma once
#include <iostream>
#include <stack>
template <typename T>
class Iterator;
template <typename T>
class Stack;

template <typename T>
class Node {
	friend class Iterator<T>;
	friend class Stack<T>;
private:
	T data;
	Node* prev;
	Node* next = nullptr;
	Node(const T& dt, Node* pr) {
		prev = pr;
		data = dt;
	}
public:
	const T& getdata() const;
	template <typename Tp>
	friend std::ostream& operator<<(std::ostream& out, const  Node<Tp>& st);
	template <typename Tp>
	friend std::ostream& operator<<(std::ostream& out, const  Stack<Tp>& st);
};

template <typename T>
class Stack {
private:
	size_t size_;
	Node<T>* tail;
	Node<T>* head;
public:
	Stack();
	/*T&*/void push(const T& dt);
	T pop();
	size_t size() const { return size_; }
	void clear();
	template <typename T>
	friend std::ostream& operator<<(std::ostream& out, const  Stack<T>& st);
	~Stack();
	Stack(const Stack<T>& st);
	Stack<T>& operator=(const  Stack& st);
	bool operator==(const std::stack<T>& Sr);
	Iterator<T> begin();
	Iterator<T> end();
};

template <typename T>
class Iterator {
private:
	Node<T>* nd;
public:
	Iterator() { nd = nullptr; };
	Iterator(const Iterator& r) { nd = r.nd; };
	Iterator(Node<T>* node) { nd = node; };

	Iterator& operator=(const Iterator& r);
	Iterator operator-(int r) const;
	Iterator operator+(int r) const;
	Iterator& operator++();
	Iterator& operator--();

	bool operator==(const Iterator& r);
	bool operator!=(const Iterator& r);

	T& dereference();
	T& operator*();
	T& operator->();
};

#include"Stack.ipp"
