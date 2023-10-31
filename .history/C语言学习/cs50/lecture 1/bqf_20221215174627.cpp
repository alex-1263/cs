#include <iostream>
#include <time.h>
using namespace std;
const int N = 100;
int dfs(int a[], int x, int vis[]) {
    if (vis[a[x]]) {
        return 0;
    }
    vis[a[x]] = 1;
    return dfs(a, a[a[x]], vis) + 1;
}
int main() {
    srand(time(0));
    int cnt = 0, T = 10000;
    for (int round = 0; round < T; round++) {
        int a[128] = {0};
        for (int i = 1; i <= N; i++) {
            a[i] = i;
        }
        for (int i = N; i > 1; i--) {
            int r = 1 + rand() % i;
            int t = a[i];
            a[i] = a[r];
            a[r] = t;
        }
        int vis[128] = {0};
        for (int i = 1; i <= N; i++) {
            if (dfs(a, i, vis) > (N >> 1)) {
                cnt++;
                break;
            }
        }
    }
    cout << 1.0 * cnt / T;
    return 0;
}