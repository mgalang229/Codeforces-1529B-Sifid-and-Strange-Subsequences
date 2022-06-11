#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			ans += (a[i] <= 0);
		}
		sort(a.begin(), a.end());
		int mn = INT_MAX;
		for (int i = 0; i < n; i++) {
			if (a[i] > 0) {
				mn = min(mn, a[i]);
			}
		}
		bool checker = (mn < INT_MAX);
		for (int i = 1; i < n; i++) {
			if (a[i] <= 0) {
				checker &= (a[i] - a[i - 1] >= mn);
			}
		}
		cout << (checker ? ans + 1 : ans) << '\n';
	}
	return 0;
}
