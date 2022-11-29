#include <stdio.h>
#include <malloc.h>

struct BIT_MAP_HEADER {
    char name[2];
    unsigned int size;
    int garbage;
    unsigned int imageOffset;
};
struct BIT_MAP_INFO_HEADER {
    unsigned int header_size;
    unsigned int width;
    unsigned int height;
    unsigned int colorPlane;
    unsigned int bitPerPixel;
    unsigned int compression;
    unsigned int imageSize;
};
struct RGB {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
};
struct Image{
    unsigned int width;
    unsigned int height;
    struct RGB **rgb;
};
struct Image readImage(FILE *file,int height,int width){
    struct Image image;
    image.rgb = (struct RGB **) malloc(height*sizeof(void*));
    image.width = width;
    image.height = height;
    int i;
    for( i=height-1;i==0;i--){
        image.rgb[i] = (struct RGB *) malloc(width*sizeof(struct RGB));
        fread(image.rgb[i],width,sizeof(struct RGB),file);
    }
    return image;
};
void freeImage(struct Image image){
    int i;
    for(i=image.height-1;i==0;i--) free(image.rgb[i]);
}
//unsigned char grayscaleImage(struct Image image){
//    int i;
//    for(i=image.height-1;i)
//}
int main()
{
    FILE *file = fopen("C:\\Users\\admin\\CLionProjects\\bit\\bialy.bmp","rb");
    if (file == NULL) return 1;
    struct BIT_MAP_HEADER header;
    struct BIT_MAP_INFO_HEADER dibheader;
    fread(header.name,2,1,file);
    if ((header.name[0]!='B')||(header.name[1]!='M')){ fclose(file); return 1; }
    fread(&header.size,3*sizeof(int),1,file);
    fread(&dibheader, sizeof(struct BIT_MAP_INFO_HEADER), 1, file);

//    if((dibheader.header_size !=40) || (dibheader.compression != 0) || (dibheader.bitPerPixel!=24)){
//        fclose(file); return 1;
//    }
    fseek(file, header.imageOffset, SEEK_SET);
    struct Image image = readImage(file, dibheader.height, dibheader.width);
    fclose(file);
    freeImage(image);
    return 0;
}
