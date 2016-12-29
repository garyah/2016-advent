#include <stdio.h>
#include <map>

namespace Advent2016
{
    class GoodIPFinder
    {
        typedef std::map<unsigned, unsigned> RangeMap;

    public:
        GoodIPFinder() :
            m_rangeMap(),
            m_firstGoodIP(0)
        {
        }

        void addBlacklistRule(const char *rule)
        {
            unsigned start = 0, end = 0;
            (void)sscanf(rule, "%u-%u", &start, &end);
            m_rangeMap[start] = end;
        }

        void findFirstGoodIP()
        {
            m_firstGoodIP = 0;
            auto rangeIter = m_rangeMap.begin();
            if (rangeIter->first)
            {
                // gap at start includes first good
                return;
            }
            auto end = rangeIter->second;
            auto maxEnd = end;
            for (++rangeIter; end < UINT32_MAX && rangeIter != m_rangeMap.end(); ++rangeIter)
            {
                if (rangeIter->first > end + 1)
                {
                    // gap in middle includes first good
                    m_firstGoodIP = end + 1;
                    return;
                }
                end = rangeIter->second;
                if (end > maxEnd) { maxEnd = end; }
            }
            if (end >= UINT32_MAX)
            {
                // no gaps!  shouldn't happen, but it could
                return;
            }
            // gap at end includes first good
            m_firstGoodIP = end + 1;
        }

        unsigned getFirstGoodIP()
        {
            return m_firstGoodIP;
        }

    private:

    private:
        RangeMap m_rangeMap;
        unsigned m_firstGoodIP;
    };
}
