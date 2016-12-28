#include "../advent2016/HashInputGenerator.hpp"

namespace Advent2016
{
    class PasswordGenerator
    {
    public:
        PasswordGenerator() :
            m_password()
        {
        }

        void generateInOrder(const char *doorId)
        {
            HashInputGenerator generator;
            unsigned index = 0;
            for (int i = 0; i < 8; ++i)
            {
                generator.generate(doorId, index);
                index = generator.getHashInputDecimal() + 1;
                m_password.append(1, *(generator.getHashOutputString() + 5));
            }
        }

        void generateByPosition(const char *doorId)
        {
            HashInputGenerator generator;
            unsigned index = 0;
            //for (int i = 0; i < 8; ++i)
            //{
            //    generator.generate(doorId, index);
            //    index = generator.getHashInputDecimal() + 1;
            //    m_password.append(1, *(generator.getHashOutputString() + 5));
            //}
        }

        const char *getPassword() const
        {
            return m_password.c_str();
        }

    private:

    private:
        std::string m_password;
    };
}
