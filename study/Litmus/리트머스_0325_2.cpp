#include <iostream>
#include <stack>

int precedence(char op)
{
    switch(op)
    {
        case '(' : case ')' : return 0;
        case '+' : case '-' : return 1;
        case '*' : case '/' : return 2;
    }
    return -1;
}

int main(void)
{
    std::string input, temp, str;
    std::getline(std::cin, input);

    double val;
    std::stack<char> st;
    std::stack<double> db;

    for (char i : input)
    {
        if (i == ' ')
            continue;
        else if (('0' <= i && i <= '9') || i == '.')
            temp += i;
        else
        {
            if (!temp.empty()) 
            {
                str += temp + ' ';
                temp.clear();
            }
            if (i == '(') st.push(i);
            else if (i == ')')
            {
                while (!st.empty())
                {
                    if (st.top() != '(') str += st.top();
                    st.pop();
                    if (i == '(') break;
                }
            }
            else
            {
                while (!st.empty())
                {
                    if (precedence(i) <= precedence(st.top()))
                    {
                        str += st.top();
                        st.pop();
                    }
                    else break;
                }
                st.push(i);
            }
        }
    }
    if (!temp.empty())
        str += temp + ' ';
    temp.clear();

    while (!st.empty())
    {
        str += st.top();
        st.pop();
    }

    for (char i : str)
    {
        if (i == '+' || i == '-' || i == '*' || i == '/')
        {
            double val2 = db.top(); db.pop();
            double val1 = db.top(); db.pop();
            switch(i){
                case '+': db.push(val1 + val2); break;
                case '-': db.push(val1 - val2); break;
                case '*': db.push(val1 * val2); break;
                case '/': 
                    if (val2 == 0)
                    {
                        std::cout << "Error : zero division error" << std::endl;
                        return 0;
                    }
                    db.push(val1 / val2); break;
            }
        }

        else if ('0' <= i && i <= '9' || i == '.')
        {
            temp += i;
        }
        else
        {
            val = stod(temp);
            temp.clear();
            db.push(val);
        }
    }
    std::cout << std::fixed;
    std::cout.precision(2);
    std::cout << db.top() << std::endl;

    return 0;
}