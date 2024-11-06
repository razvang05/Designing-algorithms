#include <bits/stdc++.h>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    int N;
    // vector to store the words
    vector<string> words;
    // maxim length of the word combination for each letter
    map<char, int> max_length;

    void read_input() {
        ifstream fin("criptat.in");
        fin >> N;
        words.resize(N);

        for (int i = 0; i < N; ++i) {
            fin >> words[i];
        }
        fin.close();
    }

    // calculate the frequency for each character in the word
    vector<map<char, int>> calculate_freq(int N) {
        vector<map<char, int>> frequencies(N);
        for (int i = 0; i < N; i++) {
            for (char ch : words[i]) {
                frequencies[i][ch]++;
            }
        }
        return frequencies;
    }
    // calculate the maximum length of a password
    int MaxPasswordLength(char ch_dominant,
                                    vector<map<char, int>>& frequencies) {
        int N = words.size();
        vector<int> dp(10001, 0);

        for (int i = 0; i < N; i++) {
            int word_length = words[i].size();
            int ch_count = frequencies[i][ch_dominant];

            // go backwards so as not to count the same word more once
            for (int j = 10000 - word_length; j >= 0; j--) {
                if (dp[j] == 0 && j != 0) {
                    continue;
                }
                dp[j + word_length] = max(dp[j + word_length], dp[j]
                                                    + ch_count);
            }
        }

        // look for the maximum length that respects the dominant letter
        for (int i = 0; i <= 10000; i++) {
            if (dp[i] > i / 2) {
                max_length[ch_dominant] = max(max_length[ch_dominant], i);
            }
        }

        return max_length[ch_dominant];
    }

    int get_result() {
        vector<map<char, int>> frequencies = calculate_freq(N);
        // we go through all the letters
        int result = 0;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            result = max(result, MaxPasswordLength(ch, frequencies));
        }

        return result;
    }

    void print_output(int result) {
        ofstream fout("criptat.out");
        fout << result;
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
