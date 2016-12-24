#include "stdafx.h"
#include "CppUnitTest.h"

#include "../advent2016/TriangleValidator.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Advent2016;

namespace advent2016tests
{		
	TEST_CLASS(TriangleValidatorTests)
	{
	public:
		
		TEST_METHOD(TestMethod03a1)
		{
            TriangleValidator validator;
            validator.addRow("5 10 25");
            auto numValid = validator.getNumValidByRows();
            Assert::AreEqual((float)0, (float)numValid, 0.f);
		}

        TEST_METHOD(OneValidReturnsOne)
        {
            TriangleValidator validator;
            validator.addRow("3 4 5");
            auto numValid = validator.getNumValidByRows();
            Assert::AreEqual((float)1, (float)numValid, 0.f);
        }

        TEST_METHOD(TestMethod03b1)
        {
            TriangleValidator validator;
            validator.addRow("101 301 501");
            auto numValid = validator.getNumValidByRows();
            Assert::AreEqual((float)0, (float)numValid, 0.f);
        }

    };
}
