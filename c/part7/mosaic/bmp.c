#include<stdio.h>
#include"bmp.h"
#include <stdbool.h>
//验证
bool readFile(FILE *fp, BITMAPFILEHEADER* header){
	if(fp==NULL||header==NULL){
		printf("文件指针或结构体指针为空\n");
		return false;
	}
	
	size_t bytesRead = fread(header, 1, sizeof(BITMAPFILEHEADER), fp);
	if(bytesRead != sizeof(BITMAPFILEHEADER))
		return false;
		
	if(header->bfType != 0x4D42){
		printf("无效的bmp文件\n");
		return false;
	}
	return true;
}


bool readInfo(FILE *fp, BITMAPINFOHEADER* info){
	if(fp==NULL||info==NULL) return false;
	if(fread(info, sizeof(BITMAPINFOHEADER), 1, fp)!=1) return false;
	
	if(info->biSize<40) return false;
	
	return true;
}


	
