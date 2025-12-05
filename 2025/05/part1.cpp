#include "../../Header/Basic.h"
using namespace std;

vector<LL>read(const string_view& s){
	vector<LL>r;
	LL x=0;
	for(auto c:s){
		if(isdigit(c)){
			x=x*10+c-'0';
		}
		else{
			if(x) r.emplace_back(x);
			x=0;
		}
	}
	if(x) r.emplace_back(x);
	return r;
}

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("input.txt","r",stdin);
#endif
	vector<array<LL,2>>a;
	string s;
	int ans=0;
	while(getline(cin,s)){
		vector r=read(s);
		dbg(r);
		assert(r.size()<=2);
		if(r.empty()) continue;
		else if(r.size()==2){
			a.push_back({r[0],r[1]});
		}
		else{
			const LL& x=r[0];
			bool ok=0;
			for(auto& [l,r]:a){
				if(l<=x && x<=r){
					ok=1;
					break;
				}
			}
			ans+=ok;
		}
	}
	cout<<ans;
	return 0;
}
