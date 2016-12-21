#include "stdafx.h"
#include "CppUnitTest.h"

#include "../advent2016/RoomValidator.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Advent2016;

namespace advent2016tests
{		
	TEST_CLASS(RoomValidatorTests)
	{
	public:
		
		TEST_METHOD(TestMethod04a1)
		{
            RoomValidator validator;
            char input[] = "";
            validator.addRoom(input);
            auto sumOfIds = validator.getSumOfIds();
            Assert::AreEqual((float)1514, (float)sumOfIds, 0.f);
		}

    };
}
