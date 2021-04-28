#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(int a, int b){
    if(a<0 && b<0)
        return a>b;
    else
        return a<b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    int minus=0;
    int plus=0;
    cin>>N;
    vector<int> arr(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
        if(arr[i]<0)minus++; else plus++;
    }
    sort(arr.begin(), arr.end(), compare);
    vector<int> minus_arr(minus);
    for(int i=0;i<minus;i+=2){
        minus_arr[i/2]=arr[i+1];
        minus_arr[minus-i/2-1]=arr[i];
    }
    if(minus%2){
        minus_arr[minus/2]=arr[minus-1];
    }
    for(auto i: minus_arr){
        cout<<i<<" ";
    }
    vector<int> plus_arr(plus);
    for(int i=0;i<plus;i+=2){
        plus_arr[i/2]=arr[minus+i];
        plus_arr[plus-i/2-1]=arr[minus+i+1];
    }
    if(plus%2){
        plus_arr[plus/2]=arr[minus+plus-1];
    }
    for(auto i: plus_arr){
        cout<<i<<" ";
    }
}