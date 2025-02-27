#include <bits/stdc++.h>

#define ld long double
#define N 1000000
#define M 10

using namespace std;


void heapify(vector<ld>& a, int n, int i) {

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(vector<ld>& a) {
    int n = a.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("test.txt", "r", stdin);
    freopen("HeapSort_result.txt", "w", stdout);

    vector<vector<ld>> a(M, vector<ld>(N));

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        auto bd = chrono::high_resolution_clock::now();
        heapSort(a[i]);
        auto kt = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> duration = kt - bd;
        cout << "Time for test " << i + 1 << ": " << duration.count() << " ms\n";
    }
    return 0;
}
