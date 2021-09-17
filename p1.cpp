#include <bits/stdc++.h>
using namespace std;

const int kMod = 1e9 + 7;

struct Object {
    int xStart;
    int xEnd;

    Object(int _xStart, int _xEnd) : xStart(_xStart), xEnd(_xEnd) {}
};

class Task {
 public:
    void solve() {
        int x = 0;
        ofstream fout("p1.out");
        fout << fixed << x;
        fout.close();
    }
};

int main() {
    Task *task = new Task();
    task->solve();
    delete task;
    return 0;
}
