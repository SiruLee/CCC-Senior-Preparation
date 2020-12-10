#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

double speed(map <double, double> m, vector<double> v) {
	double max = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		double spd = abs(m[v[i + 1]] - m[v[i]]) / abs(v[i + 1] - v[i]);
		if (spd > max) {
			max = spd;
		}
	}
	return max;
}

int main() {
	double n, t, p;
	map<double, double> m;
	vector<double> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t >> p;
		v.push_back(t);
		m[t] = p;
	}
	sort(v.begin(), v.end());
	cout.precision(5);
	cout << speed(m, v) << "\n";
	return 0;
}