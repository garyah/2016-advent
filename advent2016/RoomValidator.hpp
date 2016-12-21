#include <stdio.h>

namespace Advent2016
{
	class RoomValidator
	{
    public:
        RoomValidator() :
            m_sumOfIds(0)
        {
        }

        void addRoom(char *input)
        {
            //(void)sscanf(input, "%d %d %d", &side1, &side2, &side3);
            //m_sumOfIds += 888;
        }

        unsigned getSumOfIds()
        {
            return m_sumOfIds;
        }

    private:

    private:
        unsigned m_sumOfIds;
    };
}
