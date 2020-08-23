#include<cmath>
#include<cstring>
#define	parity(x) (x&1)
#define lowbit(x) (x&(-x))
inline int LMabs(int a){
    int temp=a>>31;
    return (a^temp)-temp;
}
inline long long LMabs(long long a){
    int temp=a>>63;
    return (a^temp)-temp;
}
inline int pown(int a,int b){
    register int ans=1,base=a;
    while(b){
        (b&1)?ans*=base:1;
        base*=base;
        b>>=1;
　  }
    return ans;
}
inline long long pown(long long a,long long b){
    register long long ans=1,base=a;
    while(b){
        (b&1)?ans*=base:1;
        base*=base;
        b>>=1;
　  }
    return ans;
}
inline void LMswap(int *a,int *b){
    (*a)^=*b;
    (*b)^=*a;
    (*a)^=*b;
}
inline void LMswap(long long *a,long long *b){
    (*a)^=*b;
    (*b)^=*a;
    (*a)^=*b;
}
inline int get_number(int x){
	return int(log10(x)+1);
}
inline long long get_number(long long x){
	return int(log10(x)+1);
}
void Euler_Prime(int prime[],int visit[],int maxn){
    memset(prime,0,sizeof(prime));
    memset(visit,0,sizeof(visit));
    for(register int i=2;i<=maxn;++i){
        if(!visit[i])prime[++prime[0]]=i;
        for(register int j=1;j<=prime[0]&&i*prime[j]<=maxn;++j){
            visit[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
int Euler(int n){
    int rea=n;
    for(int i=2;i*i<=n;++i)
        if(!(n%i)){
            rea=rea-rea/i;
            while(!(n%i))n=n/i;
        }
    (n>1)?rea=rea-rea/n:true;
    return rea;
}
long long Euler(long long n){
    int rea=n;
    for(long long i=2;i*i<=n;++i)
        if(!(n%i)){
            rea=rea-rea/i;
            while(!(n%i))n=n/i;
        }
    (n>1)?rea=rea-rea/n:true;
    return rea;
}
double Newton_sqrt(double x){
	if(x==1||x==0)return x;
	double temp=x/2;
	while(1){
		double a=temp;
		temp=(temp+x/2)/2;
		if(a-temp<0.001&&a>temp)return temp;
	}
}