
#include<bits/stdc++.h>
using namespace std;
#define lli long long int

lli power(lli a, lli b, lli mod){ 
	if (b == 1)
		return a;
	else
		return (((lli)pow(a, b)) % mod);
}

int main(){
	lli P, G, x, a, y, b, ka, kb; 
	
	P = 23;// prime no taken
	cout<<"P: "<<P<<endl; 

	G = 9;// primitive root of P
	cout<<"G: "<<G<<endl; 

	a = 4; // Sehansa selects private key a
	cout<<"The private key a for Sehansha: "<<a<<endl;
	x = power(G, a, P); // generated key
	
	b = 3;// Shakal selects private key b
	cout<<"The private key b for  Shakal: "<<b<<endl;
	y = power(G, b, P); // generated key

	ka = power(y, a, P); 
	kb = power(x, b, P);
	
	cout<<"Secret key for Sehansha is : "<<ka<<endl;
	cout<<"Secret Key for the Shakal is : "<<kb<<endl;
	
	return 0;
}
