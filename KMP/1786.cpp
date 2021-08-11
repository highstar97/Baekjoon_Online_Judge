#include <iostream>
#include <vector>
using namespace std;

vector<int> getpi(string p){
    int m = p.size(); int j = 0;
    vector<int> pi(m,0);    // pi[0]~pi[m-1] 0���� ä��
    for(int i=1; i<m; i++){
        while(j>0 && p[i] != p[j])
            j = pi[j-1];
        if(p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}

vector<int> kmp(string t, string p){
    vector<int> ans;
    vector<int> pi = getpi(p);
    int n = t.size(); int m = p.size(); int j = 0;
    for(int i=0; i<n; i++){
        while(j>0 && t[i] != p[j])
            j = pi[j-1];
        if(t[i] == p[j]){
            if(j == m-1){
                ans.push_back(i-m+1);
                j = pi[j];      // �ٷ� �������� ã�� ���ؼ�
            }
            else
                j++;
        }
    }
    return ans;
}

int main(){
    string t, p;    //t : text, p = pattern
    getline(cin, t);
    getline(cin, p);
    vector<int> matched = kmp(t,p);
    cout << (int)matched.size() << endl;
    for(int i : matched)
        cout << i+1 << " ";     // i+1 : �������� ���ڿ��� ��ȣ�� 1�������̹Ƿ�
    return 0;
}