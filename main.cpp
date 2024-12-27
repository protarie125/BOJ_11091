#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll N;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> N;
  cin.ignore();
  while (0 < (N--)) {
    string s;
    getline(cin, s);

    ll ct = 0;
    auto lst = vl(26, 0);

    for (const auto& x : s) {
      if ('a' <= x && x <= 'z') {
        const auto& c = x - 'a';
        if (lst[c] == 0) {
          ++ct;
          lst[c] = 1;
        }
      }

      if ('A' <= x && x <= 'Z') {
        const auto& c = x - 'A';
        if (lst[c] == 0) {
          ++ct;
          lst[c] = 1;
        }
      }
    }

    if (ct == 26) {
      cout << "pangram";
    } else {
      cout << "missing ";

      char c = 'a';
      for (const auto& v : lst) {
        if (v == 0) {
          cout << c;
        }
        ++c;
      }
    }

    cout << '\n';
  }

  return 0;
}