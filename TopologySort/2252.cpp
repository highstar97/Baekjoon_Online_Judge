#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 32001;

int topologySort(int node, int indegree[], vector<int> a[]){
    queue<int> q;
    int result[node];
    
    //진입차수가 0인 node를 queue에 저장
    for(int i=1; i<=node; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    for(int i=1; i<=node; i++){
        //queue가 비어있으면 "Cycle"이 존재하는 것
        if(q.empty()){
            cout << "Cycle" << endl;
            return 0;
        }

        //queue에서 node를 하나 빼서 result 배열에 저장
        int NODE = q.front();
        q.pop();
        result[i] = NODE;

        //뺀 노드와 인접한 간선 제거
        for(int i=0; i<a[NODE].size(); i++){
            int edge = a[NODE][i];
            if(--indegree[edge] == 0){
                q.push(edge);
            }
        }
    }

    //출력
    for(int i=1; i<=node; i++){
        cout << result[i] << " ";
    }
    return 0;
}

int main(){
    int N, M;
    cin >> N >> M;
    
    int node = N;
    vector<int> a[MAX];
    int indegree[MAX];
    for(int i=0; i<MAX; i++)
        indegree[i] = 0;

    //비교 데이터 입력
    for(int i=0; i<M; i++){
        int A, B;
        cin >> A >> B;
        a[A].push_back(B);
        indegree[B]++;
    }

    topologySort(node,indegree,a);
}