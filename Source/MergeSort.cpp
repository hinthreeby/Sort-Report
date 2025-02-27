
#include <bits/stdc++.h>

#define ld long double
#define N 1000000
#define M 10

using namespace std;

void merge(vector<ld>& a, int l, int mid, int r) {
    int num1 = mid - l + 1;
    int num2 = r - mid;

    vector<int> left(num1), right(num2);

    for (int i = 0; i < num1; i++)
        left[i] = a[l + i];
    for (int j = 0; j < num2; j++)
        right[j] = a[mid + 1 + j];

    int i = 0, j = 0;
    int k = l;

    while (i < num1 && j < num2) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        }
        else {
            a[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < num1) {
        a[k] = left[i];
        i++;
        k++;
    }

    while (j < num2) {
        a[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(vector<ld>& a, int l, int r) {
    if (l >= r)
        return;

    int mid = l + (r - l) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    merge(a, l, mid, r);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("test.txt", "r", stdin);
    freopen("MergeSort_result.txt", "w", stdout);

    vector<vector<ld>> a(M, vector<ld>(N));

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        auto bd = chrono::high_resolution_clock::now();
        mergeSort(a[i], 0, N - 1);
        auto kt = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> duration = kt - bd;
        cout << "Time for test " << i + 1 << ": " << duration.count() << " ms\n";
    }
    return 0;
}
