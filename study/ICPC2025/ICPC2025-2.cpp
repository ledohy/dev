#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input = "";
    string temp = "";
    string result = "";
    
    cin >> input;

    int len = (int)input.length();

    if(len % 2 == 1)
    {
        cout << "-1";
        return 0;
    }

    if (len == 2)
    {
        for (int i = 0; i < input[0] - '0'; i++)
            temp = temp + input[1];
        

        if (temp[0] == '0')
        {
            cout << -1;
            return 0;
        }
        cout << temp;

        return 0;
    }
    
    for (int i = 3; i < len; i+=2)
    {
        if (input[i - 2] == input[i])
        {
            cout << "-1";
            return 0;
        }
    }

    for (int i = 0; i < len; i+=2)
    {
        int idx = input[i] - '0';

        if (idx == 0)
        {
            cout << "-1";
            return 0;
        }

        for (int j = 0; j < idx; j++)
            temp = temp + input[i+1];
    }

    if (temp[0] == '0')
    {
        cout << -1;
        return 0;
    }
    cout << temp;

    return 0;
}
