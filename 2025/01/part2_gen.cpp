#include "../../Header/Basic.h"
using namespace std;

int main(){
	for(int t=100;t--;){
		int x=rand(1,100);
		cout<<"LR"[rng()&1]<<x<<'\n';
	}
	return 0;
}
