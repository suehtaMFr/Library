#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define sz(x) ((int)x.size())

int main (){
  ll y, k, x = 1; cin >> y >> k;
  for(ll i=0;i<k;i++){
    x += __gcd(x,y);
  }
  cout << x << "\n";
}

