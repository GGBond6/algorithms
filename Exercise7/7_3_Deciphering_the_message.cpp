#include <bits/stdc++.h>
using namespace std;
const int maxn = 40000 + 10;
const int x = 123;
int n, m, pos;
unsigned long long H[maxn], xp[maxn];
int rank1[maxn];
unsigned long long hash1[maxn];

int cmp(const int &a, const int &b) {
  return hash1[a] < hash1[b] || (hash1[a] == hash1[b] && a < b);
}
int possible(int L) {
  int c = 0, pos = -1;
  for (int i = 0; i < n - L + 1; ++i) {
    rank1[i] = i;
    hash1[i] = H[i] - H[i + L] * xp[L];
  }
  sort(rank1, rank1 + n - L + 1, cmp);
  for (int i = 0; i < n - L + 1; i++) {
    if (i == 0 || hash1[rank1[i]] != hash1[rank1[i - 1]]) c = 0;
    if (++c >= m) pos = max(pos, rank1[i]);
  }
  return pos >= 0;
}

int main() {
  char s[maxn];
  m = 2;
  scanf("%s", &s);
  n = strlen(s);
  H[n] = 0;
  for (int i = n - 1; i >= 0; i--) H[i] = H[i + 1] * x + (s[i] - 'a');
  xp[0] = 1;
  for (int i = 1; i <= n; i++) xp[i] = xp[i - 1] * x;
  int L = 1, R = n + 1;
  while (R - L > 1) {
    int M = L + (R - L) / 2;
    if (possible(M)) L = M; else R = M;
  }
  printf("%d", L);
}

