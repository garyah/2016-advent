#include <stdio.h>

#include "../common/InputReader.hpp"

using namespace Common;
//using namespace Advent2016;

int main()
{
	char *line = NULL;
	while ((line = InputReader::ReadLine()) != NULL)
	{
		// TODO: invoke class code here
		(void)printf("%s\n", line);
	}
	return 0;
}
