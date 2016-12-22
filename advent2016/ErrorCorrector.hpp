#include <string>

namespace Advent2016
{
	class ErrorCorrector
	{
    public:
        ErrorCorrector() :
            m_corrected()
        {
        }

        void addMessage(const char *message)
        {
        }

        const char *getCorrected()
        {
            return m_corrected.c_str();
        }

    private:

    private:
        std::string m_corrected;
    };
}
