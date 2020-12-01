#include<bits/stdc++.h>
using namespace std;

void process(string& text){
    string temp;
    for(auto c: text){
        if(c == 32)
            continue;
        temp.push_back(c);
    }
    transform(temp.begin(),temp.end(),temp.begin(),::tolower);
    text = temp;
}

string keyStream(string key, string text){
    int key_len = key.size();
    string new_key(key);

    int i=0;
    while(new_key.size()!=text.size()){
        new_key.push_back(key[i]);
        i++;
        if(i==key_len)i=0;

    }
    return new_key;
}

string vigenere(string& text, string key){
    process(text);
    string encrypted;

    for (int i = 0;i<text.size(); i++){
        char p = (text[i] + key[i]-2*'a')%26;
        p+='a';
        encrypted.push_back(p);
    }
    return encrypted;
}

string decryption(string encrypted,string key){
    string decrypted;

    for (int i = 0;i<encrypted.size(); i++){
        char p = (encrypted[i] -key[i] +26) %26;
        p+='a';
        decrypted.push_back(p);
    }
    return decrypted;
}

int main(){
    string key, text;
    cout<<"Enter text: ";
    getline(cin, text);
    cout<<"Enter key: ";
    cin >> key;
    cout<<endl;
    key = keyStream(key,text);
    cout << "key: " << key << endl;
    cout << "text: " << text << endl;
    string encrypted = vigenere(text,key);

    cout << "\nEncrypted text: " << encrypted << endl;
    string decrypted = decryption(encrypted,key) ;

    cout << "Decrypted Text: " << decrypted << endl;
    return 0;
}