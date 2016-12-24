#include <stdio.h>

#include "../common/InputReader.hpp"
#include "../advent2016/RoomValidator.hpp"

using namespace Common;
using namespace Advent2016;

int main()
{
    RoomValidator validator;
    char *line = NULL;
    while ((line = InputReader::ReadLine()) != NULL)
    {
        validator.addRoom(line);
        (void)printf("name = %s id = %u\n", validator.getLastDecryptedName(), validator.getLastId());
    }
    return 0;
}
