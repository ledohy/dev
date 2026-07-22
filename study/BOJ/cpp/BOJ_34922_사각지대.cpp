#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double coef = 3.141592 / 4;
    double w, h, r;
    double sight;
    cin >> w >> h >> r;
    sight = r * r * coef;
    cout << w * h - sight << '\n';

    return 0;
}