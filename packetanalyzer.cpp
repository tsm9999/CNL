#include"bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
    int count,i,choice;

    string no,time,source,destination,protocol,length,info;
    string pC;

    do
    {
        ifstream file("11.csv");
        count=-1;
        i=0;
        cout<<"1. IP\n2. UDP\n3. TCP\n4. ARP\n5. EXIT"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1:
                pC= "\"ICMP\"";   // "   \"UDP\"     "
                break;
            case 2: 
                pC= "\"UDP\"";
                break;
            case 3:
                pC="\"TCP\"";
                break;
            case 4:
                pC="\"ARP\"";
                break;
            
        }  

        while(file.good())
    {
        getline(file,no,',');
        getline(file,time,',');
        getline(file,source,',');
        getline(file,destination,',');
        getline(file,protocol,',');
        getline(file,length,',');
        getline(file,info,',');

        if(protocol ==pC ||protocol =="Protocol")
        {
            cout<<setw(4)<<left<<i++;
            cout<<setw(12)<<left<<string(time,1,time.length()-2);
            cout<<setw(30)<<left<<string(source,1,source.length()-2);
            cout<<setw(30)<<left<<string(destination,1,destination.length()-2);
            cout<<setw(8)<<left<<string(protocol,1,protocol.length()-2);
            cout<<setw(8)<<left<<string(length,1,length.length()-2);
            cout<<string(info,1,info.length()-2);
            cout<<endl;
            count++;
        }  
    }        
    
    file.close();
    cout<<"Count: "<<count<<endl;
    }while (choice!=5);
    
        return 0;  
    
    
}