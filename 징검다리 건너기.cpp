#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 200000001;
    int max = 0;
    int next_max = 0;
    int next_maxidx = -1;
    int maxidx = -1;
    for(int i=0;i<stones.size();i++){
        if(i==k){
            if(max<answer){
                answer = max;
                cout<<answer<<", "<<i<<"p1\n";
            }
        }
        if(next_max<stones[i]){
            next_max = stones[i];
            next_maxidx = i;
        }
        if(i-maxidx==k){
            max = next_max;
            maxidx = next_maxidx;
            next_max = stones[next_maxidx+1];
            if(max<answer){
                answer = max;
                cout<<answer<<", "<<i<<"p2\n";
            }
            if(i+1<stones.size()){
                next_max = stones[i+1];
                next_maxidx = i+1;
            }
        }
        
        if(max<stones[i]){
            max = stones[i];
            maxidx = i;
            if(i+1<stones.size()){
                next_max = stones[i+1];
                next_maxidx = i+1;
            }
        }
        
        
    }
    if(max<answer){
        answer = max;
        cout<<answer<<"\n";
    }
    return answer;
}
int main(){
    cout<<solution({9,8,7,6,5,4,3,2,1},3);
}