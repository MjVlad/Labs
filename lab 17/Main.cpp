#include "Stack.h"

template<typename T>
void test(Stack<T>& St) {
	St.push(0);
	std::cout << St << std::endl;
	St.clear();
	std::cout << St << std::endl;
	St.push(0);
	std::cout << St << std::endl;
	St.pop();
	std::cout << St << std::endl;
	for (int i = 0; i < 10; i++) {
		St.push(i);
	}
	std::cout << St << std::endl;
	Stack<T> St_copy;
	St_copy = St;
	St.pop();
	std::cout << St << std::endl;
	std::cout << St_copy << std::endl;
	St_copy.clear();
	//St_copy.pop();
	Stack<T> st_copy_2(St);
	std::cout << st_copy_2 << std::endl;
}

int main() {
	try {
		Stack<int> St_int;
		test(St_int);
		Stack<point> St_point;
		test(St_point);
		Stack<int> St_double;
		test(St_double);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
}