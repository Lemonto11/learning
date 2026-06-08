#ifndef BMP_H
#define BMP_H

#include <stdbool.h>
#pragma pack(push,1)
//文件头
typedef struct {
    unsigned short bfType;
    unsigned int   bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int   bf0ffBits;
}BITMAPFILEHEADER;

// 信息头（40字节）
typedef struct {
	unsigned int biSize;
	int          biWidth;
	int 		 biHeight;
	unsigned short biPlanes; 	
} BITMAPINFOHEADER;

#pragma pack(pop)


// 存储BMP图像数据的结构体
typedef struct {
    int width;
    int height;
    int rowSize;          // 每行实际字节数（含填充）
    int pixelDataSize;    // 像素数据总大小
    unsigned char* pixels; // 像素数据（BGR顺序）
    int isTopDown;        // 是否为自上而下存储（biHeight为负数）
} BMPImage;
bool readFile(FILE *fp, BITMAPFILEHEADER *header);
bool readInfo(FILE *fp, BITMAPINFOHEADER* info);


#endif

