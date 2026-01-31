#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;

typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
#define vll vector<ll>

#define _ ios::sync_with_stdio(false); cin.tie(nullptr);

void solve(){
	ll n; cin >> n;

	if(n%4==3 || n%4 == 0){
		cout << "YES" << endl;

		vll a, b;
		
		for(int i = 1; n >= i; i++){
			if(n%4 == 3 && (i%4 == 1 || i%4 == 2) ||
			 n%4 == 0 && (i%4 == 1 || i%4 == 0 ))
				a.emplace_back(i);
			else
				b.emplace_back(i);
		}

		cout << a.size() << endl;
		for(auto x:a)
			cout << x << " ";
		cout << endl;	

		cout << b.size() << endl;
		for(auto x:b)
			cout << x << " ";
		cout << endl;	
		return;	
	}

	cout << "NO" << endl;

}

int main(){_
    int o = 1;
    //cin >> o;

    while(o--){
        solve();
    }

    return  0;
}
