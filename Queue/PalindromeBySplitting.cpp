#include <iostream>
using namespace std;
int main() {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int l = 0, h = n - 1, k = 0;
        while (l < h) {
            if (a[l] == a[h]) {
                l++, h--;
            }
            else if (a[l] > a[h]) {
                a[l] = a[l] - a[h];
                h--;
                k += 1;
            }
            else
            {
                a[h] = a[h] - a[l];
                l++;
                k += 1;
            }
        }
        cout << k << endl;
    }
    return 0;
}