#include <stdio.h>
#include <ctype.h>
#include <map>

namespace Advent2016
{
	class RoomValidator
	{
        typedef std::map<char, unsigned> CountMap;
        typedef std::map<unsigned, std::string> LettersMap;

    public:
        RoomValidator() :
            m_sumOfIds(0)
        {
        }

        void addRoom(char *input)
        {
            char roomName[1000] = { 0 };
            int id = -1;
            char roomChecksum[1000] = { 0 };
            (void)sscanf(input, "%999[-abcdefghijklmnopqrstuvwxyz]%u[%999[abcdefghijklmnopqrstuvwxyz]]", roomName, &id, roomChecksum);
            if (id >= 0)
            {
                auto result = calculateChecksum(roomName);
                if (0 == result.compare(roomChecksum))
                {
                    m_sumOfIds += static_cast<unsigned>(id);
                }
            }
        }

        unsigned getSumOfIds()
        {
            return m_sumOfIds;
        }

    private:
        std::string calculateChecksum(const char *roomName)
        {
            CountMap countMap;
            for (auto p = roomName; *p; ++p)
            {
                if (islower(*p)) { countMap[*p]++; }
            }
            LettersMap lettersMap;
            for (auto i = countMap.begin(); i != countMap.end(); ++i)
            {
                lettersMap[i->second].append(1, i->first);
            }
            std::string result;
            for (auto i = lettersMap.rbegin(); i != lettersMap.rend(); ++i)
            {
                result.append(i->second);
            }
            return result.substr(0, 5);
        }

    private:
        unsigned m_sumOfIds;
    };
}
