#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long a;
    long long sum = 0;
    long long length=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(i>0){
            sum+=length*a;
        }
        length+=a;
        
    }
    cout<<sum;
}