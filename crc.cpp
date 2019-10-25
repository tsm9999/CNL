/*
Write a program in C/C++  for error detection and correction for 7/8 bits ASCII codes using Hamming Codes or CRC. 
Demonstrate the packets captured traces using Wireshark Packet Analyzer Tool.


Steps: 
1.Take input data from user.(character ASCII code)
2.Take the generator from the user.
2.Convert the input into binary(based on ASCII code < 128 )
3.Append zero's at the end.
4.Perform the and operation and the get the additional bits
5.Append it to the input data.(Final encoded binary string).
6.Display the output.
7.Ask user to enter the another input(encoded one) for verification.
8.Use the same generator to verify . 
9.Print correct or not.
10.End
*/

#include<iostream>
#include <bits/stdc++.h> 

using namespace std;

int main(){
    int choice;
    string input_binary;
    cout << "Enter data in\n" << "1.Binary\n" << "2.ASCII\n";
    cin >> choice;
    if(choice == 1 ){
        cin.ignore(1);
        cout << "Enter the data(in Binary):";
        getline(cin,input_binary);
    }else if(choice == 2){
        char input_data;
        cout << "Enter the data(in ASCII) :";
        cin >> input_data;
        cin.ignore(1);
        if(int(input_data) < 128){
            bitset<7> temp(input_data);
            input_binary = temp.to_string();
        }
        else{
            bitset<8> temp(input_data);
            input_binary = temp.to_string();
        }
    }

    string generator;
    cout << "Enter the generator :";        
    getline(cin,generator);
    string encoded = "";
    encoded = encoded + input_binary;
    int n = input_binary.length() , k = generator.length();
    int i,j;
    for(i = 0 ; i < k - 1 ; i++){
        encoded = encoded + '0';
    }
    cout << "Data : " << input_binary << endl;
    for(i = 0 ; i < encoded.length() - k +1 ; ){
        for(j = 0 ; j < k ; j++){
            encoded[i+j] = encoded[i+j] == generator[j] ? '0':'1';
        }
        for( ; i < encoded.length() && encoded[i]!='1' ; i++);
    }
    cout << "Encoded string : " << input_binary + encoded.substr(encoded.length() - k +1)  << endl;

    //verification
    string encoded_string;
    cout << "Enter the encoded string to verify :";
    getline(cin,encoded_string);
    for(i = 0 ; i < encoded_string.length() - k +1 ; ){
        for(j = 0 ; j < k ; j++){
            encoded_string[i+j] = encoded_string[i+j] == generator[j] ? '0':'1';
        }
        for( ; i < encoded_string.length() && encoded_string[i]!='1' ; i++);
    }
    for(i = encoded_string.length() - k +1 ; i < encoded_string.length() ; i++){
        if(encoded_string[i]!='0'){
            cout << "Error in transmission!\n";
            return 0;
        }
    }
    cout << "Transmission successful!\n";
}