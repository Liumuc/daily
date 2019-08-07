#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000;
const int mod=20100501;
bool isp[2000010];
int pp[2000010];
int len=0;
int n,m;
int t;

void ss(int n) {
	for(int i=0; i<=n; i++)
		isp[i]=1;
	isp[0]=isp[1]=0;
	for(int i=2; i<=n; i++)
		if(isp[i]) {
			pp[len++]=i;
			for(int j=2*i; j<=n; j+=i)
				isp[j]=0;
		}
}

int cal(int p,int n) {
	int ans=1;
	while(n) {
		n/=p;
		ans+=n;
	}
	return ans;
}

int main() {
	ss(maxn*2);
	cin>>t;
	while(t--) {
		long long ans=1;
		cin>>n>>m;
		int nm=n+1-m;
		for(int i=0; i<len&&pp[i]<=(n+m); i++) {
			int cnt=0;
			while(nm%pp[i]==0) {
				nm/=pp[i];
				cnt++;
			}
			cnt=cnt+cal(pp[i],n+m)-cal(pp[i],m)-cal(pp[i],n+1);
			for(int j=1; j<=cnt; j++) {
				ans=ans*pp[i];
				if(ans>=mod)
					ans%=mod;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
