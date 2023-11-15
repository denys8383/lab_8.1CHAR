#include "pch.h"
#include "CppUnitTest.h"
#include "../Project8.1char/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81char
{
	TEST_CLASS(UnitTest81char)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char str[] = "abc+def-ghi=";
			const char targets[] = "+-=";

			int count = Count(str, targets);
			Assert::AreEqual(3, count);
		}
	};
}
