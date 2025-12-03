#include "../../Header/Basic.h"
using namespace std;

constexpr int M=100;
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("input.txt","r",stdin);
#endif
	int a=50,ans=0;
	string s;
	while(cin>>s){
		const int d=(s[0]=='L'?-1:1);
		int x;
		sscanf(s.c_str()+1,"%d",&x);
		while(x--){
			a+=d;
			if(a<0) a=99;
			else if(!a || a==M){
				a=0;
				++ans;
			}
		}
		dbg(a,ans);
	}
	cout<<ans;
	return 0;
}
