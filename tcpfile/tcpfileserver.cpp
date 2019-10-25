#include<iostream>
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<fstream>

using namespace std;
# define PORT 8000
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
        die("Socket Creation Failed");
    else
        cout<<"Socket Created Successfully"<<endl;
    bzero((char*)&server_addr,sizeof(server_addr));
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=INADDR_ANY;
    server_addr.sin_port=htons(PORT);

    if(bind(sock,(struct sockaddr*)&server_addr,sizeof(server_addr))<0)
        die("Binding Failed");
    else
        cout<<"Binding Successful"<<endl;
    if(listen(sock,10)<0)
        die("Listen Failed");
    else
        cout<<"Listen Successful"<<endl;
    socklen_t socklen=sizeof(client_addr);
    int newSocket=accept(sock,(struct sockaddr*)&client_addr,&socklen);
    if(newSocket<0)
        die("Accept Error");
    else
        cout<<"Accept Successful"<<endl;
    long long int msg_len;
    {
        cout<<"Enter Filename"<<endl;
        char filename[100];
        cin>>filename;
        fstream fout;

        msg_len=send(newSocket,filename,100,0);
        if(msg_len<0)
            die("Filename Error");
        fout.open(filename,ios::in|ios::out|ios::binary);
            fout.seekg(0,ios::end);
            long long int filesize=fout.tellg();
            char* filebuff=new char[filesize];
            fout.seekg(0,ios::beg);
            fout.read(filebuff,filesize);
            msg_len=send(newSocket,filebuff,filesize,0);
            if(msg_len<0)
                die("Transmission Failed");
            else
                cout<<"Transmission Successful"<<endl;
            fout.close();        
    }
    return 0;

    

}