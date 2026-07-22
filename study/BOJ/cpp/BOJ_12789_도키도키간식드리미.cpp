// #include <iostream>
// #include <queue>
// #include <stack>
// using namespace std;

// queue<int> q;
// stack<int> s;

// int main(void) {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, input;
//     bool success = true;
//     cin >> n;

//     for (int i = 1; i <= n; i++) {
//         cin >> input;
//         q.push(input);
//     }

//     for (int i = 1; i <= n; i++) {
//         int tmp = 0;
//         if (!q.empty()) {
//             if (q.front() == i) {
//                 q.pop();
//                 continue;
//             }
//             else {
//                 tmp = q.front(); q.pop();
//             }
//         }
//         if (!s.empty() && s.top() == i) {
//             s.pop();
//             continue;
//         }
//         if (tmp != 0) s.push(tmp);
//         if (s.empty()) success = false;
//     }

//     if (success)
//         cout << "Nice\n";
//     else
//         cout << "Sad\n";

//     return 0;
// }
#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    stack<int> st;
    int want = 1;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (x == want) {
            want++;
        } else {
            st.push(x);
        }

        while (!st.empty() && st.top() == want) {
            st.pop();
            want++;
        }
    }

    if (want == N + 1)
        cout << "Nice\n";
    else
        cout << "Sad\n";

    return 0;
}