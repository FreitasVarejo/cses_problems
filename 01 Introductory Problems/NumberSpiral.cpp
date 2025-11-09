#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;

typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr);

ll f(ll a, ll b){
	if(a >= b) return a*a-b+1;
	return (b-1)*(b-1)+a;
}


void solve(){
	
	//for(int i = 1; 7 >= i; i++){
	//	for(int j = 1; 7 >= j; j++){
	//		cout << ((max(i, j)%2==0)?f(i, j):f(j,i)) << ' ';
	//		
	//	}
	//	cout << endl;
	//}	

	ll n; cin >> n;
	
	while(n--){
		ll a, b; cin >> a >> b;
		cout << ((max(a, b)%2==0)?f(a, b):f(b,a)) << endl;
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
