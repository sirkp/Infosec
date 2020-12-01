#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll power(ll a,ll b,ll mod){
    a=a%mod;
    ll ans=1;
    while(b>0){
        if(b&1){
            ans=(ans*a)%mod;
        }
        b=b>>1; a=(a*a)%mod;
    }
    return ans;
}
bool millerRobin(int d,int n){
    int a = 2+rand()%(n-4);

    int x = power(a,d,n);

    if(x==1 or x==n-1) return true;

    while(d!=n-1){
        x = (x*x)%n;
        d*=2;

        if(x==1 or x==n-1)return true;
    }
    return false;
}

bool isPrime(int n,int k){
    if(n==2 or n==3)return true;
    if(n<=4)return false;

    int q = n-1;
    while(q%2!=1){
        q/=2;
    }

    // fermat little theory a^(n-1)%n =1 iff n is prime
    //  so write n-1 = q*(2^r)  where r>=1 , q is odd( becz n-1 is even(n is odd(prime)))

    // a^(d*2^r)%n=1 for n to be prime
    for(int i=0;i<k;i++){
        if(!millerRobin(q,n)){
            return false;
        }
    }
    return true;
}
int main(){
    int n,k;
    cin>>n>>k;

    if(isPrime(n,k)){
        cout << n <<" is prime" << endl;
    }else{
        cout << n<<" is not prime" << endl;
        }
    return 0;
}
