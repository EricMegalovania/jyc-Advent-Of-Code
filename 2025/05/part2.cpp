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
	while(getline(cin,s)){
		vector r=read(s);
		dbg(r);
		assert(r.size()<=2);
		if(r.size()==2){
			a.push_back({r[0],r[1]});
		}
	}
	sort(all(a));
	LL ans=0,L=0,R=-1;
	for(auto& [l,r]:a){
		if(l<=R) updmx(R,r);
		else{
			ans+=R-L+1;
			L=l,R=r;
		}
	}
	ans+=R-L+1;
	cout<<ans;
	return 0;
}
