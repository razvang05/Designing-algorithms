#include <bits/stdc++.h>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

class Task {
 public:
    void solve() {
        read_input();
        print_output();
    }

 private:
    int n;
    vector<int> p;
    vector<int> c;


    void read_input() {
        ifstream fin("servere.in");
        fin >> n;
        for (int i = 0, elem; i < n; i++) {
            fin >> elem;
            p.push_back(elem);
        }

        for (int j = 0, elem; j < n; j++) {
            fin >> elem;
            c.push_back(elem);
        }

        fin.close();
    }

    double pow_min(const vector<int>& p, const vector<int>& c, double current) {
        double pow_minn = 1e9;
        for (unsigned int i = 0; i < p.size(); i++) {
            // calculate the minimum power as per the formula
            double pow_aux = p[i] - abs(current - c[i]);
            pow_minn = min(pow_minn, pow_aux);
        }
        return pow_minn;
    }

    double search_current(const vector<int>& p, const vector<int>& c) {
        double max_current = c[0] - p[0];
        double min_current = c[0] + p[0];

        for (unsigned int i = 0; i < p.size(); i++) {
            // calculate the upper and lower limit
            // which maximizes the power of the current
            double maxx = double(c[i] - p[i]);
            double minn = double(c[i] + p[i]);
            min_current = min(min_current, minn);
            max_current = max(max_current, maxx);
        }
        // calculate the current as the arithmetic mean
        // which can maximize the minimum power of the servers
        double res = (min_current + max_current) / 2.0;
        return res;
    }

    void print_output() {
        ofstream fout("servere.out");
        double currentoptim = search_current(p, c);
        fout << fixed <<setprecision(1) <<pow_min(p, c, currentoptim);
        fout.close();
    }
};


int main() {
    auto* task = new (nothrow) Task();
    if (!task) {
        cerr << "new failed: WTF are you doing? Throw your PC!\n";
        return -1;
    }
    task->solve();
    delete task;
    return 0;
}
