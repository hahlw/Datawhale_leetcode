#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

double n, p, k;

int main()
{
    while (scanf("%lf%lf",&n,&p) != EOF)
    {
        k = pow(p, 1.0 / n); 
        printf("%d\n",(int)floor(k+0.5));
    }
    return 0;
}



//大佬写的高精度
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxL=505,tt=10000;
char s[maxL<<2];
int n,L,R;
struct bigint{
    int a[maxL],len;
    bigint(){memset(a,0,sizeof a);len=0;}
    bigint(int x)//int类型 转成 bigint 类型
    {
        memset(a,0,sizeof a);
        for (len=0;x;x/=tt) a[++len]=x%tt;
    }
    bigint (char *s)//字符串类型 转成 bigint类型，因为p很大，要用字符型数组读入
    {
        memset(a,0,sizeof a);int x=L-3;
        for (len=0;x+3>=1;x-=4)
        {
            len++;
            for (int i=max(x+3,1),y=1;i>=x&&i>0;i--)
              a[len]+=(s[i]-'0')*y,y*=10;
        }
    }
    bigint operator *(const bigint &b)const//重载乘号
    {
        bigint c;c.len=len+b.len;
        for (int i=1;i<=len;i++)
         for (int j=1;j<=b.len;j++)
           c.a[i-1+j]+=a[i]*b.a[j],c.a[i+j]+=c.a[i-1+j]/tt,c.a[i-1+j]%=tt;
        while (c.len>1&&!c.a[c.len]) c.len--;
        return c;
    }
    bool operator ==(const bigint &b)const//重载 ==
    {
        if (len!=b.len) return 0;
        else for (int i=1;i<=len;i++) if (a[i]!=b.a[i]) return 0;
        return 1;
    }
    bool operator <(const bigint &b)const//重载小于号
    {
        if (len<b.len) return 1;else if (len>b.len) return 0;
        for (int i=len;i;i--)
          if (a[i]<b.a[i]) return 1;else
          if (a[i]>b.a[i]) return 0;
        return 0;
    }
}p,ans,a;
void qsm(bigint &a,int b,bigint &w)//快速幂
{
    for (w=1;b;b>>=1)
    {
        if (b&1) w=w*a;
        a=a*a;
    }
}
int main()
{
    while (1)
    {
        if (scanf("%d%s",&n,s+1)==EOF) break;
        L=strlen(s+1);p=s;
        L=1,R=1e9;bool f=1;
        while (L<=R)//二分查找
        {
            int mid=(R-L>>1)+L;
            a=mid;qsm(a,n,ans);
            if (ans==p) {printf("%d\n",mid);f=0;break;}
            if (ans<p) L=mid+1;else R=mid-1;
        }
        if (f) printf("%d\n",R);
    }
    return 0;
}
