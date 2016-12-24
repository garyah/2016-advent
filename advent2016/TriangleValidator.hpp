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
                if (isValidTriangle(static_cast<unsigned>(side1),
                    static_cast<unsigned>(side2),
                    static_cast<unsigned>(side3)))
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
        bool isValidTriangle(unsigned side1, unsigned side2, unsigned side3)
        {
            if (side1 + side2 > side3
                && side1 + side3 > side2
                && side2 + side3 > side1)
            {
                return true;
            }
            return false;
        }

    private:
        unsigned m_numValidByRows;
    };
}
