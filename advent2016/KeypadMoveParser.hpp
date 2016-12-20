#include <stdio.h>
#include <algorithm>

namespace Advent2016
{
	class KeypadMoveParser
	{
    public:
        KeypadMoveParser() :
            m_x(0),
            m_y(0),
            m_code(0)
        {
        }

        void parseInstruction(char *input)
        {
            for (char *p = input; *p; ++p)
            {
                if ('U' == *p) m_y = std::min(m_y + 1, 1);
                if ('D' == *p) m_y = std::max(m_y - 1, -1);
                if ('L' == *p) m_x = std::max(m_x - 1, -1);
                if ('R' == *p) m_x = std::min(m_x + 1, 1);
            }
            m_code *= 10;
            if (-1 == m_x)
            {
                if (1 == m_y) m_code += 1;
                if (0 == m_y) m_code += 4;
                if (-1 == m_y) m_code += 7;
            }
            if (0 == m_x)
            {
                if (1 == m_y) m_code += 2;
                if (0 == m_y) m_code += 5;
                if (-1 == m_y) m_code += 8;
            }
            if (1 == m_x)
            {
                if (1 == m_y) m_code += 3;
                if (0 == m_y) m_code += 6;
                if (-1 == m_y) m_code += 9;
            }
        }

        unsigned getCode()
        {
            return m_code;
        }

    private:
        int m_x, m_y;
        unsigned m_code;
    };
}
