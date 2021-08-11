#include <iostream>
#include <vector>
using namespace std;

int getpi(string t){
    int n = t.size(); int j = 0; int max_pi = 0;
    vector<int> pi(n,0);
    for(int i=1; i<n; i++){
        while(j>0 && t[i] != t[j])
            j = pi[j-1];
        if(t[i] == t[j]){
            pi[i] = ++j;
            if(max_pi < pi[i])
                max_pi = pi[i];
        }
    }
    return max_pi;
}

int main(){
    string t;
    getline(cin, t);
    int n = t.size();
    int max_length = 0;
    //모든 부분 문자열에 대해서 확인
    while(t.size()>0){
        int max_pi = getpi(t);
        if(max_length < max_pi)
            max_length = max_pi;
        if(t.size()>1)
            t = t.substr(1);    // 1번 index부터 끝까지 리턴
        else break;
    }
    cout << max_length;
    return 0;
}