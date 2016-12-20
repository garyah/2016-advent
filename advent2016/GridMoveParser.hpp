#include <stdio.h>
#include <cmath>
#include <map>

namespace Advent2016
{
	class GridMoveParser
	{
        typedef enum
        {
            North = 0,
            East,
            South,
            West,
        } Heading;

        typedef enum
        {
            NotParsing = 0,
            Parsing,
        } ParseState;

        typedef std::pair<int, int> Point;
        typedef std::pair<Point, bool> PointEntry;
        typedef std::map<Point, bool> PointMap;

    public:
        GridMoveParser() :
            m_x(0),
            m_y(0),
            m_heading(North),
            m_shortestPathDistance(0),
            m_parseState(NotParsing),
            m_pointMap(),
            m_distanceToFirstRevisit(0),
            m_gotFirstRevisit(false)
        {
            Point point(m_x, m_y);
            PointEntry entry(point, true);
            (void)m_pointMap.insert(entry);
        }

        void parse(char *input)
        {
            char *numberToParse = nullptr;
            for (char *p = input; ; ++p)
            {
                auto willBreak = false;
                if (0 == *p)
                {
                    willBreak = true;
                }
                if (NotParsing == m_parseState)
                {
                    if ('L' == *p || 'R' == *p)
                    {
                        numberToParse = p + 1;
                        if ('L' == *p) m_heading = static_cast<Heading>(((unsigned)m_heading - 1) % (West + 1));
                        if ('R' == *p) m_heading = static_cast<Heading>(((unsigned)m_heading + 1) % (West + 1));
                        m_parseState = Parsing;
                    }
                }
                if (Parsing == m_parseState)
                {
                    if (',' == *p || 0 == *p)
                    {
                        *p = 0;
                        int parsedNumber = -1;
                        (void)sscanf(numberToParse, "%d", &parsedNumber);
                        if (parsedNumber >= 0)
                        {
                            updatePosition(parsedNumber);
#ifdef TEST_DEBUG
                            (void)printf("%s, heading=%s, x=%d, y=%d, distance=%u\n", numberToParse - 1, headingToString(), m_x, m_y, m_shortestPathDistance);
#endif
                        }
                        m_parseState = NotParsing;
                    }
                }
                if (willBreak)
                {
                    break;
                }
            }
        }

        unsigned getShortestPathDistance()
        {
            return m_shortestPathDistance;
        }

        unsigned getDistanceToFirstRevisit()
        {
            return m_distanceToFirstRevisit;
        }

    private:
        void updatePosition(int distance)
        {
            switch (m_heading)
            {
            case North:
                for (int y = m_y + 1; y <= m_y + distance && !m_gotFirstRevisit; ++y)
                {
                    auto beforeSize = m_pointMap.size();
                    Point point(m_x, y);
                    PointEntry entry(point, true);
                    (void)m_pointMap.insert(entry);
                    if (beforeSize == m_pointMap.size())
                    {
                        m_distanceToFirstRevisit = std::abs(point.first) + std::abs(point.second);
                        m_gotFirstRevisit = true;
                    }
                }
                m_y += distance;
                break;
            case East:
                for (int x = m_x + 1; x <= m_x + distance && !m_gotFirstRevisit; ++x)
                {
                    auto beforeSize = m_pointMap.size();
                    Point point(x, m_y);
                    PointEntry entry(point, true);
                    (void)m_pointMap.insert(entry);
                    if (beforeSize == m_pointMap.size())
                    {
                        m_distanceToFirstRevisit = std::abs(point.first) + std::abs(point.second);
                        m_gotFirstRevisit = true;
                    }
                }
                m_x += distance;
                break;
            case South:
                for (int y = m_y - 1; y >= m_y - distance && !m_gotFirstRevisit; --y)
                {
                    auto beforeSize = m_pointMap.size();
                    Point point(m_x, y);
                    PointEntry entry(point, true);
                    (void)m_pointMap.insert(entry);
                    if (beforeSize == m_pointMap.size())
                    {
                        m_distanceToFirstRevisit = std::abs(point.first) + std::abs(point.second);
                        m_gotFirstRevisit = true;
                    }
                }
                m_y -= distance;
                break;
            case West:
                for (int x = m_x - 1; x >= m_x - distance && !m_gotFirstRevisit; --x)
                {
                    auto beforeSize = m_pointMap.size();
                    Point point(x, m_y);
                    PointEntry entry(point, true);
                    (void)m_pointMap.insert(entry);
                    if (beforeSize == m_pointMap.size())
                    {
                        m_distanceToFirstRevisit = std::abs(point.first) + std::abs(point.second);
                        m_gotFirstRevisit = true;
                    }
                }
                m_x -= distance;
                break;
            default:
                break;
            }
            m_shortestPathDistance = std::abs(m_x) + std::abs(m_y);
        }

#ifdef TEST_DEBUG
        const char *headingToString()
        {
            switch (m_heading)
            {
            case North:
                return "North";
            case East:
                return "East";
            case South:
                return "South";
            case West:
                return "West";
            default:
                return "unknown";
            }
        }
#endif

    private:
        int m_x, m_y;
        Heading m_heading;
        unsigned m_shortestPathDistance;
        ParseState m_parseState;
        PointMap m_pointMap;
        unsigned m_distanceToFirstRevisit;
        bool m_gotFirstRevisit;
    };
}
