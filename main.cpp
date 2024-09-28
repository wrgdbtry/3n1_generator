#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int collatz(int n) {
    if (n % 2 == 1) {
        return 3 * n + 1;
    } else {
        return n / 2;
    }
}

int main() {
    ofstream file;
    file.open("collatz_sequence.txt");

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int x = 0;
    cout << "Enter x for 10^x numbers you want to solve with 3n+1: ";
    cin >> x;

    long limit = pow(10, x);
    for (long i = 1; i < limit; i++) {
        long current = i;
        file << "Starting number: " << i << "\n";

        while (current != 1) {
            file << current << " ";
            current = collatz(current);
        }
        file << "1\n";
    }

    file.close();
    cout << "Collatz sequences written to collatz_sequence.txt." << endl;
    return 0;
}
