#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector <int> v[2];
	int q, n;
	cin >> q >> n;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			int k;
			cin >> k;
			v[i].push_back(k);
		}
	}
	sort(v[1].begin(), v[1].end());
	int sum=0;
	if (q == 1) {
		sort(v[0].begin(), v[0].end());
		for (int j = 0; j < n; j++) {
			sum += max(v[0][j], v[1][j]);
		}
	}
	else {
		sort(v[0].begin(), v[0].end(), greater<int>());
		for (int j = 0; j < n; j++) {
			sum += max(v[0][j], v[1][j]);
		}
	}
	cout << sum;
	return 0;
}