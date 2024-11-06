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
    int n, m;
    vector<int> vect1;
    vector<int> vect2;


    void read_input() {
        ifstream fin("compresie.in");
        fin >> n;
        // read elements
        for (int i = 0, elem; i < n; i++) {
            fin >> elem;
            vect1.push_back(elem);
        }

        fin >> m;
        for (int j = 0, elem; j < m; j++) {
            fin >> elem;
            vect2.push_back(elem);
        }

        fin.close();
    }

    int binary_search(const vector<int>& vec, int val) {
        int left = 0;
        int right = vec.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (vec[mid] == val) {
                return 1;
            }
            if (vec[mid] < val) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }

    int get_result() {
        vector<int> sum_vect1;
        int sum1 = 0, res = 0;

        // do the sums one by one for the first vector
        // first + second
        // (first + second) + third
        for (int elem : vect1) {
            sum1 = sum1 + elem;
            sum_vect1.push_back(sum1);
        }

        // loop through the elements of the vector in turn
        // do the sums as in the first vector and check
        // with binary search if it is in the sums of the first vector
        int sum2 = 0;
        for (int elem : vect2) {
            sum2 = sum2 + elem;

            if (binary_search(sum_vect1, sum2) == 1) {
                res++;
            }
        }
        // if the amounts are different, we return -1
        if (sum1 != sum2) {
            return -1;
        }

        return res;
    }

    void print_output(int res) {
        ofstream fout("compresie.out");
        fout << res;
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
