#include <string>

namespace Advent2016
{
	class ViableNodePairCounter
	{
    public:
        ViableNodePairCounter() :
            m_numViable(-1)
        {
        }

        void addNode(const char *input)
        {
            std::string inputStr(input);
            if (inputStr.find("/dev/grid/") == std::string::npos) return;
        }

        void countViable()
        {
        }

        unsigned getNumViable()
        {
            return m_numViable;
        }

    private:

    private:
        unsigned m_numViable;
    };
}
