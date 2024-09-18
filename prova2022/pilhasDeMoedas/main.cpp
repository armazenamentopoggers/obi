#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    int n, k, ans = 0;
    std::cin >> n >> k;

    std::map<int, int> map;
    std::multimap<int, std::pair<int, int>> dp;

    for (int i = 0; i < n; i++) {
        int aux;
        std::cin >> aux;
        map[aux]++;
    }

    std::map<int, int>::iterator it;
    for (it = map.begin(); it != map.end();) {
        int a = (*it).first;
        if (++it == map.end()) continue;
        int b = (*it).first;
        int diff = b - a;
        dp.insert({diff, {b, a}});
    }

    while (map.size() != k) {
        std::multimap<int, std::pair<int, int>>::iterator it = dp.begin();
        int key = (*it).first, valueTwo = (*it).second.first, valueOne = (*it).second.second;
        ans += key * map[valueOne];
        map.erase(valueOne);
        map[valueTwo]++;
        dp.erase(dp.find(key));
    }
    std::cout << ans;
    return 0;
}