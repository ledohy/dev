#include <iostream>
#define X first
#define Y second
using namespace std;

pair< pair<int,int>, pair<int,int> > cur;
pair<int,int>* p = &cur.X;
int most;



void button()
{ p = (p == &cur.Y) ? &cur.X : &cur.Y; }

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, input;
    int total{0};

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;

        if (input == p->X) {
            p->Y++;
            total++;
            continue;
        }
        else
            button();


        if (input == p->X) {
            p->Y = 1;
            total++;
            continue;
        }
        else {
            if (most < total)
                most = total;
            
            *p = { input, 1 };

            total = cur.X.Y + cur.Y.Y;
        }
    }
    if (most < total)
        most = total;

    cout << most << '\n';

    return 0;
}