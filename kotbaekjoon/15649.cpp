#include <iostream>
#include <vector>
using namespace std;
int N,M;
void solve(vector<int> &vec, bool visited[]){
    if(vec.size()==M){
        for(auto k: vec){
            cout<<k<<" ";
        }
        cout<<"\n";
    }
    for(int i=1;i<=N;i++){
        if(visited[i]==true)continue;
        visited[i]=true;
        vec.push_back(i);
        solve(vec, visited);
        visited[i]=false;
        vec.pop_back();
    }
}
int main(){
    cin>>N>>M;
    vector<int> vec;
    bool visited[9]={false};
    solve(vec, visited);
}