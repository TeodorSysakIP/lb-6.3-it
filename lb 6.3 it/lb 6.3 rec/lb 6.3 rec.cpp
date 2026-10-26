
#include "pch.h"
#include "CppUnitTest.h"
#include "../lb 6.3 it/lb 6.3 it.cpp"        

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest63Iterative
{
    TEST_CLASS(IsNonIncreasingTests)
    {
    public:

        TEST_METHOD(SortedNonIncreasingInt)
        {
            int a[] = { 9, 7, 5, 3, 1 };
            Assert::IsTrue(IsNonIncreasing(a, 5));
            Assert::IsTrue(IsNonIncreasing<int>(a, 5));
        }

        TEST_METHOD(EqualElementsAllowed)
        {
            int a[] = { 4, 4, 4, 4 };
            int b[] = { 5, 5, 3, 3, 3, 1 };
            Assert::IsTrue(IsNonIncreasing(a, 4));
            Assert::IsTrue(IsNonIncreasing(b, 6));
        }

        TEST_METHOD(AscendingIsNotNonIncreasing)
        {
            int a[] = { 1, 2, 3, 4, 5 };
            Assert::IsFalse(IsNonIncreasing(a, 5));
            Assert::IsFalse(IsNonIncreasing<int>(a, 5));
        }

        TEST_METHOD(ViolationAtStartMiddleEnd)
        {
            int s[] = { 1, 5, 4, 3 };
            int m[] = { 9, 5, 6, 3 };
            int e[] = { 9, 5, 4, 7 };
            Assert::IsFalse(IsNonIncreasing(s, 4));
            Assert::IsFalse(IsNonIncreasing(m, 4));
            Assert::IsFalse(IsNonIncreasing(e, 4));
        }

        TEST_METHOD(SingleAndEmpty)
        {
            int a[] = { 42 };
            Assert::IsTrue(IsNonIncreasing(a, 1));
            Assert::IsTrue(IsNonIncreasing(a, 0));
        }

        TEST_METHOD(TwoElements)
        {
            int up[] = { 1, 2 };
            int down[] = { 2, 1 };
            Assert::IsFalse(IsNonIncreasing(up, 2));
            Assert::IsTrue(IsNonIncreasing(down, 2));
        }

        TEST_METHOD(NegativeNumbers)
        {
            int a[] = { 3, 0, -1, -5, -5 };
            int b[] = { -5, -1, 0 };
            Assert::IsTrue(IsNonIncreasing(a, 5));
            Assert::IsFalse(IsNonIncreasing(b, 3));
        }

        TEST_METHOD(TemplateDouble)
        {
            double a[] = { 2.5, 2.5, 1.25, -0.5 };
            double b[] = { 2.5, 2.6, 1.25 };
            Assert::IsTrue(IsNonIncreasing<double>(a, 4));
            Assert::IsFalse(IsNonIncreasing<double>(b, 3));
        }

        TEST_METHOD(TemplateString)
        {
            string a[] = { "c", "b", "b", "a" };
            string b[] = { "a", "b", "c" };
            Assert::IsTrue(IsNonIncreasing<string>(a, 4));
            Assert::IsFalse(IsNonIncreasing<string>(b, 3));
        }

        TEST_METHOD(TemplateChar)
        {
            char a[] = { 'z', 'm', 'm', 'a' };
            char b[] = { 'a', 'z' };
            Assert::IsTrue(IsNonIncreasing<char>(a, 4));
            Assert::IsFalse(IsNonIncreasing<char>(b, 2));
        }

        TEST_METHOD(ArrayIsNotModified)
        {
            int a[] = { 3, 1, 2 };
            IsNonIncreasing(a, 3);
            Assert::AreEqual(3, a[0]);
            Assert::AreEqual(1, a[1]);
            Assert::AreEqual(2, a[2]);
        }
    };
}