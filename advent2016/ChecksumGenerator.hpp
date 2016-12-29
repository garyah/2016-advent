#include <string>

namespace Advent2016
{
    class ChecksumGenerator
    {
    public:
        ChecksumGenerator() :
            m_checksum()
        {
        }

        void generate(const char *startData, size_t targetLength = 272)
        {
        }

        const char *getChecksum() const
        {
            return m_checksum.c_str();
        }

    private:

    private:
        std::string m_checksum;
    };
}
