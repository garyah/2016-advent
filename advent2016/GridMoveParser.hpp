namespace Advent2016
{
	class GridMoveParser
	{
    public:
        GridMoveParser() :
            m_shortestPathDistance(0)
        {
        }

        void parse(char *input)
        {
            m_shortestPathDistance = 0;

            for (char *p = input; *p; ++p)
            {
                if (*p == 'L')
                {
                }
                else if (*p == 'R')
                {
                }
            }
        }

        int getShortestPathDistance()
        {
            return m_shortestPathDistance;
        }

    private:
        int m_shortestPathDistance;
    };
}
