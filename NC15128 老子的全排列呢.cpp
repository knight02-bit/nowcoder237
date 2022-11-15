#include<iostream>
using namespace std;

int a[10];
int st[10];
void dfs(int u) {
    if(u == 9) {
        for(int i = 1; i <= 8; ++i) {
            cout << a[i];
            if(i != 8) cout << " ";
        }
        cout << '\n';
    }
    for(int i = 1; i <= 8; ++i) {
        if(!st[i]) {
            st[i] = 1;
            a[u] = i;
            dfs(u+1);
            st[i] = 0;
        }
    }
}

int main()
{
    dfs(1);
    return 0;
}