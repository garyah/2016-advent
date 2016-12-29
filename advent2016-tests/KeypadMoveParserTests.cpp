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
            parser.parseInstructionFor3x3("ULL");
            parser.parseInstructionFor3x3("RRDDD");
            parser.parseInstructionFor3x3("LURDL");
            parser.parseInstructionFor3x3("UUUUD");
            Assert::AreEqual((float)1985, (float)parser.getCode(), 0.f);
        }

        TEST_METHOD(TestMethod02b1)
        {
            KeypadMoveParser parser;
            parser.parseInstructionForDiamond("ULL");
            parser.parseInstructionForDiamond("RRDDD");
            parser.parseInstructionForDiamond("LURDL");
            parser.parseInstructionForDiamond("UUUUD");
            Assert::AreEqual((float)0, (float)parser.getCode(), 0.f);
        }

    };
}
