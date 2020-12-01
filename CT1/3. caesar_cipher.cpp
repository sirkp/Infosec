#include <bits/stdc++.h> 
using namespace std; 
  
string encryption(string text, int s){ 
    string ans = ""; 
  
    for (int i=0;i<text.size();i++) { 
        if (isupper(text[i])) 
            ans += char(int(text[i]+s-65)%26 +65); 
        else
            ans += char(int(text[i]+s-97)%26 +97); 
    } 
    return ans; 
}


  
int main() {
    string text="ATTACKATONCE"; 
    int s = 4; 
    cin>>text>>s;
    cout << "text : " << text; 
    cout << "\nshift: " << s; 
    cout << "\ncipher: " << encryption(text, s); 
    cout << "\ntext: " << encryption(encryption(text, s), -s)<<endl; 
    return 0; 
} 