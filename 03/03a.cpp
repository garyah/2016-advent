#include <stdio.h>

#include "../common/InputReader.hpp"
#include "../advent2016/TriangleValidator.hpp"

using namespace Common;
using namespace Advent2016;

int main()
{
    TriangleValidator validator;
    char *line = NULL;
	while ((line = InputReader::ReadLine()) != NULL)
	{
        validator.addTriangle(line);
    }
    (void)printf("%u\n", validator.getNumValid());
    return 0;
}
