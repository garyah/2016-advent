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
            parser.parse("R2, L3");
            auto shortestPathDistance = parser.getShortestPathDistance();
            Assert::AreEqual((float)5, (float)shortestPathDistance, 0.f, L"First test input did not produce expected test output");
		}

	};
}
