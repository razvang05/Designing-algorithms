#include <bits/stdc++.h>
#include <algorithm>
#include <iomanip>
#include <cmath>

#define MOD 1000000007

using namespace std;

class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    int k;
    // vector of pairs for number and type
    vector<pair<long long, char>> vect;
    int num;
    char type;


    void read_input() {
        ifstream fin("colorare.in");
        fin >> k;
        for (int i = 0; i < k; i++) {
            fin >> num >> type;
            vect.push_back({num, type});
        }

        fin.close();
    }

    // increase to power in logarithmic time
    long long powmod(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }

        return result;
    }

    long long get_result() {
        long long res = 1;
        char pre_type = vect[0].second;
        long long num = vect[0].first;

        // calculate the number of possibilities for the first section
        // if it is horizontal, we have 6 * 3^(num-1)
        // if it is vertical, we have 3 * 2^(num-1)
        if (pre_type == 'H') {
            res = 6 * powmod(3, num - 1) % MOD;
        } else {
            res = 3 * powmod(2, num - 1) % MOD;
        }
        char type;

        for (int i = 1; i < k; i++) {
            type = vect[i].second;
            num = vect[i].first;
            // go through the data and check if the previous type
            // is equal to the current one and checks if it is H or V
            // to know what formula I apply
            if (pre_type == type) {
                if (type == 'V') {
                    res = res * powmod(2, num) % MOD;
                } else {
                    res = res *  powmod(3, num) % MOD;
                }
            // if the type changes, the formula also changes
            } else {
                if (type == 'V') {
                    res = res * powmod(2, num - 1) % MOD;
                } else {
                    res = res * 2 * powmod(3, num - 1) % MOD;
                }
            }
            pre_type = type;
        }
        return res;
    }

    void print_output(long long result) {
        ofstream fout("colorare.out");
        fout<<result;
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
