#include<stdio.h>
#include<string.h>
#include<errno.h>
#include"bmp.h"


int main(){
    
    FILE* fp = fopen("1.bmp", "rb");
    if(fp==NULL){
	printf("%s\n", strerror(errno));
	return -1;
    }

 	BITMAPFILEHEADER fileHeader;
 	if (readFile(fp, &fileHeader)) {
        printf("文件大小: %u 字节\n", fileHeader.bfSize);
        printf("数据偏移: %u 字节\n", fileHeader.bf0ffBits);
    } else {
        printf("读取BMP文件头失败\n");
    }
    
    
    BITMAPINFOHEADER infoHeader;
    if (readInfo(fp, &infoHeader)) {
        printf("宽: %d 像素\n", infoHeader.biWidth);
        printf("高: %d 像素\n", infoHeader.biHeight);
    } else {
        printf("读取BMP信息头失败\n");
    }
    
    
    return 0;
}


