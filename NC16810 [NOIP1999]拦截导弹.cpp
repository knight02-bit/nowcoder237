#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 1e5+10;
int a[N];
int ups[N], dns[N];

int main()
{
    int n = 0;
    while(scanf("%d", &a[n])!=EOF) ++n;

    int n_up = 0, n_dn = 0;
    for(int i = 0; i < n; ++i) {
        ups[i] = 1, dns[i] = 1;
        for(int j = 0; j < i; ++j) {
            if(a[j] < a[i]) ups[i] = max(ups[i], ups[j]+1);
            else dns[i] = max(dns[i], dns[j]+1);
        }
        n_up = n_up > ups[i] ? n_up : ups[i];
        n_dn = n_dn > dns[i] ? n_dn : dns[i];
    }

    printf("%d\n%d", n_dn, n_up);
    return 0;
}

/*
input:
389 207 155 300 299 170 158 65

output:
6
2
*/