#include <iostream>
#include <string>
#include <stack>

int precedence(char);

int main(void)
{
    std::string str;
    std::getline(std::cin,str);

    std::cout << str << std::endl;

    char op;
    int index = 0;
    std::string temp = str;
    //str.clear();
    std::stack<char> st;
    
    for (char i : temp)
    {
        if (('0' <= i && i <= '9') || i == '.' || i == ' ')
        {
            if (i == ' ' && ('0' <= str[index - 1] && str[index - 1] <= '9'))
                str[index++] = ' ';
            else str[index++] = i;
        }

        else if ( i == '(') st.push(i);
        else if ( i == ')')
        {
            while (!st.empty())
            {
                if (st.top() != '(') str[index++] = st.top();
                st.pop();
                if (i == '(') break;
            }
        }
        else if ( i == '+' || i == '-' || i == '*' || i == '/')
        {
            while (!st.empty())
            {
                op = st.top();
                if (precedence(i) <= precedence(op))
                {
                    str[index++] = st.top();
                    st.pop();
                }
                else break;
            }
            st.push(i);
        }
    }
    while (!st.empty())
    {
        str[index++] = st.top();
        st.pop();
    }
    
    std::cout << str << std::endl;

    index = 0;
    int dot;
    double val;
    std::string temp1;
    std::stack<double> db;
    
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
            temp1[index++] = i;
        }
        else if (i == ' ' && index != 0)
        {
            for (int c = 0; c < temp1.length(); c++)
            {
                if (temp1[c] == '.')
                dot = c;
            }
            for (int c = 0; c < temp1.length(); c++)
            {
                double tmp = 0;
                int d;
                if (c < dot)
                {
                    d = dot - c;
                    tmp = (temp1[c] - 48);
                    while (d--)
                    {
                        tmp *= 10;
                    }
                    val += tmp;
                }
                else if (c == '.') continue;
                else
                {
                    d = c - dot;
                    tmp = (temp1[c] - 48);
                    while(d--)
                    {
                        tmp /= 10;
                    }
                    val += tmp;
                    index = 0;
                }
            }
            db.push(val);
        }
    }
    std::cout << std::fixed;
    std::cout.precision(2);
    std::cout << db.top() << std::endl;

    return 0;
}

// std::string makePostfix(std::string str)
// {
//     char op;
//     int index = 0;
//     std::string temp = str;
//     str.clear();
//     std::stack<char> st;
    
//     for (char i : temp)
//     {
//         if (('0' <= i && i <= '9') || i == '.' || i == ' ')
//         {
//             str[index++] = i;
//         }

//         else if ( i == '(') st.push(i);
//         else if ( i == ')')
//         {
//             while (!st.empty())
//             {
//                 str[index++] = st.top();
//                 st.pop();
//                 if (i == '(') break;
//             }
//         }
//         else if ( i == '+' || i == '-' || i == '*' || i == '/')
//         {
//             while (!st.empty())
//             {
//                 op = st.top();
//                 if (precedence(i) <= precedence(op))
//                 {
//                     str[index++] = st.top();
//                     st.pop();
//                 }
//                 else break;
//             }
//             st.push(i);
//         }

//     }
//     while (!st.empty())
//         {
//             str[index++] = st.top();
//             st.pop();
//         }

//     return str;
// }

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

// void calc(std::string str)
// {
//     int index = 0;
//     int dot;
//     double val;
//     std::string temp;
//     std::stack<double> db;

//     for (char i : str)
//     {
//         if (i == '+' || i == '-' || i == '*' || i == '/')
//         {
//             double val2 = db.top(); db.pop();
//             double val1 = db.top(); db.pop();
//             switch(i){
//                 case '+': db.push(val1 + val2); break;
//                 case '-': db.push(val1 - val2); break;
//                 case '*': db.push(val1 * val2); break;
//                 case '/': 
//                     if (val2 == 0)
//                     {
//                         std::cout << "Error : zero division error" << std::endl;
//                         return 0;
//                     }
//                     db.push(val1 / val2); break;
//             }
//         }
//         else if ('0' <= i && i <= '9' || i == '.')
//         {
//            temp[index++] = i;
//         }
//         else if (i == ' ')
//         {
//             for (int c = 0; c < temp.length(); c++)
//             {
//                 if (temp[c] == '.')
//                 dot = c;
//             }
//             for (int c = 0; c < temp.length(); c++)
//             {
//                 double tmp = 0;
//                 int d;
//                 if (c < dot)
//                 {
//                     d = dot - c;
//                     tmp = (temp[c] - 48);
//                     while (d--)
//                     {
//                         tmp *= 10;
//                     }
//                     val += tmp;
//                 }
//                 else if (c == '.') continue;
//                 else
//                 {
//                     d = c - dot;
//                     tmp = (temp[c] - 48);
//                     while(d--)
//                     {
//                         tmp /= 10;
//                     }
//                     val += tmp;
//                 }
//             }
//             db.push(val);
//         }
//     }
//     std::cout << std::fixed;
//     std::cout.precision(2);
//     std::cout << db.top() << std::endl;

//     return;
// }