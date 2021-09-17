#include <bits/stdc++.h>
using namespace std;

const int kNmax = 100000;

class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    int n;
    int m;
    int source;
    int dest;
    vector<pair<int, int> > adj[kNmax];

    // Citesc input
    void read_input() {
        ifstream fin("p2.in");
        fin >> n >> m >> source >> dest;
        for (int i = 1, x, y, w; i <= m; i++) {
            fin >> x >> y >> w;
            adj[x].push_back(make_pair(y, w));
        }
        fin.close();
    }

    vector<int> get_result() {
        vector<int> distanta(n + 1, 9999999);
        queue<int> coada;
        int nodCurent;
        distanta[source] = 0;
        coada.emplace(source);
        while (!coada.empty()) {
            nodCurent = coada.front();
            // Pentru fiecare nod vecin cu nodul curent
            for (const auto& nodU : adj[nodCurent]) {
                int num = distanta[nodCurent] + nodU.second;
                // Daca am gasit un drum mai bun actualizez valoarea
                if (distanta[nodU.first] > num) {
                    distanta[nodU.first] = num;
                    coada.emplace(nodU.first);
                }
            }
            coada.pop();
        }
        return distanta;
    }
    // Printez solutia
    void print_output(vector<int> result) {
        ofstream fout("p2.out");
        fout << result[dest];;
        fout.close();
    }
};

int main() {
    Task *task = new Task();
    task->solve();
    delete task;
    return 0;
}
