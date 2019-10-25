#include<iostream>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>

using namespace std;

#define PORT 3003
void die(char *error)
{
    perror(error);
    exit(1);
}
int main()
{
    char a[10],re[8],ch[2],chs;
    sockaddr_in server_addr,client_addr;
    int sock=socket(AF_INET,SOCK_STREAM,0);
    if(sock<0)
        die("Socket Creation Failed");
    
    bzero((char*)&server_addr,sizeof(server_addr));
    server_addr.sin_addr.s_addr=INADDR_ANY;
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=htons(PORT);

    if(bind(sock,(struct sockaddr*)&server_addr,sizeof(server_addr))<0)
        die("Binding failed");
    if(listen(sock,10)<0)
        die("Listen Failed");
    socklen_t socklen=sizeof(client_addr);

    int newSocket =accept(sock,(struct sockaddr*)&client_addr,&socklen);
    do{
        
    recv(newSocket, (char*)&a, sizeof(a), 0);
	recv(newSocket, (char*)&ch, sizeof(ch), 0);
	chs=ch[0];
	float angle = (float)atof(a);
	while(angle>=360)
	{
        	angle -= 360;
	}
	angle *= (3.14/180);
	float result;

	switch(chs)
	{
	case '1':result=sin(angle);
		break;
	case '2':result=cos(angle);
		break;
	case '3':result=tan(angle);
		break;
	case '4':result=1/tan(angle);
		break;
	case '5':result=1/cos(angle);
		break;
	case '6':result=1/sin(angle);
		break;
    }
    
    memset(re, '\0', 8);
	gcvt(result, 8, re);
    send(newSocket, re, sizeof(re), 0);
    
    }while(1);   
    

    return 0;
    

}

