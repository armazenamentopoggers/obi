//resposta noic

#include<bits/stdc++.h>
using namespace std;
const int inf =  1e9 + 10;
const int maxn = 2e4;

int e, r, mark[maxn], esta[maxn], ate[maxn], Tciclo[maxn], Tcaminho;
vector<int> caminho;
vector<pair<int,int>> g[maxn];

void dfs(int u, int anterior) {
    mark[u] = 1;
    esta[u] = 1;
    ate[u] = Tcaminho;
    caminho.push_back(u);

    for(auto V : g[u]) {
        int v = V.first;
        int w = V.second;
        if(esta[v] && v != anterior) {
            while(true) {
                Tciclo[caminho.back()] = ate[u]-ate[v]+w;
                esta[caminho.back()] = 0;
                if(caminho.back() == v) {
                    caminho.pop_back();
                    break;
                }
                caminho.pop_back();
            }
        }
        else if(mark[v] == 0) {
            Tcaminho+= w;
            dfs(v,u);
            Tcaminho-= w;
        }
    }

    if(esta[u]) {
        esta[u] = 0;
        caminho.pop_back();
    }
}

int32_t main() {
    cin >> e >> r;
    for(int i = 1; i <= r; i++) {
        int a,b,c; cin >> a >> b >> c;
        g[a].push_back(make_pair(b,c));
        g[b].push_back(make_pair(a,c));
    }

    for(int i = 1; i <= e; i++) {
        if(mark[i] == 0) dfs(i,0);
    }

    int k;
    cin >> k;
    while(k--) {
        int x,t;
        cin >> x >> t;
        int distancia[e+10];
        for(int i = 1; i <= e; i++) {
            distancia[i] = inf;
        }
        distancia[x] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push(make_pair(0,x));
        while(pq.size()) {
            int u = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            if(dis != distancia[u]) continue;
            
            for(auto V : g[u]) {
                int v = V.first;
                int w = V.second;
                if(distancia[v] > distancia[u]+w) {
                    distancia[v] = distancia[u]+w;
                    pq.push(make_pair(distancia[v],v));
                }
            }
        }

        int resposta = inf;
        for(int i = 1; i <= e; i++) {
            if(distancia[i] != inf && Tciclo[i] >= t) {
                resposta = min(resposta, 2*distancia[i]+Tciclo[i]);
            }
        }

        if(resposta == inf) cout << -1 << endl;
        else cout << resposta << endl;
    }

}
