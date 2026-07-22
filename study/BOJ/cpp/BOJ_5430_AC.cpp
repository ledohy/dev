#include <iostream>
#include <deque>
using namespace std;

deque<int> dq;
bool error, rev;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
       
    string order, arr;
    int t, len, make_int;
    
    cin >> t;
    while (t--) {
        rev = false;
        error = false;
        cin >> order >> len >> arr;
        
        dq.clear();
        make_int = 0;
        if (len != 0) {
            for (int i = 0; i < arr.length(); i++) {
                if (arr[i] == ',' || arr[i] == ']') {
                    dq.push_back(make_int);
                    make_int = 0;
                }
                else if ('0' <= arr[i] && arr[i] <= '9') {
                    make_int *= 10;
                    make_int += arr[i] - '0';
                }
                else
                    continue;
            }
        }
        
        for (int i = 0; i < order.length(); i++) {
            if (order[i] == 'R') 
                rev = 1 - rev;
            else {
                if (dq.empty()) error = true;
                else if (rev) dq.pop_back();
                else          dq.pop_front();
            }
        }
        
        if (error)
            cout << "error\n";
        else {
            cout << '[';
            if (!rev) {
                for (int i = 0; i < dq.size(); i++) {
                    cout << dq[i];
                    if (i != dq.size() - 1)
                        cout << ',';
                }
            }
            else {
                for (int i = dq.size()-1; i >= 0; i--) {
                    cout << dq[i];
                    if (i != 0)
                        cout << ',';
                }
            }
            cout << ']' << '\n';
        }
    }
}