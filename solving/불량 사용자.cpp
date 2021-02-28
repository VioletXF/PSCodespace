//틀림
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 0;
vector<bool> used;
vector<vector<int>> map;
int condition_size=0;
int fin = 0;
void solve(int current, int cnt){
    if(cnt==condition_size){
        answer++;
        return;
    }
    if(current==fin){
        return;
    }

    for(int k : map[current]){
        if(!used[k]){
            used[k] = true;
            solve(current+1, cnt+1);
            used[k] = false;
        }
    }
    solve(current+1, cnt);
}
int solution(vector<string> user_id, vector<string> banned_id) {
    answer = 0;
    map.empty();
    used = vector<bool>(9, false);
    for(int i=0;i<user_id.size();i++){
        vector<int> matches;
        for(int k=0;k<banned_id.size();k++){
            bool match = true;
            if(banned_id[k].size()!=user_id[i].size())continue;
            for(int j=0;j<banned_id[k].size();j++){
                if(banned_id[k][j]=='*')continue;
                if(user_id[i][j]!=banned_id[k][j]){
                    match = false;
                    break;
                }
            }
            if(match){
                matches.push_back(k);
            }
        }
        map.push_back(matches);
    }
    condition_size = banned_id.size();
    fin = user_id.size();
    solve(0, 0);

    return answer;
}
int main(){
    cout<<solution({"frodo", "fradi", "crodo", "abc123", "frodoc"}, {"fr*d*", "abc1**"})<<"\n";
    cout<<solution({"frodo", "fradi", "crodo", "abc123", "frodoc"}, {"*rodo", "*rodo", "******"})<<"\n";
    cout<<solution({"frodo", "fradi", "crodo", "abc123", "frodoc"}, {"fr*d*", "*rodo", "******", "******"});

}