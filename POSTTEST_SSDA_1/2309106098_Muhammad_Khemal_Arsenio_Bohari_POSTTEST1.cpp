#include <iostream>
using namespace std;

int pascal(int row, int col) {
    if (col == 0 || col == row) {
        return 1;
    } else {
        return pascal(row - 1, col - 1) + pascal(row - 1, col);
    }
}

void printPascal(int levels) {
    for (int row = 0; row < levels; row++) {
        for (int col = 0; col <= row; col++) {
            cout << pascal(row, col) << " ";
        }
        cout << endl;
    }
}

int main() {
    int levels = 3;
    printPascal(levels);
    return 0;
}
