#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int N, S;
    cin>>N>>S;
    int arr[100001];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int left=0, right=0;
    int sum=arr[left];
    int answer=N+1;
    while(right<N){
        if(sum<S){
            ++right;
            sum+=arr[right];
        } else {
            sum-=arr[left];
            ++left;
        }
        if(sum>=S){
            answer=min(answer, right-left+1);
        }
    }
    if(answer==N+1){
        cout<<0;
    } else {
        cout<<answer;
    }
}