#include <bits/stdc++.h>

using namespace std;

// Regular show
#define import python
#define mid ((l+r)>>1)
#define sz(x) ((int)x.size())
#define fin freopen ("in.txt","r",stdin);
#define fout freopen ("out.txt","w",stdout);
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
// Rapadura é doce, mas não é mole não.
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
// I see you
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<ll> vll;
// priority_queue<int,vi,greater<int>> pq;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
static const ll M = (1LL << 61) - 1;
static const ll B = uniform_int_distribution<ll>(257, M - 1)(rng);
vector<ll> pot = {1};
__int128 mul(ll a, ll b) { return (__int128)a * b; }
ll mod_mul(ll a, ll b) { return mul(a, b) % M; }
vector<ll> p_hash, hs;

void hash_(string &s) {
  p_hash = vector<ll> (sz(s)+1);
  while (sz(pot) <= sz(s)) { pot.push_back(mod_mul(pot.back(), B)); }
  p_hash[0] = 0;
  for (int i = 0; i < sz(s); i++) {
    p_hash[i + 1] = (mul(p_hash[i], B) + s[i]) % M;
  }
}

ll get_hash(int start, int end) {
  ll raw_val = p_hash[end + 1] - mod_mul(p_hash[start], pot[end - start + 1]);
  return (raw_val + M) % M;
}

ll get_hash2(int start, int end){
  ll raw_val = hs[end + 1] - mod_mul(hs[start], pot[end - start + 1]);
  return (raw_val + M) % M;
}

void fileIO(string filename) {
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
}

int main(){
  
  fast;
  fileIO("censor");
  string a, b, s; cin >> a >> b;
  hash_(b);
  hs = vector<ll>(sz(a)+1);
  while (sz(pot) <= sz(a)) { pot.push_back(mod_mul(pot.back(), B)); }
  int i=0, j=0;
  hs[0] = 0;
  for(;j<sz(a);j++){
    s+=a[j];
    hs[i + 1] = (mul(hs[i], B) + a[j]) % M;
    if(i>=sz(b)-1 && (get_hash(0,sz(b)-1)==get_hash2(i-sz(b)+1, i))){
      for(int k=0;k<sz(b);k++) s.pop_back();
      i = i-sz(b)+1;
    }
    else i++;
  }
  cout << s << "\n";
}
