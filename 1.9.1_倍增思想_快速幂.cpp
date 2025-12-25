#include <iostream>
using namespace std;
typedef long long LL;
// a^b % p 的值
LL quickpow(LL a, LL b, LL p)
{
LL ret = 1;
while(b)
{
if(b & 1) ret = ret * a % p;
a = a * a % p;
b >>= 1; // 提取 b 的⼆进制位
} r
eturn ret;
} i
nt main()
{
LL a, b, p;
scanf("%lld%lld%lld", &a, &b, &p);
printf("%lld^%lld mod %lld=%lld\n", a, b, p, quickpow(a, b, p));
return 0;
}
