#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int topologySort(int N, int indegree[], int Delay[], vector<int> a[]);

int main(){
    int  N, X;
    cin >> N;
    
    int Delay[N+1];
    vector<int> a[N+1];
    int indegree[N+1];
    for(int i=0; i<N+1; i++){
        indegree[i] = 0;
    }

    for(int n=1; n<=N; n++){
        int count = 1;
        while(true){
            cin >> X;
            if(count == 1)
                Delay[n] = X;
            if(X == -1)
                break;
            if(X != -1 && count > 1){
                a[X].push_back(n);
                indegree[n]++;
            }
            count++;
        }
    }

    topologySort(N,indegree,Delay,a);
}

int topologySort(int N, int indegree[], int Delay[], vector<int> a[])
{
    queue<int> q;
    int time[N + 1]; //건물 짓기 실행하는 시간
    for (int i = 0; i < N + 1; i++)
        time[i] = 0;

    for (int n = 1; n <= N; n++)
    {
        if (indegree[n] == 0)
            q.push(n);
    }

    for (int n = 1; n <= N; n++)
    {
        if (q.empty())
            return -1;

        int store = q.front();
        q.pop();
        for (int i = 0; i < a[store].size(); i++)
        {
            int edge = a[store][i];
            if (--indegree[edge] == 0)
                q.push(edge);
            if (time[edge] < time[store] + Delay[store])
                time[edge] = time[store] + Delay[store];
        }
    }

    for(int i=1; i<=N; i++){
        cout << time[i]+Delay[i] << endl;
    }
    
    return 0;
}