#include <iostream>
#include <stdlib.h>
#include <time.h>

typedef struct {
     int m;
     int n;
    float** arr;
} Matrica;

Matrica UnesiMatricu(int m, int n);
Matrica GenerirajMatricu(int m, int n, float a, float b);

Matrica ZbrojiMatrice(Matrica a, Matrica b);
Matrica OduzmiMatrice(Matrica a, Matrica b);
Matrica PomnoziMatrice(Matrica a, Matrica b);

Matrica Transponiraj(Matrica a);

void Print(Matrica a);

using namespace std;

int main() {
    srand(time(0));

    auto a = GenerirajMatricu(3, 4, 1, 10);
    auto b = GenerirajMatricu(3, 4, 1, 10);

    auto i = GenerirajMatricu(2, 3, 1, 5);
    auto j = GenerirajMatricu(3, 2, 1, 5);
    //
    auto z = ZbrojiMatrice(a, b);
    auto r = OduzmiMatrice(a, b);
    auto t = Transponiraj(j);
    auto p = PomnoziMatrice(i, j);
    Print(i);
    cout << "-----------------" << endl;
    Print(j);
    cout << "-----------------" << endl;
    Print(p);
    //auto p = PomnoziMatrice(i, j);
}

float get_random(float a, float b)
{
    float randomNumber = sin(rand() * rand());
    return a + (b - a) * fabs(randomNumber);
}

Matrica GenerirajMatricu(int m, int n, float a, float b) {
    Matrica mx;
    mx.m = m;
    mx.n = n;
    mx.arr = new float* [m];
    for (int i = 0; i < mx.m; i++) {
        mx.arr[i] = new float[n];
        for (int j = 0; j < mx.n; j++) {
            float t = get_random(a, b);
            mx.arr[i][j] = t;
        }
    }
    return mx;
}

Matrica ZbrojiMatrice(Matrica a, Matrica b)
{
    Matrica mx;
    if (a.m != b.m || a.n != b.n) {
        mx.m = 0;
        mx.n = 0;
        return mx;
    }
    mx.m = a.m;
    mx.n = a.n;
    mx.arr = new float* [a.m];
    for (int i = 0; i < mx.m; i++) {
        mx.arr[i] = new float[mx.n];
        for (int j = 0; j < mx.n; j++)
            mx.arr[i][j] = a.arr[i][j] + b.arr[i][j];
    }
    return mx;
}

Matrica OduzmiMatrice(Matrica a, Matrica b)
{
    Matrica mx;
    if (a.m != b.m || a.n != b.n) {
        mx.m = 0;
        mx.n = 0;
        return mx;
    }
    mx.m = a.m;
    mx.n = a.n;
    mx.arr = new float* [a.m];
    for (int i = 0; i < mx.m; i++) {
        mx.arr[i] = new float[mx.n];
        for (int j = 0; j < mx.n; j++)
            mx.arr[i][j] = a.arr[i][j] - b.arr[i][j];
    }
    return mx;
}

float IzracunajElement(Matrica a, Matrica b, int i, int j) {
    float sum = 0.;
    for (int k = 0; k < a.n; k++)
        sum += a.arr[i][k] * b.arr[k][j];
    return sum;
}

Matrica PomnoziMatrice(Matrica a, Matrica b)
{
    Matrica mx;
    if (a.n != b.m) {
        mx.m = 0;
        mx.n = 0;
        return mx;
    }

    mx.m = a.m;
    mx.n = b.n;
    mx.arr = new float* [a.m];
    for (int i = 0; i < mx.m; i++) {
        mx.arr[i] = new float[mx.n];
        for (int j = 0; j < mx.n; j++) {
            mx.arr[i][j] = IzracunajElement(a, b, i, j);
        }
    }
    return mx;
}

Matrica Transponiraj(Matrica a) {
    Matrica mx;
    mx.m = a.n;
    mx.n = a.m;
    mx.arr = new float* [mx.m];
    for (int i = 0; i < mx.m; i++) {
        mx.arr[i] = new float[mx.n];
        for (int j = 0; j < mx.n; j++) {
            mx.arr[i][j] = a.arr[j][i];
        }
    }
    return mx;
}

void Print(Matrica mx) {
    for (int i = 0; i < mx.m; i++) {
        cout << "|";
        for (int j = 0; j < mx.n; j++)
            cout << mx.arr[i][j] << " | ";
        cout << endl;
    }
}

Matrica UnesiMatricu(int m, int n) {
    Matrica mx;
    mx.m = m;
    mx.n = n;
    mx.arr = new float* [mx.m];
    for (int i = 0; i < mx.m; i++) {
        mx.arr[i] = new float[n];
        for (int j = 0; j < mx.n; j++) {
            float tmp;
            cout << "Unesi element na poziciji M[" << i << "]" << "[" << j << "]: " << endl;
            cin >> tmp;
            cin.ignore();
        }
    }
    return mx;
}

