#include <iostream>
#include <vector>

int N, answer = 0;
int board[15];

bool Promising(int x)
{
	for(int i=0; i<x; ++i)
	{
		if(board[x] == board[i] || x-i == abs(board[x]-board[i]))
		{
			return false;
		}
	}
	return true;
}

void NQueen(int x)
{
	if(x == N)
	{
		++answer;
		return;
	}	

	for(int i=0; i<N; ++i)
	{
		board[x] = i;
		if(Promising(x))
		{
			NQueen(x+1);
		}
	}

}

int main()
{
	std::cin >> N;
	NQueen(0);
	std::cout << answer;
}