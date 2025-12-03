#include "../../Header/Basic.h"
using namespace std;

#define D constexpr MI
#define C const
#define O operator
template<int mod>struct MI{
	D():v(0){}
	template<typename T>
	D(T x):v(x%mod){if(v<0) v+=mod;}
	template<typename T>
	static D raw(T x){MI z; z.v=x; return z;}
	D pow(LL n) C {
		MI x=*this, r=1;
		while(n){if(n&1) r*=x; x*=x; n>>=1;}
		return r;
	}
	D inv() C {return pow(mod-2);}
	D& O +=(C MI& x){
		if((v+=x.v)>=mod) v-=mod;
		return *this;
	}
	D& O -=(C MI& x){
		if((v-=x.v)<0) v+=mod;
		return *this;
	}
	D& O *=(C MI& x){
		LL z=v; z*=x.v; v=z%mod;
		return *this;
	}
	D& O /=(C MI& x){
		return *this=*this*x.inv();
	}
	int val() C{return v;}
#define OP(s,t) friend D O s(C MI& x,C MI& y){return MI(x) t y;}
	OP(+,+=) OP(-,-=) OP(*,*=) OP(/,/=)
#undef OP
private:
	int v;
};
#undef D
#undef C
#undef O

using Z=MI<100>;
#define raw(x) Z::raw(x)

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("input.txt","r",stdin);
#endif
	Z a=raw(50);
	int ans=0;
	string s;
	while(cin>>s){
		const char c=s[0];
		int x;
		sscanf(s.c_str()+1,"%d",&x);
		if(c=='L') a-=x;
		else a+=x;
		if(!a.val()) ++ans;
		dbg(c,x,a.val());
	}
	cout<<ans;
	return 0;
}
