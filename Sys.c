
// MT, 2015oct26

#include <assert.h>

#include "Sys.h"

bool Sys_is_big_endian()
{
    assert(sizeof(unsigned int)==4);

    union
    {
        unsigned int uI;
        unsigned char uC[4];
    } u = { 0x01020304 };

    return u.uC[0]==1;
}
