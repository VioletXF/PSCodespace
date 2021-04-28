#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    int input[100001];
    int sum[100001];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    sum[0]=input[0];
    int answer=input[0];
    for(int i=1;i<n;i++){
        sum[i]=max(sum[i-1]+input[i], input[i]);
        answer=max(answer,sum[i]);
    }
    cout<<answer;

}