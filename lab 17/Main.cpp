#include "Stack.h"
#include "point.h"
#include <iterator>
#include <algorithm>

template<typename T>
void test(Stack<T>& St) {
	/*St.push(0);
	std::cout << St << std::endl;
	St.clear();
	std::cout << St << std::endl;
	St.push(0);
	std::cout << St << std::endl;
	St.pop();
	std::cout << St << std::endl;*/
	for (int i = 0; i < 10; i++) {
		St.push(i);
	}
	std::cout << St << std::endl;
	for (Iterator<T> it = St.begin(); it != St.end(); ++it) {
		std::cout << *it;
	}
	std::cout << std::endl;
	//std::copy(St.begin(), St.end(), std::ostream_iterator<T>(std::cout, " "));
	/*Iterator<T> it(St.end());
	Iterator<T> tmp = St.begin() - 1;
	for (it; it != tmp; --it) {
		std::cout << it.dereference() << " || ";
	}*/
	//std::cout << std::endl;
	/*it = St.begin();
	for (it; it != St.end() + 1; ++it) {
		std::cout << it.dereference() << " || ";
	}*/
	/*std::cout << std::endl;
	Stack<T> St_copy;
	for (int i = 0; i < 5; i++)
		St_copy.push(i);
	std::cout << St << std::endl;
	std::cout << St_copy << std::endl;
	St_copy = St;
	std::cout << St_copy << std::endl;
	for (int i = 0; i < 5; i++)
		St_copy.push(i);
	std::cout << St_copy << std::endl;
	St_copy = St;
	std::cout << St_copy << std::endl;
	St.pop();
	std::cout << St << std::endl;
	std::cout << St_copy << std::endl;
	St_copy.clear();
	Stack<T> st_copy_2(St);
	std::cout << st_copy_2 << std::endl;*/
}

int main() {
	try {
		Stack<int> St_int;
		/*St_int.push(5);
		Iterator<Node<int>> it(St_int.begin());
		Node<int> u = *it;
		std::cout << u.getdata();
		std::cout << *it;*/
		test(St_int);
		Stack<point> St_point;
		test(St_point);
		Stack<double> St_double;
		test(St_double);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
}