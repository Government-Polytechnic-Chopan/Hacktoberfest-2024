#include <iostream>
using namespace std;
//number to binary
int binary(int dec){
int pow=1,ans=0,rem;

while(dec>0){
    rem=dec%2;
    ans+=(rem*pow);
    dec/=2;
    pow*=10;}
    return ans; }
    
    int main(){
        int n;
        cin>>n;
        cout<<binary(n);
      
return 0; }
