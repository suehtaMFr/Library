#include <bits/stdc++.h>
 
using namespace std;
 
//Regular show
#define sz(x) ((int)x.size())
#define fin freopen ("input.txt","r",stdin);
#define fout freopen ("output.txt","w",stdout);
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
//rapadura é doce, mas não é mole não
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
//I see you
std::mt19937 rng((int) std::chrono ::steady_clock::now().time_since_epoch().count());
std::mt19937_64 rng64((int) std::chrono::steady_clock::now().time_since_epoch().count());
//~ long double pi = 3.141592653589793;

struct aresta{
	int u,v,p;
	bool operator <(aresta const & b){
		return p<b.p;
	}
};

int rannk[220], ft[220];
vector<aresta> lis;

void inic(int n){
	for(int i=0;i<=n;i++) ft[i]=i,rannk[i]=1;
}

int findft(int u){
	if(ft[u]==u) return u;
	return ft[u] = findft(ft[u]);
}

void unionv(int u, int v){
	u = findft(u); v = findft(v);
	if(u==v)return;
	if(rannk[u]>=rannk[v]){ rannk[u]+=rannk[v]+1;ft[v]=u;}
	else { rannk[v]+=rannk[u]+1;ft[u]=v;}
}

int bfs(int u, int v,vector<pair<int,int>> adj[]){
	
	bool vis[220] = {0};
	queue<pair<int,int>> q;
	q.push({u,INT_MAX});
	while(!q.empty()){
		pair<int,int> x = q.front(); q.pop();
		if(x.ff==v) return x.ss;
		for(auto e:adj[x.ff]){
			if(!vis[e.ff]){
				vis[e.ff]=1;
				q.push({e.ff,min(x.ss,e.ss)});
			}
		}
	}
	return -1;
}

int main () {
	
	fast;
	int c, s, v=0;
	while(cin >> c >> s && (c || s)){
		map<string,int> mp;
		vector<pair<int,int>> adj[c+1];
		string x, y;
		for(int i=0, a, b, z, c=0;i<s;i++){
			cin >> x >> y >> z;
			if(mp.count(x)){
				a=mp[x];
			}
			else {a=c;mp[x]=c++;}
			if(mp.count(y)){
				b=mp[y];
			}
			else {b=c;mp[y]=c++;}
			lis.pb({a,b,z});
		}
		inic(c);
		sort(all(lis));
		for(int i=s-1;i>=0;i--){
			aresta a = lis[i];
			if(findft(a.u)!=findft(a.v)){
				unionv(a.u,a.v);
				adj[a.u].pb({a.v,a.p});
				adj[a.v].pb({a.u,a.p});
			}
		}
		cout << "Scenario #" << ++v << "\n";
		cin >> x >> y;
		cout << bfs(mp[x],mp[y],adj) << " tons\n\n";
		lis.clear();
	}
}
