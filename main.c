#include <stdio.h>

int main()
{
    FILE* file = fopen("bialy.bmp","rb");
    if (file == NULL)
        return NULL;
    printf("e");
    return 0;
}
