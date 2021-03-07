#include <string>
#include <vector>

using namespace std;
class Trie{
    bool finish;
    Trie* next[26];
public:
    Trie(){
        for(int i=0;i<26;i++)next[i]=nullptr;
    }
    ~Trie(){
        for(int i=0;i<26;i++){
            if(next[i])
                delete next[i];
        }
    }
    void insert(const char* k){
        if(*k=='\0'){
            finish = true;
        } else {
            int current = *k-'A';
            if(next[current] == nullptr){
                next[current] = new Trie();
            }
            next[current]->insert(k+1);
        }
    }
};
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    return answer;
}