#include "stdafx.h"
#include "CppUnitTest.h"

#include "../advent2016/GoodIPFinder.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Advent2016;

namespace advent2016tests
{
    TEST_CLASS(GoodIPFinderTests)
    {
    public:

        TEST_METHOD(TestMethod20a1)
        {
            GoodIPFinder finder;
            finder.addBlacklistRule("5-8");
            finder.addBlacklistRule("0-2");
            finder.addBlacklistRule("4-7");
            Assert::AreEqual((float)3, (float)finder.getFirstGoodIP(), 0.f);
        }

    };
}
