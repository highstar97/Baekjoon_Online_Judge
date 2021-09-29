#include <iostream>

int main()
{
    int answer = 0;
    std::string input;
    std::cin >> input;

    for(int i=input.length()-1; i >= 0; i--)
    {
        if(input[i] == '=')
        {
            if(i-2 >= 0 && input[i-2] == 'd')
                i -= 2;
            else
                i -= 1 ;
        }
        else if(input[i] == '-')
        {
            i -= 1;
        }   
        else if(input[i] == 'j')
        {  
            if(i-1 >= 0 && (input[i-1] == 'l' || input[i-1] == 'n'))
                i -= 1;
        }
        answer++;
    }

    std::cout << answer << std::endl;
}