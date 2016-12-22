#include "stdafx.h"
#include "CppUnitTest.h"

#include "../advent2016/ViableNodePairCounter.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Advent2016;

namespace advent2016tests
{		
	TEST_CLASS(ViableNodePairCounterTests)
	{
	public:
		
		TEST_METHOD(TestMethod22a1)
		{
            ViableNodePairCounter counter;
            counter.addNode("/dev/grid/node-x0-y0     92T   68T    24T   73%");
            counter.countViable();
            Assert::AreEqual((float)10, (float)counter.getNumViable(), 0.f);
		}

    };
}
