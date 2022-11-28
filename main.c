#include <stdio.h>

struct BITMAP_header {
    char name[2];
    unsigned int size;
    int garbage;
    unsigned int image_offset;
};
struct DIB_header {
    unsigned int header_size;
    unsigned int width;
    unsigned int height;
    unsigned int color_plane;
    unsigned int bit_per_pixel;
};
int main()
{
    FILE *file = fopen("C:\\Users\\admin\\CLionProjects\\bit\\bialy.bmp","rb");
    if (file == NULL)
        return NULL;
    struct BITMAP_header header;
    struct DIB_header dibheader;
    fread(header.name,2,1,file);
    fread(&header.size,3*sizeof(int),1,file);
//    fread(&header, sizeof(struct BITMAP_header), 1, file);
    fread(&dibheader,sizeof(struct DIB_header),  1, file);
    printf("Size %d\nWidth %d\nHeight %d\n",dibheader.header_size,dibheader.width,dibheader.height);
    fclose(file);
    return 0;
}
