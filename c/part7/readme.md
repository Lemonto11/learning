# 标准IO常用函数

## fopen/ fclose
FILE *fopen(const char *pathname, const char *mode);

       r      Open text file for reading.  The stream is positioned at the beginning of the file.

       r+     Open for reading and writing.  The stream is positioned at the beginning of the file.

       w      Truncate  file  to  zero length or create text file for writing.  The stream is positioned at the beginning of the file.

       w+     Open for reading and writing.  The file is created if it does not exist, otherwise it is truncated.  The stream is positioned at the beginning of the file.

       a      Open  for appending (writing at end of file).  The file is created if it does not exist.  The stream is positioned at the end of the file.

       a+     Open for reading and appending (writing at end of file).  The file is created  if  it does  not  exist.  Output is always appended to the end of the file.  POSIX is silent on what the initial read position is when using this mode.  For  glibc,  the  initial file position for reading is at the beginning of the file, but for Android/BSD/MacOS, the initial file position for reading is at the end of the file.



int fclose(FILE *stream);


## fgetc 

int fgetc(FILE *stream);

char *fgets(char *s, int size, FILE *stream);

int getchar(void);


## fputc


## fread/ fwrite
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
	ptr:存放读取的字符串的字符数组， buf[SIZE]
	nmemb:读取的字符数 SIZE-1 / strlen(buf)
	返回值：成功返回读取到的字符个数 失败或到文件末尾返回0
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
	ptr:要写入的字符串的字符数组， str[]="hello\n"
	nmemb:要写入的字符数  strlen(str)
	返回值：成功返回写入的字符个数==size为1时的nmemb, 失败或到文件末尾返回0
