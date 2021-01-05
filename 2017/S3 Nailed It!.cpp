#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L[2002] = { 0, };
int S[4001] = { 0, };

void sum() {
	for (int i = 1; i <= 2000; i++) {
		if (L[i]) {
			if (L[i] > 1) {
						S[i * 2] += L[i] / 2;
			}
			for (int j = i + 1; j <= 2000; j++) {
				if (L[j]) S[i + j] += min(L[i], L[j]);
			}
		}
		
	}
}

int ans1 = 1, ans2 = 0;

void solution() {
	for (auto x : S) {
		if (x > ans1) {
			ans1 = x;
			ans2=1;
		}
		else if (x == ans1) ans2++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	int i;
	cin >> N;
	while (N--) {
		cin >> i;
		L[i]++;
	}
	sum();
	solution();

	cout << ans1 << ' ' << ans2;
	return 0;
}