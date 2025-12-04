#include "../../Header/Basic.h"
using namespace std;

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("input.txt","r",stdin);
#endif
	vector<string>a;
	string s;
	while(cin>>s){
		a.emplace_back(s);
	}
	const int n=(int)a.size();
	const int m=(int)(a[0].size());
	int ans=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(a[i][j]=='.') continue;
			int cc=0;
			for(int di=-1;di<=1;++di){
				for(int dj=-1;dj<=1;++dj){
					if(!di && !dj) continue;
					int ni=i+di;
					int nj=j+dj;
					if(ni<0 || nj<0 || ni>=n || nj>=m) continue;
					if(a[ni][nj]!='.') ++cc;
				}
			}
			if(cc<4){
				a[i][j]='x';
				++ans;
			}
		}
	}
#ifdef LOCAL
	for(auto& v:a) cout<<v<<'\n';
#endif
	cout<<ans;
	return 0;
}
