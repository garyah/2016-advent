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
            char input[] = "5 10 25";
            validator.addTriangle(input);
            auto numValid = validator.getNumValid();
            Assert::AreEqual((float)0, (float)numValid, 0.f);
		}

        TEST_METHOD(OneValidReturnsOne)
        {
            TriangleValidator validator;
            char input[] = "3 4 5";
            validator.addTriangle(input);
            auto numValid = validator.getNumValid();
            Assert::AreEqual((float)1, (float)numValid, 0.f);
        }

    };
}
