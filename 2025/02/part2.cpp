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
	for(int i=1;i*2<=m;++i){
		if(m%i) continue;
		bool ok=1;
		for(int j=i;ok && j<m;j+=i){
			if(s.substr(0,i)!=s.substr(j,i)) ok=0;
		}
		if(ok) return X;
	}
	return 0;
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
