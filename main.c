
// MT, 2015oct23

//NDEBUG

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "Sha1.h"

#include "Sys.h"

int main(int const argc, char * const argv[])
{
    if(argc>1)
    {
		Sys_log_line(true, true, "Starting algorithm..");

        char const * const str = Sha1_create_string_from_path(argv[1]);

        Sys_log_line(true, true, "Algorithm done.");
		printf("\n");

        if(str!=NULL)
        {
            printf("%s\n", str);
        }
    }

    return EXIT_SUCCESS;
}
