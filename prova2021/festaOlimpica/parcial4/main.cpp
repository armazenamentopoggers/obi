// Comentário NOIC - OBI Fase 3 P1 e P2 - Festa
// Complexidade: O(M*Saída)
// Escrito por Pedro Racchetti
#include<bits/stdc++.h>
using namespace std;

const int MAXM = 5e3 + 10;

typedef long long ll;
ll n, m;
ll t[MAXM];
vector<ll> fila;

int main(){
	scanf("%lld", &n);
	scanf("%lld", &m);
	for(int i = 1; i <= m; i++) scanf("%lld", &t[i]);

	// inicializaremos a versão final da fila com números de 1 a n, ou a 10^4
	for(int i = 1; i <= min((ll)1e4, n); i++) fila.push_back(i);

	// agora, efetuaremos as regressões na fila
	for(int i = m; i; i--){
		for(ll j = 0; j < fila.size(); j++){
			fila[j] += (fila[j]-1)/(t[i]-1); // somamos o número de X a posição atual
		}
		while(fila.back() > n) fila.pop_back(); // removemos os excessos, que já passaram de n
	}
	for(ll v : fila) printf("%lld\n", v);
}