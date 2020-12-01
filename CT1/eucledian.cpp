// Basic Euclidean Algorithm 
#include <bits/stdc++.h> 
using namespace std; 

int gcd(int a, int b){ 
	if (a == 0) 
		return b; 
	return gcd(b % a, a); 
} 

int main(){ 
	int a = 10, b = 15; 
	
	cout<<"enter two number: ";
	cin>>a>>b;

	cout<<"GCD("<<a<<", "<< b << ") = " << gcd(a, b)<< endl; 
	return 0; 
} 
