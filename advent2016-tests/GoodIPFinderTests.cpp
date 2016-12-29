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
            finder.findFirstGoodIP();
            Assert::AreEqual((float)3, (float)finder.getFirstGoodIP(), 0.f);
        }

        TEST_METHOD(GapAtStart)
        {
            GoodIPFinder finder;
            finder.addBlacklistRule("5-4294967295");
            finder.findFirstGoodIP();
            Assert::AreEqual((float)0, (float)finder.getFirstGoodIP(), 0.f);
        }

        TEST_METHOD(GapMiddle)
        {
            GoodIPFinder finder;
            finder.addBlacklistRule("0-4");
            finder.addBlacklistRule("4294967291-4294967295");
            finder.findFirstGoodIP();
            Assert::AreEqual((float)5, (float)finder.getFirstGoodIP(), 0.f);
        }

        TEST_METHOD(GapAtEnd)
        {
            GoodIPFinder finder;
            finder.addBlacklistRule("0-4294967290");
            finder.findFirstGoodIP();
            Assert::AreEqual((float)4294967291, (float)finder.getFirstGoodIP(), 0.f);
        }

        TEST_METHOD(NoGapsSameAsAllGood)
        {
            GoodIPFinder finder;
            finder.addBlacklistRule("0-4294967295");
            finder.findFirstGoodIP();
            Assert::AreEqual((float)0, (float)finder.getFirstGoodIP(), 0.f);
        }

    };
}
