#include <bits/stdc++.h>
using namespace std;
#ifndef AffineCipher_LIBRARY_H
#define AffineCipher_LIBRARY_H

int a,b,c,user_choice;
string message;
void take_letter_AffineCipher(){
    if(user_choice == 1){
        cout<<"Please enter the message to cipher: ";
    }else{
        cout<<"Please enter the message to decipher: ";
    }
    message = "";
    while (message.empty()){
        getline(cin,message);
    }
    transform(message.begin(),message.end(),message.begin(),::toupper);
}

void take_numbers_AffineCipher(){
    cout<<"Enter a number: ";
    cin>>a;
    cout<<"Enter b number: ";
    cin>>b;
    cout<<"Enter c number: ";
    cin>>c;
    while ((a*c)%26!=1 || a<0 || b<0 || c<0){
        cout<<"Please enter positive numbers and (a * c) mod 26 = 1.\n";
        take_numbers_AffineCipher();
    }
}

void take_choice_AffineCipher(){
    cout<<"What do you want to do today?\n";
    cout<<"1- Cipher \n";
    cout<<"2- Decipher \n";
    cout<<"3- End \n";
    cin>>user_choice;
    while (user_choice>3 || user_choice<1){
        cout<<"Enter correct number/\n";
        take_choice_AffineCipher();
    }
}

int cipher_equation_AffineCipher(char tmp){
    return (a*(tmp-'A')+b)%26;
}

int decipher_equation_AffineCipher(char tmp){
    return c*((tmp-'A') -b +26)%26;
}

void cipher_AffineCipher(){
    for (int i = 0; i < message.size(); ++i) {
        if(message[i] < 65 || message[i] > 90){
            continue;
        }
        message[i]= char(cipher_equation_AffineCipher(message[i])+'A');
    }
    cout << "Ciphered message: " << message << '\n';
}

void decipher_AffineCipher(){
    for (int i = 0; i < message.size(); ++i) {
        if(message[i] < 65 || message[i] > 90){
            continue;
        }
        message[i] = char(decipher_equation_AffineCipher(message[i])+'A');
    }
    cout << "Deciphered message: " << message << '\n';
}

void start_Affine_cipher(){
    take_choice_AffineCipher();
    if(user_choice==3){
        return;
    }
    take_letter_AffineCipher();
    take_numbers_AffineCipher();
    if(user_choice==1){
        cipher_AffineCipher();
    }else{
        decipher_AffineCipher();
    }
    start_Affine_cipher();
}

#endif
