#include <iostream>
using namespace std;

bool minus_button;
int make_int;
int result;

void go_result()
{
    if (minus_button)
        result -= make_int;
    else
        result += make_int;
    
    make_int = 0;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;

    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        if ('0' <= str[i] && str[i] <= '9') {
            make_int *= 10;
            make_int += str[i] - '0';
        }

        else {
            go_result();
            if (str[i] == '-')
                minus_button = true;
        }
    }
    go_result();

    cout << result << '\n'; 

    return 0;
}