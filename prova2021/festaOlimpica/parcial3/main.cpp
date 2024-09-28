// Comentário NOIC - OBI Fase 3 P1 e P2 - Festa
// Complexidade: O(M)
// Escrito por Pedro Racchetti
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
// Como N e M podem ser bem grandes, usamos long long
ll n, m;

int main(){
	scanf("%lld", &n);
	scanf("%lld", &m);
	if(m > 31){
		printf("1\n");
		return 0;
	}
	ll aux1 = (1<<m);
	ll a1 = 1, cnt = 1;
	// Basta passar por todos os números da forma 2^M + 1,
	// garantindo que não se imprima mais que 10000 números.
	while(a1 <= n && cnt <= 10000){
		printf("%lld\n", a1);
		cnt++;
		a1 += aux1;
	}
}