#include <iostream>
#include <vector>
#include <map>

int main() {
    int n, l, m, res = 0;
    std::cin >> n >> l >> m;

    //std::vector<std::pair<int, int>> list;
    std::vector<std::pair<int, int>> cres;
    std::vector<std::pair<int, int>> des;
    std::vector<int> cons;

    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        if (a == 0) {
            cons.push_back(b);
        } else if (a < 0) {
            des.push_back({a, b});
        } else {
            cres.push_back({a, b});
        }
    }

    // for (int i = 0; i < list.size(); i++) {
    //     int a = list[i].first, b = list[i].second;
    //     for (int j = i + 1; j < list.size(); j++) {
    //         int c = list[j].first, d = list[j].second;
    //         int z = (a - c);
    //         if (z == 0) continue;
    //         int op = (d - b) / (a - c);
    //         if (op >= l && op <= m) {
    //             res++;
    //         }
    //     }
    // }

    for (int i = 0; i < cons.size(); i++) {
        for (int j = 0; j < cres.size(); j++) {
            int a = cres[j].first, b = cres[j].second;
            int op = (cons[i] - b) / a;
            if (op >= l && op <= m) {
                res++;
            }
        }
        for (int j = 0; j < des.size(); j++) {
            int a = des[j].first, b = des[j].second;
            int op = (cons[i] - b) / a;
            if (op >= l && op <= m) {
                res++;
            }
        }
    }

    for (int i = 0; i < cres.size(); i++) {
        int a = cres[i].first, b = cres[i].second;
        for (int j = 0; j < des.size(); j++) {
            int c = des[j].first, d = des[j].second;
            int z = (a - c);
            if (z == 0) continue;
            int op = (d - b) / (a - c);
            if (op >= l && op <= m) {
                res++;
            }
        }
    }

    std::cout << res;
}