#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

double speed(vector<pair<double, double>> data) {
	double max = 0;
	for (int i = 0; i < data.size() - 1; i++) {
		double spd = abs(data[i + 1].second - data[i].second) / (data[i + 1].first - data[i].first);
		if (spd >= max) {
			max = spd;
		}
	}
	return max;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	double t, p;
	vector<pair <double, double>> data;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t >> p;
		data.push_back(make_pair(t, p));
	}
	sort(data.begin(), data.end());

	/*for (auto x : data) {
		cout << x.first << "\n";
	}*/
	cout.precision(6);
	cout << speed(data);
	return 0;
}