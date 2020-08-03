#pragma once
#include <iostream>
#include <stack>

template <typename T>
class Node {
private:
	T data;
	Node* prev;
	Node(const T& dt, Node* pr) {
		prev = pr;
		data = dt;
	}
	T getdata() const;
public:
	template <typename Tp>
	friend class Stack;
	template <typename Tp>
	friend std::ostream& operator<<(std::ostream& out, const  Stack<Tp>& st);
	template <typename T>
	friend bool operator==(const Stack<T>& Sl, const std::stack<T> Sr);
};

template <typename T>
class Stack {
private:
	size_t size_;
	Node<T>* tail;
public:
	Stack();
	T& push(const T& dt);
	T pop();
	size_t size() const { return size_; }
	void clear();
	template <typename T>
	friend std::ostream& operator<<(std::ostream& out, const  Stack<T>& st);
	~Stack();
	Stack(const Stack<T>& st);
	Stack<T>& operator=(const  Stack<T>& st);
	template <typename T>
	friend bool operator==(const Stack<T>& Sl, const std::stack<T> Sr);
};
#include"Stack.ipp"