#include <bits/stdc++.h>
using namespace std;

const int kNmax = 100000;

struct triplet {
    int x, y, z;
    triplet(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};

class Task {
 public:
    void solve() {
        read_input();
        get_result();
    }

 private:
    int n;
    int m;
    double energie;
    int nod_start = 1;
    int source;
    vector<pair<int, int> > adj[kNmax];
    vector<triplet> raspuns;

    void read_input() {
        ifstream fin("p3.in");
        fin >> n >> m >> energie;
        source = 1;
        for (int i = 1, x, y, w; i <= m; i++) {
            fin >> x >> y >> w;
            adj[x].push_back(make_pair(y, w));
        }
        fin.close();
    }
    vector<int> get_result() {
        double eng_consumata = 1.0;
        int crtNode;
        vector<int> distanta(n + 1, 999999);
        vector<int> cale(n+1, -1);
        cale[0] = -1;
        cale[source] = 0;

        auto cmp = [&distanta](int x, int y) {
            return distanta[x] > distanta[y];
        };

        priority_queue<int, vector<int>, decltype(cmp)> coadaP(cmp);
        distanta[source] = 0;
        coadaP.emplace(source);

        while (!coadaP.empty()) {
            crtNode = coadaP.top();
            // pentru fiecare nod vecin cu nodul curent
            for (const auto& nodU : adj[crtNode]) {
                int val = nodU.second + distanta[crtNode];
                // Daca am gasit un drum mai bun actualizez valoarea minima
                if (distanta[nodU.first] > val) {
                    distanta[nodU.first] = val;
                    coadaP.emplace(nodU.first);
                    cale[nodU.first] = crtNode;
                    raspuns.push_back(triplet(crtNode,
                            nodU.first, nodU.second));
                }
            }
            coadaP.pop();
        }

        int finish = n;
        for (int i = raspuns.size() - 1; i >= 0; i--) {
            if (raspuns[i].x == cale[finish] && raspuns[i].y == finish) {
                finish = cale[finish];
                energie = energie * (1.0 - (raspuns[i].z/100.0));
            }
        }
        energie *= 1.000;
        cout << fixed << setprecision(4) << energie << '\n';
        prin_cale(cale, n);
        printf("\n");
        return distanta;
    }
    void prin_cale(vector<int> vect, int n) {
        if (vect[n] == 0) {
            printf("%d ", 1);
            return;
        }
        prin_cale(vect,  vect[n]);
        printf("%d ", n);
    }
};

int main() {
    Task *task = new Task();
    task->solve();
    delete task;
    return 0;
}
