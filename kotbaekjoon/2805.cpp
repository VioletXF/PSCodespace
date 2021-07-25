#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
long long tree[1000001];
long long aftercut(long long height){
    long long result = 0;
    for(int i=0;i<N;i++){
        result+=max(0LL, tree[i]-height);
    }
    return result;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long right = 0;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>tree[i];
        right = max(right, tree[i]);
    }
    long long left = 1;
    long long result = 0;
    while(left<=right){
        long long mid = (left+right)/2;
        long long len = aftercut(mid);
        if(len>=M){
            left = mid+1;
            result = mid;
        } else {
            right = mid-1;
        }
    }
    cout<<result;
}