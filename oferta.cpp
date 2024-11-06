#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    int n, k;
    vector<int> vect1;


    void read_input() {
        ifstream fin("oferta.in");
        fin >> n;
        fin >> k;
        for (int i = 0, elem; i < n; i++) {
            fin >> elem;
            vect1.push_back(elem);
        }

        fin.close();
    }

    double get_result() {
        vector <double> cost(n + 1, 0.0);

        for (int i = 1; i <= n; i++) {
            // calculate the price if the product is alone
            cost[i] = cost[i - 1] + vect1[i - 1];

            if (i >= 2) {
                // we find the cheaper product
                int minn = min(vect1[i - 1], vect1[i - 2]);
                int sum = vect1[i - 1] + vect1[i - 2];
                // calculate the discount price
                double price_discount  = cost[i - 2] + sum - minn * 0.5;
                // we find the minimum price
                cost[i] = min(cost[i], price_discount);
            }
            // we calculate for 3 products
            if (i >= 3) {
                // we calculate from the 3 most expensive 2 products
                int first = vect1[i - 3];
                int second;
                if (first > vect1[i - 2]) {
                     second = max(vect1[i - 2], vect1[i - 1]);
                } else {
                    first = vect1[i - 2];
                    second = max(vect1[i - 3], vect1[i - 1]);
                }
                // we calculate the price with a discount, without a minimum
                double price_discount = cost[i - 3] + first + second;
                // do the minimum between the prices
                cost[i] = min(cost[i], price_discount);
            }
        }
        return cost[n];
    }

    void print_output(double result) {
        ofstream fout("oferta.out");
        fout <<fixed<<setprecision(1)<< result;
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
