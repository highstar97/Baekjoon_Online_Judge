#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int topologySort(int N, int indegree[], vector<int> a[]){
    //������ �켱������ �����Ƿ� �켱���� ť(heap)�� �̿�
    //greater<int> : �������� , less<int> : ��������(default)
    priority_queue<int,vector<int>,greater<int>> pq;

    //���������� 0�� ���� queue�� �Է�
    for(int n=1; n<=N; n++){
        if(indegree[n] == 0)
            pq.push(n);
    }

    //���� ������ ���ؼ� ��� Ȯ��
    for(int n=1; n<=N; n++){
        if(pq.empty()){
            cout << "Cycle" << endl;
            return -1;
        }

        int question = pq.top();
        pq.pop();

        cout << question << " ";

        for(int i=0; i<a[question].size(); i++){
            int edge = a[question][i];
            if(--indegree[edge] == 0)
                pq.push(edge);    
        }
    }
    return 0;
}

int main(){
    int N, M, A, B;
    cin >> N >> M;

    vector<int> a[N+1];
    int indegree[N+1];
    for(int i=0; i<N+1; i++)
        indegree[i] = 0;

    for(int m=0; m<M; m++){
        cin >> A >> B;
        a[A].push_back(B);
        indegree[B]++;
    }

    topologySort(N,indegree,a);
}