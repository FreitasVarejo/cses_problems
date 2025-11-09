#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;

typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr);

void solve(){
	ll n; cin >> n;

	if(4 > n){
		if(n==1) cout << 1;
		else cout << "NO SOLUTION";
		return;
	}

	ll l = (n%2==0)?n:n-1;
	ll r = (n%2==0)?n-1:n;
	
	while(l > 4){
		cout << l << ' ';
		l -= 2;
	}

	cout << "2 4 1 3 ";

	ll i = 5;

	while(r >= i){
		cout << i << ' ';
		i += 2;
	}
	
}

int main(){_
    int o = 1;
    //cin >> o;

    while(o--){
        solve();
    }

    return  0;
}
