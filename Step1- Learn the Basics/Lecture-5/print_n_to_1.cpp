#include <iostream>
using namespace std;


void printGfg(int N) {
    if (N <= 0) { // Base condition: Stop when N reaches 0
        return;
    }
    cout << N << endl;
    printGfg(N - 1); // Recursive call with N decremented
}

int main() {
    int N;
    cin >> N;
    printGfg(N); // Call function with N
    return 0;
}
