#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int topologySort(int W,int N, int indegree[],int Delay[],vector<int> a[]);

int main(){
        //case, �ǹ�, ��Ģ, �ǹ���ȣ, �ǹ���ȣ2, ��ǥ�ǹ�
    int     T,   N,     K,      X,      Y,          W;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> N >> K;
        
        //������ �ð� �Է�
        int D[N+1];
        for(int n=1; n<=N; n++){
            cin >> D[n]; 
        }
        
        //�������� �Է� �� �ʱ�ȭ
        int indegree[N+1];
        for(int i=0; i<N+1; i++){
            indegree[i] = 0;
        }

        //��Ģ �Է�
        vector<int> a[N+1];
        for(int k=0; k<K; k++){
            cin >> X >> Y;
            a[X].push_back(Y);
            indegree[Y]++;
        }

        //��ǥ�ǹ� ��ȣ �Է�
        cin >> W;

        cout << topologySort(W,N,indegree,D,a) << endl;
    }
}

int topologySort(int W,int N, int indegree[],int Delay[],vector<int> a[]){
    queue<int> q;

    //�ٽ� time�̶�� �迭�� ����!
    //�Ǽ� ���۽ð� �ʱ�ȭ
    int time[N+1];      
    for(int i=0; i<N+1; i++)
        time[i] = 0;

    //���������� 0�� �ǹ� queue�� ����
    for(int i=1; i<=N; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    //�ǹ� ������ŭ �˻� �ʿ�
    for(int i=1; i<=N; i++){
        //����Ŭ �˻�
        if(q.empty()){
            cout << "Cycle" << endl;
            return -1;
        }

        //queue�� ����ִ� �ǹ� ���̳���
        int store = q.front();
        q.pop();
        
        //�̾Ƴ� �ǹ��� ����� ������ �����, ����Ǿ��ִ� �ǹ��� ���۽ð��� ����
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