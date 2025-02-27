#include <bits/stdc++.h>

#define ld long double
#define N 1000000
#define M 10

using namespace std;


void increasing_sorted() {
    for (int i = 0; i < N; i++) {
        cout << (ld)i + (ld)rand() / RAND_MAX << " ";
    }
    cout << "\n";
}

void decreasing_sorted() {
    for (int i = N - 1; i >= 0; i--) {
        cout << (ld)i + (ld)rand() / RAND_MAX << " ";
    }
    cout << "\n";
}

void generate_random() {
    for (int i = 0; i < N; i++) {
        cout << (ld)rand() / RAND_MAX * 1e6 << " ";
    }
    cout << "\n";

}

int main() {
    srand(time(0));

    freopen("test.txt", "w", stdout);

    increasing_sorted();
    decreasing_sorted();

    for (int i = 2; i < M; i++) {
        generate_random();
    }

    return 0;
}

