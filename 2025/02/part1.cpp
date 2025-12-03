#include "../../Header/Basic.h"
using namespace std;

LL work(const LL X){
	LL x=X;
	string s;
	while(x){
		s+=char('0'+x%10);
		x/=10;
	}
	const int m=(int)s.size();
	if(m&1) return 0;
	if(s.substr(0,m/2)!=s.substr(m/2,m/2)) return 0;
	dbg(X);
	return X;
}

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("input.txt","r",stdin);
#endif
	LL ans=0;
	string s;
	while(getline(cin,s)){
		vector<LL>o;
		LL x=0;
		for(auto c:s){
			if(isdigit(c)){
				x=x*10+c-'0';
			}
			else{
				if(x) o.emplace_back(x);
				x=0;
			}
		}
		if(x) o.emplace_back(x);
		for(int i=1;i<(int)o.size();i+=2){
			for(LL j=o[i-1];j<=o[i];++j){
				ans+=work(j);
			}
		}
	}
	cout<<ans;
	return 0;
}
