#include <stdio.h>

namespace Advent2016
{
	class TriangleValidator
	{
    public:
        TriangleValidator() :
            m_numValidByRows(0)
        {
        }

        void addRow(char *input)
        {
            int side1 = -1, side2 = -1, side3 = -1;
            (void)sscanf(input, "%d %d %d", &side1, &side2, &side3);
            if (side1 >= 0 && side2 >= 0 && side3 >= 0)
            {
                if (side1 + side2 > side3
                    && side1 + side3 > side2
                    && side2 + side3 > side1)
                {
                    ++m_numValidByRows;
                }
            }
        }

        unsigned getNumValidByRows()
        {
            return m_numValidByRows;
        }

    private:

    private:
        unsigned m_numValidByRows;
    };
}
