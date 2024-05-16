#include<bits/stdc++.h>
using namespace std;

int kadane(vector <int> &nums) {
	int n = nums.size(), ans = nums[0];
	int mini = nums[0], maxi = nums[0], cmini = nums[0], cmaxi = nums[0];
	for (int i = 0; i < n; i++) {
		cmaxi = max(nums[i], cmaxi + nums[i]);
		maxi = max(maxi, cmaxi);
		cmini = min(nums[i], cmini + nums[i]);
		mini = min(mini, cmini);
		ans += nums[i];
	}
	return maxi > 0 ? max(maxi, ans - mini) : maxi;
}

int main() {

	// Write your code here
	int n;
	cin >> n;
	vector <int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	cout << kadane(nums) << endl;
	return 0;
}
