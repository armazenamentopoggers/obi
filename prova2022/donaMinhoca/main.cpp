#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXN 300000
int dist[MAXN];
int dist2[MAXN];

void bfs(int v, std::vector<std::vector<int>> l, int n) {

    std::queue<int> queue;
    std::vector<bool> visited(n + 1, false);
    queue.push(v);

    while (!queue.empty()) {
        int curr = queue.front();
        visited[curr] = true;
        queue.pop();

        for (int i = 0; i < l[curr].size(); i++) {
            if (!visited[l[curr][i]]) {
                dist[l[curr][i]] = dist[curr] + 1;
                queue.push(l[curr][i]);
            }
        }
    }
}

void bfs2(int v, std::vector<std::vector<int>> l, int n) {

    std::queue<int> queue;
    std::vector<bool> visited(n + 1, false);
    queue.push(v);

    while (!queue.empty()) {
        int curr = queue.front();
        visited[curr] = true;
        queue.pop();

        for (int i = 0; i < l[curr].size(); i++) {
            if (!visited[l[curr][i]]) {
                dist2[l[curr][i]] = dist2[curr] + 1;
                queue.push(l[curr][i]);
            }
        }
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> list(n + 1);

    for (int i = 1; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }

    bfs(1, list, n);

    int max = -1, v = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[v] < dist[i]) {
            max = dist[i];
            v = i;
        }
    }

    bfs2(v, list, n);

    int d = -1;
    for (int i = 1; i <= n; i++) {
        d = std::max(d, dist2[i]);
    }
    std::cout << (d/(2*k));
}