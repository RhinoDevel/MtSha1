
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
        FILE* filePtr = fopen(argv[1], "rb");

        if(filePtr!=NULL)
        {
            unsigned char * const sha1Ptr = Sha1_create_from_file(filePtr);

            fclose(filePtr);
            filePtr = NULL;

            if(sha1Ptr!=NULL)
            {
                Sha1_print(sha1Ptr);
                printf("\n");
            }

            free(sha1Ptr);
        }
    }

    return EXIT_SUCCESS;
}
