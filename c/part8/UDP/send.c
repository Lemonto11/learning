#include<stdio.h>
#include<sys/stat.h>
#include<fctrl.h>


int main(){
	//创建套接字
	int sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock<0){
		perror("socket");
		return -1;
	}
	
	//绑定地址
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9876);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	int ret = bind(fd, (struct sockaddr*)&addr, sizeof(addr));
	if(ret==-1){
		perror("bind");
		return -1;
	}
	
    return 0;
}


