#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <double> v;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	double answer = 2000000000;
	for (int i = 1; i < n - 1; i++) {
		double a = (v[i] - v[i - 1]) / 2 + (v[i + 1] - v[i]) / 2;
		answer = min(answer, a);
	}
	cout << fixed;
	cout.precision(1);
	cout <<answer;
	return 0;
}