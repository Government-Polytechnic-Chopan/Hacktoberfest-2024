#include <bits/stdc++.h>
using namespace std;
#define ll long long

int binary(vector<int>v,int tar){
    int strt=0,end=v.size()-1;
    
    while (strt<=end)
    {
        int m=strt+(end-strt)/2;
        if(v[m]==tar){
            return m;
        }
        else if(v[m]<tar){
            strt=m+1;
        }
        else{
            end=m-1;
        }
        
    }
    return -1;
    
}



int main(){
    vector<int>v={1,2,3,7,9};
    binary(v,7);
}