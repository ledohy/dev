#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C, D;
    cin >> A >> B >> C >> D;
    bool Shu = 0;
    bool Walk = 0;

    if (A+B <= D) Shu = 1;
    if (C <= D) Walk = 1;

    if (Shu && Walk)
        cout << "~.~\n";
    else if (!Shu && !Walk)
        cout << "T.T\n";
    else {
        if (Shu) cout << "Shuttle\n";
        else cout << "Walk\n";
    }
    return 0;
}