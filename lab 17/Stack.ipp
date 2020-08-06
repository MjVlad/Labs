template<typename T>
T Node<T>::getdata() const {
	return data;
}

template<typename T>
Stack<T>::Stack() {
	size_ = 0;
	tail = nullptr;
}

template<typename T>
inline T& Stack<T>::push(const T& dt) {
	Node<T>* tmp = new Node<T>(dt, tail);
	tail = tmp;
	size_++;
	return tail->data;
}

template<typename T>
T Stack<T>::pop() {
	if (!tail) throw std::out_of_range("stack is empty");
	T tmp = tail->getdata();
	Node<T>* nd = tail->prev;
	delete tail;
	tail = nd;
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
	tail = nullptr;
	T* tmp = new T[st.size_];
	Node<T>* nd = st.tail;
	size_t i = 1;
	for (i; i <= st.size_; i++) {
		tmp[i - 1] = nd->data;
		nd = nd->prev;
	}
	for (i--; i > 0; i--) {
		this->push(tmp[i - 1]);
	}
	delete[] tmp;
}

template<typename T>
inline Stack<T>& Stack<T>::operator=(const Stack<T>& st) {
	if (this == &st) return *this;
	this->clear();
	tail = nullptr;
	T* tmp = new T[st.size_];
	Node<T>* nd = st.tail;
	size_t i = 1;
	for (i; i <= st.size_; i++) {
		tmp[i - 1] = nd->data;
		nd = nd->prev;
	}
	for (i--; i > 0; i--) {
		this->push(tmp[i - 1]);
	}
	delete[] tmp;
	return *this;
}

template<typename T>
bool Stack<T>::operator==(const std::stack<T>& Sr) {
	Node<T>* nd = this->tail;
	std::stack<T> tmp(Sr);
	for (size_t i = 0; i < this->size(); i++) {
		if (nd->getdata() != tmp.top()) return false;
		nd = nd->prev;
		tmp.pop();
	}
	return true;
}