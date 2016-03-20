
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
        printf("%s - Starting algorithm..\n", Sys_get_time_str(true, true));

        char const * const str = Sha1_create_string_from_path(argv[1]);

        printf("%s - Algorithm done.\n\n", Sys_get_time_str(true, true));

        if(str!=NULL)
        {
            printf("%s\n", str);
        }
    }

    return EXIT_SUCCESS;
}
