#include "../../Header/Basic.h"
using namespace std;

constexpr int N=12;
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("input.txt","r",stdin);
#endif
	LL ans=0;
	string s;
	while(cin>>s){
		array<LL,N>a{};
		for(auto c:s){
			int x=c-'0';
			for(int i=N-1;i>0;--i){
				if(a[i-1]) updmx(a[i],a[i-1]*10+x);
			}
			updmx(a[0],1ll*x);
		}
		ans+=a[N-1];
	}
	cout<<ans;
	return 0;
}
