#include<stdio.h>


int main(){

	//fopen
	FILE* fp = fopen("basic.c", "r+");
	
	//getchar()
	char c;
	while((c=getchar())!='\n'){
		printf("%c", c);
	}
	printf("\n");
	
	//fgetc()
	char ch;
	while((ch = fgetc(fp))!=EOF){
		printf("%c", ch);
	}
	printf("\n");
	//fclose
	fclose(fp);
    return 0;
}


