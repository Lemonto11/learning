#include<stdio.h>

#define SIZE 512
int main(){

	//fopen
	FILE* fp = fopen("text.txt", "r+");
	if(fp==NULL){
		perror("fopen");
		return -1;
	}
	//getchar()
	printf("--------getchar-------\n");
	char c;
	while((c=getchar())!='\n'){
		printf("%c", c);
	}
	printf("\n");
	
	//fgetc()
	printf("--------fgetc-------\n");
	char ch;
	while((ch = fgetc(fp))!=EOF){
		printf("%c", ch);
	}
	printf("\n");
	
	//fgets(char *s, int size, FILE* stream)
	printf("--------fgets-------\n");
	rewind(fp);
	char buf[SIZE];
	int line = 0;
	while(fgets(buf, SIZE, fp)!=NULL){
		line++;
		printf("%s", buf);
	}
	printf("一共有%d行\n", line);
	
	//fputs(const char *s, FILE* stream)
	printf("--------fputs-------\n");
	if(fputs("susususupernova", fp)==EOF){
		perror("fputs");
	}
	printf("写入susususupernova\n");
	
	//fread(void* ptr, size_t size, size_t num, FILE* Stream)
	printf("--------fread-------\n");
	fseek(fp, 0, SEEK_SET);
	char buffer[SIZE]={0};
	size_t ret = fread(buffer, 1, SIZE-1, fp);
	if(!ret){
		perror("fread");
		return -1;
	}
	buffer[SIZE]='\0';
	printf("%s", buffer);
	printf("\n");
	
	//fclose
	fclose(fp);
    return 0;
}
