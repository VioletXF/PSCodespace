#include <string>
#include <vector>
// #include <iostream>
#include <algorithm>
using namespace std;
bool compare(pair<int, double> one, pair<int, double> two){

    if(one.second>two.second){
        return true;
    } else if(one.second==two.second){
        return one.first<two.first;
    }
    return false;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> temp(N);
    for(int i=1;i<=N;i++){
        int cleared = 0;
        int notyet = 0;
        for(auto s : stages){
            if(s>i)cleared++; else if(s==i)notyet++;
        }
        int arrive = cleared + notyet;
        double rate = 0;
        if(arrive==0){
            rate = 0;
        } else {
            rate = (double)notyet/(double)arrive;
        }
        // cout<<"rate of "<<i<<": "<<rate<<"("<<notyet<<"/"<<arrive<<")\n";
        temp[i-1]=make_pair(i, rate);
    }
    sort(temp.begin(), temp.end(), compare);
    for(auto k: temp){
        answer.push_back(k.first);
    }
    return answer;
}
// void printAnswer(vector<int> answer){
//     for(auto k : answer){
//         cout<<k<<", ";
//     }
//     cout<<"\n";
// }
// int main(){
//     printAnswer(solution(5, {2, 1, 2, 6, 2, 4, 3, 3}));//3,4,2,1,5
//     printAnswer(solution(4, {4,4,4,4,4}));//4,1,2,3
// }
