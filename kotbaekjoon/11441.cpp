#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin>>N;
    int arr[100001];
    int sum[100001]={0};
    for(int i=0;i<N;i++){
        cin>>arr[i];
        if(i>0){
            sum[i]=sum[i-1]+arr[i];
        } else {
            sum[0]=arr[0];
        }
    }
    int M;
    cin>>M;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        if(a>=2)
            cout<<sum[b-1]-sum[a-2]<<"\n";
        else
            cout<<sum[b-1]<<"\n";
    }
}