#include <iostream>
#include <vector>
using namespace std;
bool ispossible(vector<int> &arr, int n, int m, int mid)
{
	int painter = 1, time = 0;
	for (int i = 0; i < n; i++)
	{
		if (time + arr[i]<=mid)
		{
			time += arr[i];
		}
		else
		{
			painter++;
			time = arr[i];
		}
	}
	return painter <= m;
}
int minpaint(vector<int> &arr, int n, int m)
{
	int sum = 0, maxval = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		maxval = max(maxval, arr[i]);
	}
	int st = maxval, end = sum, ans = -1;
	while (st <= end)
	{
		int mid = st + (end - st) / 2;
		if (ispossible(arr, n, m, mid))
		{
			ans = mid;
			end = mid - 1;
		}
		else
		{
			st = mid + 1;
		}
	}
	return ans;
}
int main()
{
	vector<int> arr = {40, 30,10, 20};
	int n = 4, m = 2;

	cout << minpaint(arr, n, m) << endl;
	return 0;
