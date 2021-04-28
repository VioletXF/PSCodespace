#include <iostream>
#include <vector>
using namespace std;
int N,M;
void solve(vector<int> &vec){
    if(vec.size()==M){
        for(auto k: vec){
            cout<<k<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=N;i++){
        vec.push_back(i);
        solve(vec);
        vec.pop_back();
    }
}
int main(){
    cin>>N>>M;
    vector<int> vec;
    solve(vec);
}