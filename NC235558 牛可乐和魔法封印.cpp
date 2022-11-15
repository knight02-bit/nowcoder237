#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 1e5+10;
int a[N];
int n, q;

int fl(int x)//找大于等于x的最小下标 
{
    if(x <= a[1]) return 1;
    int l = 1, r = n;
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(x <= a[mid]) r = mid;
        else l = mid + 1;
    }
    return l;
}

int fr(int x)//找小于等于x的最大下标
{
    if(x >= a[n]) return n;
    int l = 1, r = n;
    while(l < r)
    {
        int mid = (l + r + 1) >> 1;
        if(x < a[mid]) r = mid-1;
        else l = mid;
    }
    return r;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    scanf("%d", &q);
    while(q --)
    {
        int left, right;
        scanf("%d%d", &left, &right);
        if(left > a[n] || right < a[1]) printf("0\n");
        else printf("%d\n", fr(right)+1-fl(left));
    }
    return 0;
}


/*
input:
5
1 1 2 3 3
3
1 1
2 3
1 3

output:
2
3
5
*/

/*
input:

output:
*/