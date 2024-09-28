#include <iostream>
#include <vector>
#include <cmath>
#include <complex>

int main() {
    int n, k, t, res = 0;
    std::cin >> n >> k >> t;

    std::vector<int> p(n + 1);
    std::vector<std::pair<int, int>> a;
    std::vector<int> oc;

    for (int i = 1; i <= n; i++) {
        std::cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        int aux;
        std::cin >> aux;
        if (aux == 1) {
            a.push_back({i, p[i]});
        }
    }

    for (auto & it : a) {
        int pos = it.first, val = it.second;
        for (int i = 1; i <= t; i++) {
            int curr = val;
            if (p[pos + i] > curr && pos + i <= p.size()) {
                bool no = true;
                for (auto & o : oc) {
                    if (pos + i == o) no = false; 
                }
                if (no) {
                    it.first = pos + i;
                    curr = it.second = p[pos + i];
                    t--;
                }
            }
            if (p[pos - i] > curr && pos - i >= 1) {
                bool no = true;
                for (auto & o : oc) {
                    if (pos - i == o) no = false; 
                }
                if (no) {
                    it.first = pos - i;
                    curr = it.second = p[pos - i];
                    t--;
                }
            }
        }
        res += it.second;
        oc.push_back(it.first);
    }

    std::cout << res;
}

// 5 2 2
// 4 8 1 5 7
// 1 0 1 0 0

// 4 2 3
// 8 9 1 5
// 0 1 0 1

    // for (auto & it : a) {
    //     int pos = it.first, val = it.second;
    //     for (int i = 1; i <= mov; i++) {
    //         int curr = val;

    //         if (p[pos + i] > curr && pos + i <= p.size()) {
    //             it.first = pos + i;
    //             curr = it.second = p[pos + i];
    //         }
    //         if (p[pos - i] > curr && pos - i >= 1) {
    //             it.first = pos - i;
    //             curr = it.second = p[pos - i];
    //         }
    //     }
    //     res += it.second;
    //     oc.push_back(it.first);
    // }