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
	string s;
	LL ans=0;
	vector<vector<int>>a;
	while(getline(cin,s)){
		int i=0,x=0;
		for(auto c:s){
			if(isdigit(c)){
				x=x*10+c-'0';
			}
			else if(c=='+'){
				ans+=accumulate(all(a[i]),0ll);
				++i;
			}
			else if(c=='*'){
				LL r=1;
				for(auto u:a[i]) r*=u;
				ans+=r;
				++i;
			}
			else if(x){
				if(!(i<(int)a.size())){
					a.push_back({x});
					++i;
				}
				else a[i++].emplace_back(x);
				x=0;
			}
		}
		if(x){
			if(!(i<(int)a.size())){
				a.push_back({x});
				++i;
			}
			else a[i++].emplace_back(x);
			x=0;
		}
	}
	cout<<ans;
	return 0;
}
