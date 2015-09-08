/*********************************************************
  file name: codeforces#309div1B.cpp
  author : kereo
  create time:  2015年07月04日 星期六 14时20分53秒
*********************************************************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int sigma_size=26;
const int N=100+50;
const int MAXN=100000+50;
const int inf=0x3fffffff;
const double eps=1e-8;
const int HASH=100007;
const int mod=1000000000+7;
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define Ls(x) (x->ch[0])
#define Rs(x) (x->ch[1])
#define PII pair<int, int>
#define mk(x,y) make_pair((x),(y))
int n;
ll k;
ll dp[N][2];
int main(){
	//freopen("in.txt","r",stdin);
	while(~scanf("%d%lld",&n,&k)){
		memset(dp,0,sizeof(dp));
		dp[n][0]=dp[n+1][0]=1;
		for(int i=n-1;i>=1;i--){
			dp[i][0]=dp[i+1][0]+dp[i+1][1];
			dp[i][1]=dp[i+2][0]+dp[i+2][1];
		}
		/*for(int i=1;i<=n;i++)
			printf("i=%d dp[i][0]=%lld dp[i][1]=%lld\n",i,dp[i][0],dp[i][1]);	
			*/
		for(int i=1;i<=n;){
			if(i>1)
				printf(" ");
			if(k<=dp[i][0]){
				printf("%d",i);
				i++;
			}
			else{
				k-=dp[i][0];
				printf("%d %d",i+1,i);
				i+=2;
			}
		}
	}
	return 0;
}
