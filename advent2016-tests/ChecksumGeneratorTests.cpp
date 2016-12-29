#include "stdafx.h"
#include "CppUnitTest.h"

#include "../advent2016/ChecksumGenerator.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Advent2016;

namespace advent2016tests
{		
    TEST_CLASS(ChecksumGeneratorTests)
    {
    public:
        
        TEST_METHOD(TestMethod16a1)
        {
            ChecksumGenerator generator;
            generator.generate("10000", 20);
            Assert::AreEqual("01100", generator.getChecksum());
        }

    };
}
