// Comentário NOIC - OBI Fase 3 P1 e P2 - Festa
// Complexidade: O(M + Nlog N)
// Escrito por Pedro Racchetti

#include<bits/stdc++.h>
using namespace std;
#define esq(x) x << 1 
#define dir(x) (x<<1) | 1
#define mid(x,y,t) ((x+y)>>1) + t

typedef long long ll;
const int MAXM  =5e3 + 10;
const int MAXN = 4e5 + 10;
ll n, m;
set<int> s;
int val[MAXM];

int seg[4*MAXN];
// construímos a Segment Tree, inicializando todas as posições como 1.
void build(int node, int x, int y){
	if(x == y){
		seg[node] = 1;
		return;
	}
	build(esq(node), x, mid(x,y,0));
	build(dir(node), mid(x,y,1), y);
	seg[node] = seg[esq(node)] + seg[dir(node)];
}

// a operação de update nessa árvore apenas muda o valor de uma posição para 0
void update(int node, int x, int y, int id){
	if(x > id || y < id) return;
	if(x == y){
		seg[node] = 0;
		return;
	}
	update(esq(node), x, mid(x,y,0), id);
	update(dir(node), mid(x,y,1), y, id);
	seg[node] = seg[esq(node)] + seg[dir(node)];
}


// na busca binária, encontramos qual é a i-ésima posição ativa
// ou seja, qual o valor do i-ésimo elemento na fila.
int bb(int node, int x, int y, int val){
	if(x==y) return x;
	if(seg[esq(node)] >= val) return bb(esq(node), x, mid(x,y,0), val);
	return bb(dir(node), mid(x,y,1), y, val - seg[esq(node)]);
}

int main(){
	scanf("%lld", &n);
	scanf("%lld", &m);
	for(int i = 1; i <= m; i++){
		scanf("%d", &val[i]);
	}
	
	build(1,1,n);

	// natual é uma variável auxiliar
	// que guarda o tamanho atual da fila.
	int natual = n;

	for(int i = 1; i <= m; i++){
		vector<int> toremove;
		// mais uma vez, para se manter a posição original,
		// pré-computamos as posições a serem removidas
		// e apenas depois as removemos.
		for(int j = val[i]; j <= natual; j+= val[i]){
			toremove.push_back(bb(1,1,n, j));
		}
		// como a árvore não muda de tamanho, não precisamos
		// percorrer o vetor de trás para frente.
		for(int v: toremove){
			update(1,1,n, v);
		}
		// atualizamos natual para o total de posições ativas,
		// que é exatamente o tamanho da fila.
		natual = seg[1];
	}
	for(int i = 1; i <= min(natual, 10000); i++){
		printf("%d\n", bb(1,1,n,i));
	}

}