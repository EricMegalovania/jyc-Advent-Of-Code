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
	vector<string>a;
	while(getline(cin,s)){
		a.emplace_back(s);
	}
	LL add=0,mul=1;
	for(int i=(int)(a[0].size()-1);i>=0;--i){
		int x=0;
		for(int j=0;j+1<(int)a.size();++j){
			if(isdigit(a[j][i])) x=x*10+a[j][i]-'0';
		}
		if(x) add+=x,mul*=x;
		if(a.back()[i]=='+'){
			ans+=add;
			add=0,mul=1;
		}
		else if(a.back()[i]=='*'){
			ans+=mul;
			add=0,mul=1;
		}
	}
	cout<<ans;
	return 0;
}
