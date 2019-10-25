#include"bits/stdc++.h"
using namespace std;

int main()
{
    int data[10],datarec[10],i,c1,c2,c3,c;

    cout<<"Enter data bits"<<endl;
    cin>>data[4];
    cin>>data[2];
    cin>>data[1];
    cin>>data[0];

    data[6]=data[0]^data[2]^data[4];
    data[5]=data[0]^data[1]^data[4];
    data[3]=data[0]^data[1]^data[2];


    cout<<"DataWord Sent is:  ";
    for(i=6;i>=0;i--)
        cout<<data[i];

    cout<<endl<<"Enter Received Data Word"<<endl;
    for(i=6;i>=0;i--)
        cin>>datarec[i];

    c1=datarec[6]^datarec[4]^datarec[2]^datarec[0];
    c2=datarec[5]^datarec[4]^datarec[1]^datarec[0];
    c3=datarec[3]^datarec[2]^datarec[1]^datarec[0];
    c=c3*4+c2*2+c1;

    if(c==0)
        cout<<"No Error"<<endl;
    else

    {
    cout<<"Error Present"<<endl;

    cout<<"Data Sent is:";
    for(i=6;i>=0;i--)
        cout<<data[i];

    cout<<endl<<"Data Received is:" ;
    for(i=6;i>=0;i--)
        cout<<datarec[i];

    cout<<"Correct Message is: ";
    if(datarec[7-c]==0)
        datarec[7-c]=1;
    else
        datarec[7-c]=0;

    for(i=6;i>=0;i--)
        cout<<endl<<datarec[i];
    }
    return 0;
        

}