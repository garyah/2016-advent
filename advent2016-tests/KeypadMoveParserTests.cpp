#include "stdafx.h"
#include "CppUnitTest.h"

#include "../advent2016/KeypadMoveParser.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Advent2016;

namespace advent2016tests
{		
	TEST_CLASS(KeypadMoveParserTests)
	{
	public:
		
		TEST_METHOD(TestMethod02a1)
		{
            KeypadMoveParser parser;
            parser.parseInstruction("ULL");
            parser.parseInstruction("RRDDD");
            parser.parseInstruction("LURDL");
            parser.parseInstruction("UUUUD");
            auto code = parser.getCode();
            Assert::AreEqual((float)1985, (float)code, 0.f);
		}

    };
}
