//틀림
#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
vector<string> words;
set<char> consumed;
bool isInvalid;
void consume(char what){
    //cout<<"consumed "<<what<<" ";
    consumed.insert(what);
}
int ruleSide(string str, int idx, bool consumes = true){ //returns next idx
    if(isInvalid) return idx;
    if(idx == str.size()) return idx;
    if(isupper(str[idx])) return idx;
    char low = str[idx];
    if(consumed.find(low)!=consumed.end() && consumes){
        //invalid
        isInvalid = true;
        return str.size();
    }
    if(islower(str[idx+1]) && consumes){
        //invalid
        isInvalid = true;
        return str.size();
    }
    int endIdx = -1;
    char other = 0;
    bool wasLow = false;
    for(int i=idx+2;i<str.size();i++){
        if(islower(str[i])){
            if(str[i]==low){
                if(endIdx==-1){
                    endIdx = i;
                } else { // not this rule
                    return idx;
                }
            } else if(other!=0){
                if(other != str[i]){
                    if(wasLow)
                        break;
                }
            } else {
                other = str[i];
                if(consumed.find(other)!=consumed.end() && consumes){
                    //invalid
                    //cout<<"gosh"<<other<<" on "<<i;
                    isInvalid = true;
                    return str.size();
                }
                if(consumes)
                    consume(other);
                
            }
            wasLow = true;
        }else {
            wasLow = false;
        }
    }
    if(endIdx==-1 && consumes){
        //invalid
        isInvalid = true;
        return str.size();
    }
    if(consumes){
        consume(low);
        words.push_back(str.substr(idx, endIdx-idx+1));
    }
    return endIdx+1;
}
int ruleMiddle(string str, int idx){ //returns next idx
    if(isInvalid)return idx;
    if(idx==str.size())return idx;
    if(islower(str[idx]))return idx;
    char low;
    int lowcnt=0;
    if(idx+1<str.size())
        low = str[idx+1];
    else {
        words.push_back(str.substr(idx, 1));
        return idx+1;
    }
    if(consumed.find(low)!=consumed.end()){
        //invalid
        isInvalid = true;
        return str.size();
    }
    int endIdx = idx;
    for(int i=idx; i+2<str.size(); i+=2){
        char mayUpper = str[i];
        char mayLower = str[i+1];
        char mayUpper2 = str[i+2];
        if(isupper(mayUpper) && isupper(mayUpper2) && mayLower == low){
            endIdx = i+2;
            lowcnt++;
        } else {
            break;
        }
    }
    
    if(endIdx+1<str.size() && str[endIdx+1] == low){
        //invalid
        isInvalid = true;
        return str.size();
    }
    //cout<<"lowcnt"<<lowcnt;
    if(lowcnt==1 && endIdx-1!=ruleSide(str, endIdx-1, false)){
        //cout<<"test";
        consume(low);
        words.push_back(str.substr(idx, endIdx-2-idx+1));
        return endIdx-1;
    }
    consume(low);
    words.push_back(str.substr(idx, endIdx-idx+1));
    return endIdx+1;
}

int passUpperSeq(string str, int idx) { //returns next idx
    if(isInvalid)return idx;
    if(idx==str.size())return idx;
    if(islower(str[idx]))return idx;
    int endIdx = idx;
    for(int i=idx+1; i<str.size(); i++){
        if(isupper(str[i])){
            endIdx = i;
        } else {
            break;
        }
    }
    if(endIdx+1<str.size() && endIdx+1 != ruleSide(str, endIdx+1, false)){
        words.push_back(str.substr(idx, endIdx-idx+1));
        return endIdx+1;
    } else {
        if(endIdx+1==str.size()){
            words.push_back(str.substr(idx, endIdx-idx+1));
            return endIdx+1;
        } else {
            if(endIdx!=idx)
                words.push_back(str.substr(idx, endIdx-1-idx+1));
            return endIdx;
        }
    }
    
    
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
    words.clear();
    consumed.clear();
    isInvalid = false;
    string answer = "";
    int idx = 0;
    int previdx=0;
    for(int i=0;i<sentence.size();i++){
        if(sentence[i]==' '){
            return "invalid";
        }
    }
    while(idx<sentence.size() && !isInvalid){
        idx = ruleSide(sentence, idx);
        //cout<<idx<<", ";
        idx = passUpperSeq(sentence, idx);
        //cout<<idx<<", ";
        idx = ruleMiddle(sentence, idx);
        //cout<<idx<<", ";
        if(idx==previdx){
            if(isupper(sentence[idx])){
                words.push_back(sentence.substr(idx, 1));
                idx++;
            } else {
                isInvalid = true;
                break;
            }
        }
        previdx = idx;
    }
    if(isInvalid){
        return "invalid";
    }
    for(string k:words){
        string filtered ="";
        for(int i=0;i<k.size();i++){
            if(isupper(k[i]))filtered+=k[i];
        }
        answer.append(filtered+" ");
    }
    return answer.substr(0, answer.size()-1);
}


// int main(){
//     cout<<solution("HELLOWORLD")<<"\n";
//     cout<<solution("HaEaLaLaObWORLDb")<<"\n";
//     cout<<solution("aHbEbLbLbOacWdOdRdLdDc")<<"\n";
//     cout<<solution("aHELLOa bWORLDb")<<"\n";
//     cout<<solution("HaEaLaLObWORLDb")<<"\n";
//     cout<<solution("aHELLOWORLDa")<<"\n";
//     cout<<solution("HaEaLaLaOWaOaRaLaD")<<"\n";
//     cout<<solution("abHELLObaWORLD")<<"\n";
//     cout<<solution("SpIpGpOpNpGJqOqA")<<"\n";
//     cout<<solution("AxAxAxAoBoBoB")<<"\n";
//     cout<<solution("HaEaLaLaObWcOcRcgLgcDb")<<"\n";
//     cout<<solution("aa")<<"\n";
//     cout<<solution("XcXbXcX")<<"\n";
//     cout<<solution("cXbXc")<<"\n";
// }