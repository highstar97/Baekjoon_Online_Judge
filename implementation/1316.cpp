#include <iostream>
#include <set>

bool IsGroupWord(std::string temp)
{
    std::set<char> Group;
    for(int i=0; i<temp.length(); i++){
        if(Group.find(temp[i]) == Group.end())
        {
            Group.emplace(temp[i]);
        }
        else
        {
            if(temp[i-1] != temp[i])
            {
                return false;
            }
        }
    }
    return true;
}

int main(){
    int N;
    int answer = 0;
    std::cin >> N;
    for(int i=0; i<N; i++)
    {
        std::string temp;
        std::cin >> temp;
        if(IsGroupWord(temp))
            answer++;
    }
    std::cout << answer << std::endl;
}