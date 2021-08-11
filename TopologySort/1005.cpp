#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int topologySort(int W,int N, int indegree[],int Delay[],vector<int> a[]);

int main(){
        //case, 건물, 규칙, 건물번호, 건물번호2, 목표건물
    int     T,   N,     K,      X,      Y,          W;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> N >> K;
        
        //딜레이 시간 입력
        int D[N+1];
        for(int n=1; n<=N; n++){
            cin >> D[n]; 
        }
        
        //진입차수 입력 및 초기화
        int indegree[N+1];
        for(int i=0; i<N+1; i++){
            indegree[i] = 0;
        }

        //규칙 입력
        vector<int> a[N+1];
        for(int k=0; k<K; k++){
            cin >> X >> Y;
            a[X].push_back(Y);
            indegree[Y]++;
        }

        //목표건물 번호 입력
        cin >> W;

        cout << topologySort(W,N,indegree,D,a) << endl;
    }
}

int topologySort(int W,int N, int indegree[],int Delay[],vector<int> a[]){
    queue<int> q;

    //핵심 time이라는 배열을 선언!
    //건설 시작시간 초기화
    int time[N+1];      
    for(int i=0; i<N+1; i++)
        time[i] = 0;

    //진입차수가 0인 건물 queue에 저장
    for(int i=1; i<=N; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    //건물 개수만큼 검사 필요
    for(int i=1; i<=N; i++){
        //싸이클 검사
        if(q.empty()){
            cout << "Cycle" << endl;
            return -1;
        }

        //queue에 들어있는 건물 뽑이내기
        int store = q.front();
        q.pop();
        
        //뽑아낸 건물과 연결된 간선을 지우고, 연결되어있던 건물의 시작시간을 갱신
        for(int j=0; j<a[store].size(); j++){
            int edge = a[store][j];
            if(time[edge] < time[store] + Delay[store])
                time[edge] = time[store] + Delay[store];
            if(--indegree[edge] == 0)
                q.push(edge);
        }
    }

    return time[W] + Delay[W];
}