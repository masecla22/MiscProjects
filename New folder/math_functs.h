
#include <iostream>
#include <cstring>

char strtchr(char a[255],string b)
{
    int i = b.length();
    int p=0;
    while(p<i)
    {
        a[p]=b[p];
        p++;
    }
    return 0;
}
