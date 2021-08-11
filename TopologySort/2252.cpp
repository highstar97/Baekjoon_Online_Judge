#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 32001;

int topologySort(int node, int indegree[], vector<int> a[]){
    queue<int> q;
    int result[node];
    
    //���������� 0�� node�� queue�� ����
    for(int i=1; i<=node; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    for(int i=1; i<=node; i++){
        //queue�� ��������� "Cycle"�� �����ϴ� ��
        if(q.empty()){
            cout << "Cycle" << endl;
            return 0;
        }

        //queue���� node�� �ϳ� ���� result �迭�� ����
        int NODE = q.front();
        q.pop();
        result[i] = NODE;

        //�� ���� ������ ���� ����
        for(int i=0; i<a[NODE].size(); i++){
            int edge = a[NODE][i];
            if(--indegree[edge] == 0){
                q.push(edge);
            }
        }
    }

    //���
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

    //�� ������ �Է�
    for(int i=0; i<M; i++){
        int A, B;
        cin >> A >> B;
        a[A].push_back(B);
        indegree[B]++;
    }

    topologySort(node,indegree,a);
}