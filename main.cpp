#include <iostream>
#include <random>

using namespace std;

int main() {  //
  random_device rd{};
  mt19937 rng{rd()};
  uniform_real_distribution<float> dist{0, 1};
  auto random = [&]() {  //
    return dist(rng);
  };

  int n = 10000000;
  int c = 0;
  for (int i = 0; i < n; ++i) {
    const auto x = random();
    const auto y = random();
    const auto r2 = x * x + y * y;
    if (r2 < 1) ++c;
  }
  auto monte_carlo_pi = 4 * float(c) / float(n);
  cout << "pi = " << monte_carlo_pi << '\n';
}