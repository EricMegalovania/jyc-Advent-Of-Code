#include "../../Header/Basic.h"
using namespace std;

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("input.txt","r",stdin);
#endif
	LL ans=0;
	string s;
	while(cin>>s){
		int res=0,mx=s[0]-'0';
		for(int i=1;i<s.size();++i){
			const int x=s[i]-'0';
			updmx(res,mx*10+x);
			updmx(mx,x);
		}
		ans+=res;
	}
	cout<<ans;
	return 0;
}
