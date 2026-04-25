#include "DaThuc.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
    DaThuc dt1, dt2;
    cout << "Nhap P(x): ";
    cout << endl;
    cin >> dt1;
    cout << "Nhap Q(x): ";
    cin >> dt2;
    DaThuc tong = dt1 + dt2;
    DaThuc hieu = dt1 - dt2;
    DaThuc tich = dt1 * dt2;
    DaThuc thuong = dt1 / dt2;

    cout << "P(x) + Q(x) = " << tong << endl;
    cout << "P(x) - Q(x) = " << hieu << endl;
    cout << "P(x) * Q(x) = " << tich << endl;
    cout << "P(x) / Q(x) = " << thuong << endl;
    cout << "Tinh gia tri cua da thuc (nhap x): "; cout << endl;
    double x;
    cin >> x;
    cout << "P(" << x << ") = " << dt1(x) << endl;  
    cout << "Q(" << x << ") = " << dt2(x) << endl;
    return 0;
}