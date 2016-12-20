#include <stdio.h>
#include <cmath>

namespace Advent2016
{
	class KeypadMoveParser
	{
    public:
        KeypadMoveParser() :
            //m_x(0),
            //m_y(0),
            m_code(0)
        {
        }

        void parseInstruction(char *input)
        {
            for (char *p = input; *p; ++p)
            {
            }
        }

        unsigned getCode()
        {
            return m_code;
        }

    private:
        //unsigned YYY()
        //{
        //    return YYY;
        //}

    private:
        //int m_x, m_y;
        unsigned m_code;
    };
}
