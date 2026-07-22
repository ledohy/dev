#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> idx;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    int n, m, count{0};
    cin >> n >> m >> str;
    string target_str = "I";
    for (int i = 0; i < n; i++) target_str.append("OI");
    int target_len = target_str.length();
    for (int i = 0; i < m; i++) 
        if (str[i] == 'I') idx.push_back(i);
    for (int& it : idx) 
        if (str.substr(it, target_len) == target_str) count++;
    cout << count << '\n';

    return 0;
}