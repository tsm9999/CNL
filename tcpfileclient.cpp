#include<iostream>
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<fstream>

#define PORT 8000
#define SERVER_ADDRESS "127.0.0.1"


using namespace std;
void die(char *error)
{
	perror(error);
	exit(1);
}
int main()
{
    sockaddr_in server_addr;
    int sock=socket(AF_INET,SOCK_STREAM,0);
    if(sock<0)
        die("Socket Creation Failed");
    else
        cout<<"Socket Created Successfully"<<endl;
    bzero((char*)&server_addr,sizeof(server_addr));
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=inet_addr(SERVER_ADDRESS);
    server_addr.sin_port=htons(PORT);

    int status =connect(sock,(struct sockaddr *)&server_addr,sizeof(server_addr));
    if(status<0)
        die("Connect Error");
    else
        cout<<"Connect Successful"<<endl;
    long long int msg_len;
    char buffer[256];
    {
        cout<<"Waiting for server to send filename"<<endl;
        char filename[100];
        bzero((char*)&filename,sizeof(filename));
        msg_len=recv(sock,filename,100,0);
        if(msg_len<0)
            die("Filename Error");
        else   
            cout<<"Filename: "<<filename<<endl;
        char *filebuf=new char[90000*80];
        bzero((char*)&filebuf,sizeof(filebuf));
        msg_len=recv(sock,filebuf,90000*80,0);
        ofstream fout;
        fout.open(filename,ios::out|ios::binary);
        if(!fout)
            die("Can't create file");
        else
        {
            fout.write(filebuf,msg_len);
            fout.close();
            cout<<"File Received";
        }   
    }
    return 0;
}