#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool primes[2000000];


bool check(int num) {
	if (primes[num]) {
		return true;
	}
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

int main() {
	int n;
	vector<int> inputs;
	primes[2] = true; primes[3] = true;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int n;
		cin >> n;
		inputs.push_back(n);
	}

	for (int x : inputs) {
		if (check(x * 2 - 2)) {
			primes[x * 2 - 2] = true;
			cout << 2 << " " << x * 2 - 2 << "\n";

		}
		else {
			for (int i = 3; i <= x; i += 2) {
				if (primes[i]) {
					if (primes[x * 2 - i]) {
						cout << i << " " << x * 2 - i << "\n";
						break;
					}
					else if (check(x * 2 - i)) {
						primes[x * 2 - i] = true;
						cout << i << " " << x * 2 - i << "\n";
						break;
					}
				}
				else if (check(i)) {
					if (primes[x * 2 - i]) {
						cout << i << " " << x * 2 - i << "\n";
						break;
					}
					else if (check(x * 2 - i)) {
						primes[x * 2 - i] = true;
						cout << i << " " << x * 2 - i << "\n";
						break;
					}
				}
			}
		}
	}

	return 0;
}