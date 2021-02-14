//시간초과
#include <iostream>
using namespace std;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(false);
    char input[500001];
    int N, K;
    cin>>N>>K;
    int sel = N-K;
    cin>>input;
    
    int maxidx = -1;
    int maxnum;
    int i;
    int num;
    while(sel>0){
        maxnum = 0;
        for(i=maxidx+1;i<N-sel+1;i++){
            num = input[i]-'0';
            if(num>maxnum){
                maxidx = i;
                maxnum = num;
            }
        }
        cout<<input[maxidx];
        sel--;
    }

}