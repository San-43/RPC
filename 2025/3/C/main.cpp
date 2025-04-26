#include <bits/stdc++.h>

using namespace std;

bool esEntero(double x) {
    return x == floor(x);
}

int main() {
    double a, b, cont = 0;
    cin >> a >> b;

    for (int i = a; i <= b; i++) {
        double aux = sqrt(i);
        if (esEntero(aux)) {
            cont++;
        }
    }
    cout << cont * 15 << endl;
}