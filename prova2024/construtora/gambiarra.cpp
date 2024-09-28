#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

int main() {
    int n, res = 0;
    std::cin >> n;

    std::multimap<int, int> map;
    std::set<int> set;

    int past = 0, qtd = 1, max = 0;
    for (int i = 0; i < n; i++) {
        int aux;
        std::cin >> aux;

        if (i == 0) {
            past = aux;
            continue;   
        }
        if (aux == past) {
            qtd++; 
        } else {
            map.emplace(past, qtd);
            set.emplace(past);
            max = std::max(max, past);
            past = aux;
            qtd = 1;
        }
    }
    map.emplace(past, qtd);
    set.emplace(past);
    max = std::max(max, past);

    for (auto & s : set) {
        bool used = false;
        for (auto & t : set) {
            if (s != max && s < t && !used) {
                int freq = map.count(s);
                int diff = t - s;
                res += freq * diff;
                used = true;
            }
        }
    }
    std::cout << res;
}

// 8
// 5 4 4 4 5 4 4 7