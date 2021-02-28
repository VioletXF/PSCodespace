// not solved yet
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
int key[8][3]={ //ctrl, y, x
    {0,-1,0},
    {0,0,-1},
    {0,0,1},
    {0,1,0},
    {1,-1,0},
    {1,0,-1},
    {1,0,1},
    {1,1,0} 
};
struct data{
    int step;
    int card;
    int y;
    int x;
    int prev_y;
    int prev_x;
    int selected_y;
    int selected_x;
    int flips;
};
pair<int, int> get_next(vector<vector<int>> board, int y, int x, int ctrl, int updown, int leftright){
    if(ctrl==0){
        y+=updown;
        x+=leftright;
    } else {
        if(updown==-1||updown==1){
            while(y+updown>=0 && y+updown<=3){
                y+=updown;
                if(board[y][x]!=0) break;
            }
        } else {
            while(x+leftright>=0 && x+leftright<=3){
                x+=leftright;
                if(board[y][x]!=0) break;
            }
        }
    }
    if(y>3)y=3;
    if(y<0)y=0;
    if(x>3)x=3;
    if(x<0)x=0;
    return {y,x};
}
int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;
    int maxflip = 0;
    for(int i=0;i<4;i++){
        for(int k=0;k<4;k++){
            maxflip=max(maxflip, board[i][k]);
        }
    }
    queue<data> q;
    q.push({0, 0, r, c, r, c, r, c, 0});
    if(board[r][c]!=0){
        q.push({1, board[r][c], r, c, r, c, r, c, 0});
    }
    while(!q.empty()){
        int step = q.front().step;
        int y = q.front().y;
        int x = q.front().x;
        int prev_y = q.front().prev_y;
        int prev_x = q.front().prev_x;
        int selected_y = q.front().selected_y;
        int selected_x = q.front().selected_x;
        int prevcard = q.front().card;
        int flips = q.front().flips;
        int currcard = board[y][x];
        if(prevcard==currcard && currcard!=0){
            step++;
            flips++;
            if(flips==maxflip){
                return step;
            }
            board[selected_y][selected_x] = 0;
            board[y][x] = 0;
        }
        else if(currcard==0)currcard = prevcard;
        else {
            selected_y = y;
            selected_x = x;
        }
        q.pop();
        for(int i=0;i<8;i++){
            int ctrl = key[i][0];
            int updown = key[i][1];
            int leftright = key[i][2];
            pair<int, int> next = get_next(board, y, x, ctrl, updown, leftright);
            if(next.first!=y||next.second!=x)
                if(next.first!=prev_y||next.second!=prev_x)
                    q.push({step+1, currcard, next.first, next.second, y, x, selected_y, selected_x, flips});
        }
    }
    return answer;
}
int main(){
    std::cout << solution({{1,0,0,3},{2,0,0,0},{0,0,0,2},{3,0,1,0}}, 1, 0);
    std::cout << "end";
}