//meia boca

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int const MAXN = 50100;
int dist[MAXN], d = 0, qtd = 0;
std::vector<bool> visitedDfs(MAXN, false);

void bfs(int v, int n, std::vector<std::vector<int>> g) {
    std::queue<int> queue;
    std::vector<bool> visited(n + 1, false);
    queue.push(v);

    while (!queue.empty()) {
        int aux = queue.front();
        queue.pop();
        visited[aux] = true;

        for (int i = 0; i < g[aux].size(); i++) {
            int curr = g[aux][i];
            if (!visited[curr]) {
                queue.push(curr);
                visited[curr] = true;
                dist[curr] = dist[aux] + 1;
            }
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> graph(n + 1);

    for (int i = 1; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs(1, n, graph);

    int max = -1, v = 0, multi = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > max) {
            max = dist[i];
            v = i;
        }
    }
    for (int i = 0; i <= n; i++) {
        if (dist[i] == max) multi++;
        dist[i] = 0;
    }

    bfs(v, n, graph);
    
    for (int i = 1; i <= n; i++) {
        if (dist[i] > d) {
            d = dist[i];
            qtd++;
        }
    }
    d++;
    
    std::cout << d << std::endl << qtd*multi;
}