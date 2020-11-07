#include "pch.h"
#include "CppUnitTest.h"
#include "..\lab 17\Stack.h"
#include "..\lab 17\point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethodPush_Pop) {
			Stack<int> s;
			std::stack<int> st;
			for (int i = 0; i < 10; i++) {
				st.push(i);
				s.push(i);
			}
			Assert::IsTrue(s == st);
			for (int i = 0; i < 10; i++) {
				Assert::AreEqual(s.pop(), st.top());
				st.pop();
			}
			try {
				s.pop();
				Assert::IsFalse(true);
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}
		TEST_METHOD(TestMethodConstructorCopy) {
			Stack<int> st;
			for (int i = 0; i < 10; i++) {
				st.push(i);
			}
			Stack<int> st_copy(st);
			for (int i = 0; i < 10; i++)
				Assert::AreEqual(st.pop(), st_copy.pop());
		}
		TEST_METHOD(TestMethodAssignmentoperator) {
			Stack<int> st;
			for (int i = 0; i < 10; i++) {
				st.push(i);
			}
			Stack<int> st_copy;
			st_copy = st;
			for (int i = 0; i < 10; i++)
				Assert::AreEqual(st.pop(), st_copy.pop());
		}
		TEST_METHOD(TestMethodSize) {
			Stack<int> a;
			size_t test = 18;
			int i;
			for (i = 0; i < test; i++) a.push(i);
			Assert::AreEqual(a.size(), test);
			for (i = 0; i < 6; i++) a.pop();
			Assert::AreEqual(a.size(), test - i);
		}
		TEST_METHOD(TestMethodClear) {
			Stack<int> st;
			for (int i = 0; i < 10; i++) {
				st.push(i);
			}
			st.clear();
			try {
				st.pop();
				Assert::IsFalse(true);
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}
	};
}
