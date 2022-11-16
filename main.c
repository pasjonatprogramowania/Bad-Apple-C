#include <stdio.h>

int main()
{
    FILE* file = fopen("plik.txt","r");
    if (file == NULL)
        return NULL;
    printf("e");
    return 0;
}
