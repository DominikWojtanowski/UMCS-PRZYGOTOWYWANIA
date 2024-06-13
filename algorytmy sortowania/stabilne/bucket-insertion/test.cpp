#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

const int MOD = 1000000009;

struct Parcel
{
    int priority;
    int size;
    int index;
};

bool compareParcels(const Parcel &a, const Parcel &b)
{
    if (a.priority != b.priority)
    {
        return a.priority > b.priority; // Higher priority first
    }
    return a.index < b.index; // Earlier index first
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<long long> results(t);

    for (int test_case = 0; test_case < t; ++test_case)
    {
        int n;
        cin >> n;
e
        vector<Parcel> parcels(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> parcels[i].priority >> parcels[i].size;
            parcels[i].index = i;
        }

        sort(parcels.begin(), parcels.end(), compareParcels);

        long long total_cost = 0;
        for (int i = 0; i < n; ++i)
        {
            long long day = i + 1;
            long long size = parcels[i].size;
            total_cost = (total_cost + day * size) % MOD;
        }

        results[test_case] = total_cost;
    }

    for (const auto &result : results)
    {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}
