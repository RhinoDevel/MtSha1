
// MT, 2015oct26

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
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

char* Sys_get_time_str(bool const inDate, bool const inSeconds)
{
    char* retVal = NULL;
    time_t t = time(NULL);
    struct tm const * const l = localtime(&t);
    size_t const dateLen = 11,
        timeLen = 5;
    size_t len = timeLen+1, // 23:59 and '\0'
        pos = 0;

    if(inDate)
    {
        len += dateLen; // 2016/03/20-
    }
    if(inSeconds)
    {
        len += 3; // :59
    }

    size_t const byteLen = len*(sizeof *retVal);

    retVal = malloc(byteLen);
    assert(retVal!=NULL);

    if(inDate)
    {
        snprintf(retVal+pos, byteLen-pos, "%d/%02d/%02d-", l->tm_year+1900, l->tm_mon+1, l->tm_mday);

        pos += dateLen;
    }

    snprintf(retVal+pos, byteLen-pos, "%02d:%02d", l->tm_hour, l->tm_min);
    pos += timeLen;

    if(inSeconds)
    {
        snprintf(retVal+pos, byteLen-pos, ":%02d", l->tm_sec);
    }

    return retVal;
}
