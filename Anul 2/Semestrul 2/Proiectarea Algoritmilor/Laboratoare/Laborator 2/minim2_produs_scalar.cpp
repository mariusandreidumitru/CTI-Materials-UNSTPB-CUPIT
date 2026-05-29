#include <iostream>

using namespace std;

void SORTARE1(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

void SORTARE2(int b[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(b[i] < b[j]) {
                swap(b[i], b[j]);
            }
        }
    }
}

void AFISARE(int s, int a[], int b[], int n) {
    cout << "Suma = " << s << endl;


    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;


    for(int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
}

void MINIM2(int a[], int b[], int n, int &s) {
    SORTARE1(a, n);
    SORTARE2(b, n);

    s = 0;

    for(int i = 0; i < n; i++) {
        s += a[i] * b[i];
    }

    AFISARE(s, a, b, n);
}

int main() {
    int a[100], b[100], n, s = 0;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    MINIM2(a, b, n, s);

    return 0;
}
