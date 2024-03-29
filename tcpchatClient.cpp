#include<iostream>
#include <sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

using namespace std;

#define PORT 3207
#define SERVER_ADDRESS "127.0.0.1"

void die(char *error)
{
    perror(error);
    exit(1);
}

int main()
{
    struct sockaddr_in server_addr;
    int sock=socket(AF_INET,SOCK_STREAM,0);
    if(sock<0)
        cout<<"Server couldn't be created"<<endl;
    else
        cout<<"Server created successfully"<<endl;
    server_addr.sin_addr.s_addr=inet_addr(SERVER_ADDRESS);
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=htons(PORT);

    int status=connect(sock,(struct sockaddr*)&server_addr,sizeof(server_addr));
    if(status==0)
        cout<<"Connect Success";
    else
        cerr<<"connect"<<endl;
    char buffer[256];
    while(1)
    {
        bzero((char*)buffer,256);
            cout<<">";
            string data;
            getline(cin,data);
            strcpy(buffer,data.c_str());
        send(sock,buffer,strlen(buffer),0);
        bzero(buffer,256);
        cout<<"Awaiting Server Response"<<endl;
        recv(sock,(char*)&buffer,sizeof(buffer),0);
        cout<<"Server: "<<buffer<<endl;
    }
    return 0;
    
}