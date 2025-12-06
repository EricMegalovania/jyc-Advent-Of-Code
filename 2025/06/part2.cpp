#include "../../Header/Basic.h"
using namespace std;

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
