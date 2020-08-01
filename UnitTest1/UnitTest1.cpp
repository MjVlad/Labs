#include "pch.h"
#include "CppUnitTest.h"
#include "..\lab 17\Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethodConstructor){
			Stack<int> a; Stack<double> d; Stack<point> p; Stack<char> c;
		}
		TEST_METHOD(TestMethodPush) {
			Stack<int> a; Stack<double> d; Stack<point> p; Stack<char> c;
			point pt(3, 7,9); int in = 5; double dl = 3.1415; char ch = 77;
			Assert::AreEqual(a.push(in),in);
			Assert::AreEqual(d.push(dl), dl);
			Assert::AreEqual(c.push(ch), ch);
			Assert::AreEqual(p.push(pt).x, pt.x);
			Assert::AreEqual(p.push(pt).y, pt.y);
			Assert::AreEqual(p.push(pt).z, pt.z);
		}
		TEST_METHOD(TestMethodPop) {
			Stack<int> a; Stack<double> d; Stack<point> p; Stack<char> c;
			point pt(3, 7, 9); int in = 5; double dl = 3.1415; char ch = 77;
			a.push(in); d.push(dl); c.push(ch); p.push(pt); p.push(pt); p.push(pt);
			Assert::AreEqual(a.pop(), in);
			Assert::AreEqual(d.pop(), dl);
			Assert::AreEqual(c.pop(), ch);
			Assert::AreEqual(p.pop().x, pt.x);
			Assert::AreEqual(p.pop().y, pt.y);
			Assert::AreEqual(p.pop().z, pt.z);
		}
		TEST_METHOD(TestMethodConstructorCopy) {
			Stack<int> a; Stack<double> d; Stack<point> p; Stack<char> c;
			point pt(3, 7, 9); int in = 5; double dl = 3.1415; char ch = 77;
			a.push(in); d.push(dl); c.push(ch); p.push(pt); p.push(pt); p.push(pt);
			Stack<int> a1(a); Stack<double> d1(d); Stack<point> p1(p); Stack<char> c1(c);
			Assert::AreEqual(a1.pop(), in);
			Assert::AreEqual(d1.pop(), dl);
			Assert::AreEqual(c1.pop(), ch);
			Assert::AreEqual(p1.pop().x, pt.x);
			Assert::AreEqual(p1.pop().y, pt.y);
			Assert::AreEqual(p1.pop().z, pt.z);
		}
		TEST_METHOD(TestMethodAssignmentoperator) {
			Stack<int> a; Stack<double> d; Stack<point> p; Stack<char> c;
			point pt(3, 7, 9); int in = 5; double dl = 3.1415; char ch = 77;
			a.push(in); d.push(dl); c.push(ch); p.push(pt); p.push(pt); p.push(pt);
			Stack<int> a1; Stack<double> d1; Stack<point> p1; Stack<char> c1;
			a1 = a; d1 = d; p1 = p; c1 = c;
			Assert::AreEqual(a1.pop(), in);
			Assert::AreEqual(d1.pop(), dl);
			Assert::AreEqual(c1.pop(), ch);
			Assert::AreEqual(p1.pop().x, pt.x);
			Assert::AreEqual(p1.pop().y, pt.y);
			Assert::AreEqual(p1.pop().z, pt.z);
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
			Stack<int> a;
			size_t test = 18;
			int i;
			for (i = 0; i < test; i++) a.push(i);
			Assert::AreEqual(a.size(), test);
			a.clear();
			Assert::AreEqual(a.size(), (size_t)0);
		}
	};
}
