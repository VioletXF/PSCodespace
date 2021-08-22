#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int d[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};
int solution(vector<vector<int>> board) {
    int answer = 0;
    queue<pair<int, int>> q;
    int cost[25][25][4];
    int visited[25][25][4];
    for(int i=0;i<4;i++){
        cost[0][0][i] = 0;
        visited[0][0][i] = true;
    }
    q.push({0,0});
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int y2 = y+d[i][0];
            int x2 = x+d[i][1];
            if(0<=y2 && y2<board.size() && 0<=x2 && x2<board.size()){
                if(!board[y2][x2]){
                    bool update = false;
                    if(y2!=0 || x2!=0){
                        for(int k=0;k<4;k++){
                            if(visited[y2][x2][k]){
                                if(cost[y2][x2][i]){
                                    cost[y2][x2][i] = min(cost[y2][x2][i], cost[y][x][k]+((i+k)%2?600:100));
                                } else {
                                    cost[y2][x2][i] = cost[y][x][k] + ((i+k)%2?600:100);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return answer;
}