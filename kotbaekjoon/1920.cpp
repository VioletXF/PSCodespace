#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin>>N;
    vector<int> card(N);
    for(int i=0;i<N;i++){
        cin>>card[i];
    }
    sort(card.begin(), card.end());
    cin>>M;
    for(int i=0;i<M;i++){
        int input;
        cin>>input;
        int left = 0;
        int right = N-1;
        bool found = false;
        while(left<=right){
            int mid = (left+right)/2;
            if(card[mid] == input){
                cout<<"1\n";
                found = true;
                break;
            } else if (card[mid] > input){
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        if(!found){
            cout<<"0\n";
        }

    }
    
}