#include <iostream>
#include <string>
#include <stack>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::stack<char> st;
    std::string str;
    bool flag = true;


    while (1) {
        while (!st.empty())
            st.pop();
        flag = true;
        str = "";

        getline(std::cin, str, '\n');

        if (str == ".")
            return 0;

        for (int i = 0; i < str.length(); i++) 
        {
            if (str[i] == '(' || str[i] == '[') {
                st.push(str[i]);
                continue;
            }

            else if (str[i] == ')') {
                if (st.empty()) {
                    flag = false;
                    break;
                }
                else if (st.top() == '(') {
                    st.pop();
                    continue;
                }
                else
                    flag = false;
            }
            else if (str[i] == ']') {
                if (st.empty()) {
                    flag = false;
                    break;
                }
                else if (st.top() == '[') {
                    st.pop();
                    continue;
                }
                else
                    flag = false;
            }
            else
                continue;
        }
        if (!st.empty())
            flag = false;

        if (flag)
            std::cout << "yes" << '\n';
        else
            std::cout << "no" << '\n';
    }
}