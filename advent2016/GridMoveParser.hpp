#include <stdio.h>
#include <cmath>

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
            NumHeadings,
        } Heading;

        typedef enum
        {
            NotParsing = 0,
            Parsing,
        } ParseState;

    public:
        GridMoveParser() :
            m_x(0),
            m_y(0),
            m_heading(North),
            m_shortestPathDistance(0),
            m_parseState(NotParsing)
        {
        }

        void parse(char *input)
        {
            m_x = m_y = 0;
            m_heading = North;
            m_shortestPathDistance = 0;
            m_parseState = NotParsing;

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
                        if ('L' == *p) m_heading = static_cast<Heading>((m_heading - 1) % NumHeadings);
                        if ('R' == *p) m_heading = static_cast<Heading>((m_heading + 1) % NumHeadings);
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

    private:
        void updatePosition(int distance)
        {
            switch (m_heading)
            {
            case North:
                m_y += distance;
                break;
            case East:
                m_x += distance;
                break;
            case South:
                m_y -= distance;
                break;
            case West:
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
    };
}
