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

    for (auto & [keyOne, valueOne] : map) {
        int res = 1e9, aux;
        for (auto & [keyTwo, valueTwo] : map) {
            if (keyOne != keyTwo && keyTwo > keyOne) {
                if (((keyTwo - keyOne) * valueOne) < res) {
                    res = ((keyTwo - keyOne) * valueOne);
                    aux = keyTwo;
                }
            }
        }
        dp.insert({res, {aux, keyOne}});
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