#include<iostream>
#include <sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;
#define PORT 3207


void die(char *error)
{
    perror(error);
    exit(1);
}

int main()
{
    sockaddr_in server_addr,client_addr;
    int sock=socket(AF_INET,SOCK_STREAM,0);
    if(sock<0)
        cerr<<"SOcket creation error"<<endl;
    else
        cout<<"Socket Created Successfully"<<endl;
    
   bzero((char *)&server_addr,sizeof(server_addr));
        server_addr.sin_family=AF_INET;
        server_addr.sin_addr.s_addr=INADDR_ANY;
        server_addr.sin_port=htons(PORT);

   if(bind(sock,(sockaddr*)&server_addr,sizeof(server_addr))==-1)
		die("ERROR IN BINDING");

    if(listen(sock,10)<0)
        cerr<<"Error in Listening";
    socklen_t socklen=sizeof(client_addr);
    int newSocket=accept(sock,(struct sockaddr*)&client_addr,&socklen);
    char buffer[256];

    while(1)
    {
        cout<<"Awaiting For Response"<<endl;
        bzero(buffer,256);
        recv(newSocket,buffer,255,0);
        cout<<"Client: "<<buffer<<endl;
        cout<<">";
        string data;
        getline(cin,data);
        bzero(buffer,256);
        strcpy(buffer,data.c_str());

                fflush(stdin);
        send(newSocket,(char*)&buffer,strlen(buffer),0);

    }

    return 0;
}
