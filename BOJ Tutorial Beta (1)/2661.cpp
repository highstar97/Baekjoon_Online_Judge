#include <iostream>

int N;
bool IsEnd = false;

bool IsValid(std::string answer)
{
    int len = answer.length();
    int end = len - 1;
	for (int i = 1; i <= len / 2; i++) {
		std::string key = answer.substr(end,i);
        std::string target = answer.substr(end-i,i);
        if(key == target)
        {
            return false;
        }
        --end;
	}
	return true;
}

void DFS(std::string answer, int length)
{
    if(IsEnd)
    {
        return;
    }

    if(IsValid(answer) == false)
    {
        return;
    }

    if(length == N)
    {
        std::cout << answer;
        IsEnd = true;
        return;
    }

    DFS(answer+"1",length+1);
    DFS(answer+"2",length+1);
    DFS(answer+"3",length+1);
}

int main()
{    
    std::cin >> N;
    std::string answer;

    DFS(answer,0);

    return 0;
}