#include <iostream>
using namespace std;

int counter1 = 0; //global counter for O(1)
int counter2 = 0; //global counter for O(n)
int counter3 = 0; //global counter for O(log n)
int counter4 = 0; //global counter for O(n log n)
int counter5 = 0; //global counter for O(n^2)
int counter6 = 0; //global counter for O(2^n)


void constantfunction (int n){
    counter1++;
}

void linearfunction(int n){
    for (int i =1; i<=n; i++){
        counter2++;
    }
}

void logarithmicFunction(int n) {
    for (int i = 1; i < n; i *= 2) {
        counter3++;
    }
}

void linearArithmicFunction(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < n; j *= 2) {
            counter4++; 
        }
    }
}

void quadraticFunction(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            counter5++;
        }
    }
}

void exponentialFunction(int n) {
    for (int i = 1; i <= (1 << n); i++) {
        counter6++;
    }
}

int main () {
    
    int sizes[] = {1, 2, 4, 8, 16, 32, 64, 128};

    cout << "n\tO(1)\tO(n)\tO(log n)\tO(n log n)\tO(n^2)\tO(2^n)\n";

    for (int i = 0; i < 8; i++) {
        int n = sizes[i];

        // Reset all counters
        counter1 = counter2 = counter3 = counter4 = counter5 = counter6 = 0;

        constantfunction(n);
        linearfunction(n);
        logarithmicFunction(n);
        linearArithmicFunction(n);
        quadraticFunction(n);

        if (n <= 16) {
            exponentialFunction(n);
            cout << n << "\t" << counter1 << "\t" << counter2 << "\t" << counter3
                 << "\t\t" << counter4 << "\t\t" << counter5 << "\t" << counter6 << endl;
        } else {
            cout << n << "\t" << counter1 << "\t" << counter2 << "\t" << counter3
                 << "\t\t" << counter4 << "\t\t" << counter5 << "\t" << "Skipped" << endl;
        }
    }
    return 0;
}