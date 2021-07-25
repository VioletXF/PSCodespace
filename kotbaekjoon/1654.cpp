#include <iostream>
#include <algorithm>
using namespace std;
long long lan[10001];
int K, N;
long long count(long long length){
    long long result = 0;
    for(int i=0; i<K;i++){
        result+=lan[i]/length;
    }
    return result;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>K>>N;
    long long right = 0;
    for(int i=0;i<K;i++){
        cin>>lan[i];
        right = max(right, lan[i]);
    }
    long long left = 1;
    
    long long result = 0;
    while(left<=right){
        long long mid = (left+right)/2;
        long long cnt = count(mid);
        if(cnt>=N){
            result = mid;
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    cout<<result;
}