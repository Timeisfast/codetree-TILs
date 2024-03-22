#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    unordered_map<int, int> m;
    vector<int> v;
    int n, k, cnt{ 0 };
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        m[a]++;
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        if(v[i] > k / 2) break;
        if(v[i] == k - v[i]) {
            cnt += m[v[i]] * (m[v[i]] - 1) / 2;
            m[v[i]] = 0;
        }
        else {
            cnt += m[k - v[i]];
        }
    }
    cout << cnt;
    return 0;
}