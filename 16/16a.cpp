#include <stdio.h>

#include "../common/InputReader.hpp"
#include "../advent2016/ChecksumGenerator.hpp"

using namespace Common;
using namespace Advent2016;

int main()
{
    char *line = NULL;
    while ((line = InputReader::ReadLine()) != NULL)
    {
        ChecksumGenerator generator;
        generator.generate(line);
        (void)printf("%s\n", generator.getChecksum());
    }
    return 0;
}
