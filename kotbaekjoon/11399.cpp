#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int> p(N);
    for(int i=0;i<N;i++){
        cin>>p[i];
    }
    sort(p.begin(), p.end());
    int answer=0;
    int sum=0;
    for(int i=0;i<N;i++){
        sum+=p[i];
        answer+=sum;
    }
    cout<<answer;
}