#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

const int cInf = 1e5;

int Answer(std::vector<int>& ai, std::vector<int>& bj) {
  int l = ai.size();
  int left = 0;
  int right = l - 1;
  while (left + 1 != right) {
    int middle = (left + right) / 2;
    (ai[middle] - bj[middle] < 0 ? left : right) = middle;
  }
  return (bj[left] < ai[right] ? left : right);
}

void Solve() {
  int n;
  int m;
  int l;
  std::cin >> n >> m >> l;
  std::vector<std::vector<int>> a(n, std::vector<int>(l + 2));
  std::vector<std::vector<int>> b(m, std::vector<int>(l + 2));

  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= l; j++) {
      std::cin >> a[i][j];
    }
    a[i].back() = cInf;
  }
  for (int i = 0; i < m; i++) {
    b[i].front() = cInf;
    for (int j = 1; j <= l; j++) {
      std::cin >> b[i][j];
    }
  }

  int quests;
  std::cin >> quests;
  while (0 != quests--) {
    int i;
    int j;
    std::cin >> i >> j;
    std::cout << Answer(a[--i], b[--j]) << '\n';
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  int times = 1;
  // std::cin >> times;
  while (times-- != 0) {
    Solve();
  }
}
