#include <iostream>
#include <stack>

std::stack<char> s;

void checkMatching(std::string str)
{   
    bool flag = false;
    int l_count = 1, b_count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            s.push(str[i]);
        
        else if (str[i] == '\n')
            l_count++;

        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            int asc = str[i] - s.top();
            if (asc == 1 || asc == 2) 
            {
                flag = true;
                s.pop();
                b_count++;
            }
            else
            {
                while(!s.empty())
                    s.pop();
                flag = false;
                break;
            }
        }
    }
    if (s.size() != 0)
    {
        flag = false;
        l_count--;
    }

    if (flag == true)
    {
        l_count--;
        std::cout << "OK, ";
    }
    else if(flag == false) 
        std::cout << "Error, ";

    std::cout << "Line_count : " << l_count << ", ";
    std::cout << "bracket_count : " << b_count << std::endl;
}

int main(){
    std::string Str,temp;
    while(true){
        std::getline(std::cin,temp);
        if(temp=="EOF")break;
        Str.append(temp);
        Str.append("\n");
        std::cin.clear();
    }
    checkMatching(Str);

    return 0;
}