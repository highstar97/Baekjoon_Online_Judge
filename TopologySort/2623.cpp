#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int topologySort(int N, int indegree[], vector<int> a[]);

int main(){
    int N, M, num_pick, X;
    cin >> N >> M;

    vector<int> a[N+1];
    int indegree[N+1];
    for(int i=0; i<N+1; i++)
        indegree[i] = 0;

    //가수 순서 입력 받기
    for(int i=0; i<M; i++){
        cin >> num_pick;
        int A, B;
        cin >> A;
        while(--num_pick != 0){
            cin >> B;
            a[A].push_back(B);
            indegree[B]++;
            A = B;
        }
    }

    topologySort(N,indegree,a);
}

int topologySort(int N, int indegree[], vector<int> a[]){
    queue<int> q;
    int singer, result[N];

    for(int n=1; n<=N; n++){
        if(indegree[n] == 0)
            q.push(n);
    }

    for(int n=1; n<=N; n++){
        if(q.empty()){
            cout << 0 << endl;
            return -1;
        }

        singer = q.front();
        q.pop();
        result[n-1] = singer;
        for(int i=0; i<a[singer].size(); i++){
            int edge = a[singer][i];
            if(--indegree[edge] == 0)
                q.push(edge);
        }
    }

    for(int i : result){
        cout << i <<endl;
    }
    return 0;
}