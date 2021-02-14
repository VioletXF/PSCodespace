//틀림
#include <iostream>
using namespace std;
int main(){
    long long min, max;
    int cnt = 0;
    bool check[1000001];
    cin>>min>>max;
    for(long long i = 2; i*i<=max;i++){
        long long begin = min/(i*i);
        if(min%(i*i)!=0)begin++;
        for(long long k=begin;i*i*k<=max;k++){
            check[i*i*k-min] = true;
        }
    }
    for(int i=0;i<max-min+1;i++){
        if(!check[i])cnt++;
    }
    cout<<cnt;
}