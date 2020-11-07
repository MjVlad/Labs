#include "Stack.h"
template<typename T>
const T& Node<T>::getdata() const {
	return data;
}

template<typename T>
Stack<T>::Stack() {
	size_ = 0;
	tail = nullptr;
	head = nullptr;
}
 
template<typename T>
 void Stack<T>::push(const T& dt) {
	Node<T>* tmp = new Node<T>(dt, tail);
	if (tail)
		tail->next = tmp;
	else { 
		head = tmp;
	}
	tail = tmp;
	size_++;
}

template<typename T>
T Stack<T>::pop() {
	if (!tail) throw std::out_of_range("stack is empty");
	T tmp = tail->data;
	Node<T>* nd = tail->prev;
	delete tail;
	tail = nd;
	if (tail)
		tail->next = nullptr;
	size_--;
	return tmp;
}

template<typename T>
void Stack<T>::clear() {
	while (size_ > 0) {
		Node<T>* nd = tail->prev;
		delete tail;
		tail = nd;
		size_--;
	}
}

template<typename Tp>
inline std::ostream& operator<<(std::ostream& out, const Node<Tp>& st){
	out << st.getdata();
	return out;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Stack<T>& st) {
	Node<T>* tmp = st.tail;
	for (size_t i = 0; i < st.size_; i++) {
		out << tmp->data << " || ";
		tmp = tmp->prev;
	}
	return out;
}

template<typename T>
Stack<T>::~Stack() {
	this->clear();
}

template<typename T>
Stack<T>::Stack(const Stack<T>& st) {
	size_ = 0;
	head = nullptr;
	tail = nullptr;
	Node<T>* nd = st.head;
	for (size_t i = 0; i < st.size_; i++) {
		this->push(nd->getdata());
		nd = nd->next;
	}
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& st) {
	if (this == &st) return *this;
	int diff_size = (int)size_ - (int)st.size_;
	Node<T>* l_nd = head;
	Node<T>* r_nd = st.head;
	if (diff_size < 0) {
		for (int i = 0; i < size_; i++) {
			l_nd->data = r_nd->data;
			l_nd = l_nd->next;
			r_nd = r_nd->next;
		}
		for (int i = 0; i > diff_size; i--) {
			this->push(r_nd->getdata());
			r_nd = r_nd->next;
		}
	}
	else {
		for (int i = 0; i < st.size_; i++) {
			l_nd->data = r_nd->data;
			l_nd = l_nd->next;
			r_nd = r_nd->next;
		}
		for (int i = 0; i < diff_size; i++) {
			this->pop();
		}
	}
	return *this;
}

template<typename T>
bool Stack<T>::operator==(const std::stack<T>& Sr) {  // operator for std::stack
	if (this->size_ != Sr.size()) return false;
	Node<T>* nd = this->tail;
	std::stack<T> tmp(Sr);
	for (size_t i = 0; i < this->size(); i++) {
		if (nd->getdata() != tmp.top()) return false;
		nd = nd->prev;
		tmp.pop();
	}
	return true;
}

template<typename T>
inline Iterator<T> Stack<T>::begin(){
	Iterator<T> it(head);
	return it;
}

template<typename T>
inline Iterator<T> Stack<T>::end(){
	Iterator<T> it(tail->next);
	return it;
}

template<typename T>
inline Iterator<T>& Iterator<T>::operator=(const Iterator<T>& r) {
	nd = r.nd;
	return *this;
}

template<typename T>
inline Iterator<T> Iterator<T>::operator-(int r) const{
	Iterator<T> tmp(*this);
	while (r) {
		--tmp;
		r--;
	}
	return tmp;
}

template<typename T>
inline Iterator<T> Iterator<T>::operator+(int r) const{
	Iterator<T> tmp(*this);
	while (r) {
		++tmp;
		r--;
	}
	return tmp;
}

template<typename T>
inline Iterator<T>& Iterator<T>::operator++() {
	if (!nd) throw std::logic_error("the iterator points to void");
	nd = nd->next;
	return *this;
}

template<typename T>
inline Iterator<T>& Iterator<T>::operator--() {
	if (!nd) throw std::logic_error("the iterator points to void");
	nd = nd->prev;
	return *this;
}

template<typename T>
inline bool Iterator<T>::operator==(const Iterator<T>& r) {
	return nd == r.nd;
}

template<typename T>
inline bool Iterator<T>::operator!=(const Iterator<T>& r) {
	return nd != r.nd;
}

template<typename T>
inline T& Iterator<T>::dereference() {
	return nd->data;
}

template<typename T>
inline T& Iterator<T>::operator*(){
	return nd->data;
}

template<typename T>
inline T& Iterator<T>::operator->(){
	return nd->data;
}
