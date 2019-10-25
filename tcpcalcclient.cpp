#include<iostream>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>

using namespace std;

#define PORT 3003
#define SERVER_ADDRESS "127.0.0.1"
void die(char *error)
{
    perror(error);
    exit(1);
}
int main()
{


    char a[5],ch[2],result[8];
    sockaddr_in server_addr;
    int sock=socket(AF_INET,SOCK_STREAM,0);
    if(sock<0)
        die("Socket Creation failed");
    server_addr.sin_addr.s_addr=inet_addr(SERVER_ADDRESS);
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=htons(PORT);

    int status=connect(sock,(struct sockaddr*)&server_addr,sizeof(server_addr));
    if(status<0)
        die("Connect Failed");
    else    
        cout<<"Connect Successful"<<endl;

    do{
        cout<<"Enter angle in degrees : "<<endl;
        cin>>a;
        send(sock,(char *)&a,sizeof(a),0);
        cout<<"Enter \n1)Sine \n2)Cosine \n3)Tan \n4)Cot \n5)Sec \n6)Cosec"<<endl;
        cin>>ch;
        send(sock,(char *)&ch,sizeof(ch),0);
        recv(sock, (char*)&result, sizeof(result), 0);
        cout<<result<<endl;

    }while(ch!=0);
    return 0;

}