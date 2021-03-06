#include <chrono>
#include <iostream>
#include <random>

using namespace std;

int main() {  //
  mt19937 rng{random_device{}()};
  uniform_real_distribution<float> dist{0, 1};
  auto random = [&]() { return dist(rng); };

  const int n = 10000000;
  int c = 0;

  {
    const auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < n; ++i) {
      const auto x = random();
      const auto y = random();
      if ((x * x + y * y) < 1) ++c;
    }

    const auto end = chrono::high_resolution_clock::now();
    const auto time = chrono::duration<float>(end - start).count();
    cout << "time = " << time << " s\n";
  }

  const auto monte_carlo_pi = 4.0f * c / n;
  cout << "pi = " << monte_carlo_pi << '\n';
}