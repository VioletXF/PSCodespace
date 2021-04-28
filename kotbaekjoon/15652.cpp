#include <iostream>
#include <vector>
using namespace std;
int N,M;
void solve(vector<int> &vec, int offset){
    if(vec.size()==M){
        for(auto k: vec){
            cout<<k<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=offset;i<=N;i++){
        vec.push_back(i);
        solve(vec, i);
        vec.pop_back();
    }
}
int main(){
    cin>>N>>M;
    vector<int> vec;
    solve(vec, 1);
}