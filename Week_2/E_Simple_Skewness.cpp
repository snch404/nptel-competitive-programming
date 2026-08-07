#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Returns the mean of the chosen subset:
// k elements before (and including) median
// + k largest elements
double getMean(const vector<ll> &prefix,
               const vector<ll> &arr,
               int medianIndex,
               int k,
               int n)
{
    if (k == 0)
        return arr[medianIndex];

    ll leftSum = prefix[medianIndex + 1] - prefix[medianIndex - k];
    ll rightSum = prefix[n] - prefix[n - k];

    return (leftSum + rightSum) / (2.0 * k + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    // Prefix sums
    vector<ll> prefix(n + 1, 0);

    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + arr[i];

    double bestValue = -1.0;
    int bestMedian = 0;
    int bestK = 0;

    for (int medianIndex = 0; medianIndex < n; medianIndex++)
    {
        // Maximum possible K
        int maxK = min(medianIndex, n - medianIndex - 1);

        int left = 0;
        int right = maxK;
        int mid = (left + right) / 2;

        // DO NOT CHANGE THIS BINARY SEARCH
        while (right - left > 0)
        {
            double currentMean =
                getMean(prefix, arr, medianIndex, mid, n);

            int nextK = mid + 1;

            int nextLargest = arr[n - nextK];
            int nextLeft = arr[medianIndex - nextK];

            if ((nextLargest + nextLeft) / 2.0 <= currentMean)
                right = max(mid, left);
            else
                left = min(mid + 1, right);

            mid = (left + right) / 2;
        }

        double finalMean =
            getMean(prefix, arr, medianIndex, left, n);

        if (finalMean - arr[medianIndex] > bestValue)
        {
            bestValue = finalMean - arr[medianIndex];
            bestMedian = medianIndex;
            bestK = left;
        }
    }

    cout << 2 * bestK + 1 << '\n';

    vector<ll> answer;

    // Largest K elements
    for (int i = 0; i < bestK; i++)
        answer.push_back(arr[n - 1 - i]);

    // Median + K elements before it
    for (int i = 0; i <= bestK; i++)
        answer.push_back(arr[bestMedian - i]);

    sort(answer.begin(), answer.end());

    for (ll x : answer)
        cout << x << " ";

    cout << '\n';

    return 0;
}