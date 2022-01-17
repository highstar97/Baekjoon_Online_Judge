#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

struct Location
{
    int x; int y;
};

int N, M;
Location R, B, O;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

typedef std::vector<std::string> Board;

void ShowBoard(Board board)
{
    for(auto data : board)
    {
        for(int i=0; i<M; i++)
            std::cout << data[i];
        std::cout << std::endl;
    }
}

void GetRBOLocation(Board& board)
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(board[i][j] == 'R')
            {
                R.x = i; R.y = j;
                board[i][j] = '.';
            }
            else if(board[i][j] == 'B')
            {
                B.x = i; B.y = j;
                board[i][j] = '.';
            }
            else if(board[i][j] == 'O')
            {
                O.x = i; O.y = j;
            }
        }
    }
}

bool Rotate(std::queue<Board>& q, Board board, int d)
{
    GetRBOLocation(board);
    bool isRfirst;
    switch(d)
    {
        case 0:
            isRfirst = R.x < B.x;
            break;
        case 1:
            isRfirst = R.x > B.x;
            break;
        case 2:
            isRfirst = R.y < B.y;
            break;
        case 3:
            isRfirst = R.y > B.y;
            break;
    }

    // 우선순위와 d에 따라 구슬 이동
    if(isRfirst)
    {
        while(board[R.x+dx[d]][R.y+dy[d]] != '#')
        {
            R.x += dx[d]; R.y += dy[d];
            if(board[R.x][R.y] == 'O') break;
        };
        board[R.x][R.y] = 'R';
        while(board[B.x+dx[d]][B.y+dy[d]] != '#' && board[B.x+dx[d]][B.y+dy[d]] != 'R')
        {
            B.x += dx[d]; B.y += dy[d];
            if(board[B.x][B.y] == 'O') break;
        };
        board[B.x][B.y] = 'B';
    }
    else
    {
        while(board[B.x+dx[d]][B.y+dy[d]] != '#')
        {
            B.x += dx[d]; B.y += dy[d];
            if(board[B.x][B.y] == 'O') break;
        };
        board[B.x][B.y] = 'B';
        while(board[R.x+dx[d]][R.y+dy[d]] != '#' && board[R.x+dx[d]][R.y+dy[d]] != 'B')
        {
            R.x += dx[d]; R.y += dy[d];
            if(board[R.x][R.y] == 'O') break;
        };
        board[R.x][R.y] = 'R';
    }
    q.emplace(board);

    if(B.x == O.x && B.y == O.y) return false;
    if(R.x == O.x && R.y == O.y) return true;
    return false;
}

int bfs(Board& board)
{
    int count = 0;
    bool issuccess = false;
    std::queue<Board> q;
    q.emplace(board);
    while(!q.empty())
    {
        Board front_board = q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            issuccess = Rotate(q, front_board, i);
            if(issuccess)
                return ++count;
        }
        count++;
    }
    return -1;
}

int main()
{
    // 입력 받기
    std::cin >> N >> M;
    Board board(N);
    for(int i=0; i<N; i++)
    {
        std::cin >> board[i];
    }
    
    int result = bfs(board);
    if(result == -1)
        std::cout << -1;
    else 
    {
        for(int i=0; i<10; i++)
        {
            result -= pow(4,i);
            if(result <= 0)
            {
                std::cout << i+1;
                break;
            }
        }
    }
    return 0;
}

/* 정답
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
using namespace std;

typedef vector<string> Board;

int N,M;
const int dy[]={-1,1,0,0};
const int dx[]={0,0,-1,1};

// 보드판 판별
int check(Board& b){
    bool hasRed=false,hasBlue=false;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(b[i][j]=='R') hasRed=true;
            else if(b[i][j]=='B') hasBlue=true;
        }
    }
    if(!hasBlue) return -1; // 파란 공이 없을 시 실패
    if(!hasRed) return 1; // 빨간 공이 없을 시 성공
    return 0; // 아무것도 아닌 경우
}

// 빨강 파랑 우선순위 판단
bool isRedFirst(int ry, int rx, int by, int bx, int d){
    switch(d){
    case 0: return ry < by;
    case 1: return ry > by;
    case 2: return rx < bx;
    case 3: return rx > bx;
    }
}

// 보드판 회전과 구슬 이동
Board rotate(Board& prev, int d){
    Board ret(N);
    for(int i=0;i<N;i++)
        ret[i]=prev[i];

    int ry,rx,by,bx;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(ret[i][j]=='B'){
                ret[i][j]='.';
                by=i; bx=j;
            }
            else if(ret[i][j]=='R'){
                ret[i][j]='.';
                ry=i; rx=j;
            }
        }
    }

    bool redFirst = isRedFirst(ry,rx,by,bx,d);

    while(ret[ry+dy[d]][rx+dx[d]]!='#'){
        ry+=dy[d]; rx+=dx[d];
        if(ret[ry][rx]=='O') break;
    };
    while(ret[by+dy[d]][bx+dx[d]]!='#'){
        by+=dy[d]; bx+=dx[d];
        if(ret[by][bx]=='O') break;
    };

    if(ret[ry][rx]!='O' && ry==by && rx==bx){
        if(redFirst){ by-=dy[d]; bx-=dx[d]; }
        else { ry-=dy[d]; rx-=dx[d]; }
    }

    if(ret[ry][rx]!='O') ret[ry][rx]='R';
    if(ret[by][bx]!='O') ret[by][bx]='B';

    return ret;
}

int bfs(Board& init){
    map<Board,int> m;
    m[init]=0;
    queue<Board> q;
    q.push(init);
    while(!q.empty()){
        Board cur = q.front();
        q.pop();
        int curDist = m[cur];
        if(curDist>=10) break;
        for(int i=0;i<4;i++){
            Board next = rotate(cur,i);
            int res = check(next);
            if(res==-1) continue;
            else if(res==1) return curDist+1;
            if(m.find(next)==m.end()){
                m[next]=curDist+1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main(){
    cin>>N>>M;
    Board board(N);
    for(int i=0;i<N;i++)
        cin>>board[i];
    cout<<bfs(board);
    return 0;
}*/