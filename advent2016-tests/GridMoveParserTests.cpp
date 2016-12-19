#include "stdafx.h"
#include "CppUnitTest.h"

#include "../advent2016/GridMoveParser.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Advent2016;

namespace advent2016tests
{		
	TEST_CLASS(GridMoveParserTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            GridMoveParser parser;
            char input[] = "R2, L3";
            parser.parse(input);
            auto shortestPathDistance = parser.getShortestPathDistance();
            Assert::AreEqual((float)5, (float)shortestPathDistance, 0.f);
		}

        TEST_METHOD(TestMethod2)
        {
            GridMoveParser parser;
            char input[] = "R2, R2, R2";
            parser.parse(input);
            auto shortestPathDistance = parser.getShortestPathDistance();
            Assert::AreEqual((float)2, (float)shortestPathDistance, 0.f);
        }

        TEST_METHOD(TestMethod3)
        {
            GridMoveParser parser;
            char input[] = "R5, L5, R5, R3";
            parser.parse(input);
            auto shortestPathDistance = parser.getShortestPathDistance();
            Assert::AreEqual((float)12, (float)shortestPathDistance, 0.f);
        }

    };
}
