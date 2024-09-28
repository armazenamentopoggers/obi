#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int l, c, p, preto[8][8], dp[8][(1<<8)];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> l >> c >> p;
    for(int i = 1; i <= p; i++) {
        int x,y; cin >> x >> y;
        x--; y--; //diminuo em 1 para fazer 0-indexado
        preto[x][y] = 1;
    }

    for(int i = 0; i < l; i++) {
        for(int mask = 0; mask < (1<<c); mask++) {
            dp[i][mask] = 0;
            bool validomask = true;

            for(int j = 0; j < c; j++) {
                if(j+1 <= c-1 && ((1<<j)&mask) != 0 && ((1<<(j+1))&mask) != 0) {
                    validomask = false;
                    continue;
                }
                if(((1<<j)&mask) != 0 && preto[i][j] == 1) {
                    validomask = false;
                    continue;
                }
                bool validoj = false;
                if(i-1 >= 0 && preto[i-1][j] == 1) validoj = true;
                if(i+1 <= l-1 && preto[i+1][j] == 1) validoj = true;
                if(j-1 >= 0 && preto[i][j-1] == 1) validoj = true;
                if(j+1 <= c-1 && preto[i][j+1] == 1) validoj = true;
                
                if(validoj == false && ((1<<j)&mask) != 0) validomask = false;
            }
            if(validomask == false) continue;

            int qtdbranco = 0;
            for(int j = 0; j < c; j++) {
                if((1<<j)&mask) qtdbranco++;
            }

            if(i == 0) {
                dp[i][mask] = qtdbranco;
                continue;
            }

            for(int mask1 = 0; mask1 < (1<<c); mask1++) {
                bool validomask1 = true;
                for(int j = 0; j < c; j++) {
                    if(((1<<j)&mask1) != 0 && ((1<<j)&mask) != 0) validomask1 = false;
                }
                if(validomask1) dp[i][mask] = max(dp[i][mask],dp[i-1][mask1]+qtdbranco);
            }
        }
    }

    int ans = 0;
    for(int mask = 0; mask < (1<<c); mask++) {
        ans = max(ans,dp[l-1][mask]);
    }
    cout << ans << endl;
}