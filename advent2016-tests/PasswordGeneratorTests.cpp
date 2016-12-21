#include "stdafx.h"
#include "CppUnitTest.h"

#include "../advent2016/PasswordGenerator.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Advent2016;

namespace advent2016tests
{		
	TEST_CLASS(PasswordGeneratorTests)
	{
	public:
		
		TEST_METHOD(TestMethod05a1)
		{
            PasswordGenerator generator;
            generator.generate("abc");
            Assert::AreEqual("18f47a30", generator.getPassword());
		}

    };
}
