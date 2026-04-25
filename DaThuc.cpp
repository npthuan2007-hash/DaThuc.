#include "DaThuc.h"
#include <bits/stdc++.h>

using namespace std;

DaThuc:: DaThuc() {
    bac = 0;
    heSo = new double [100];
    heSo[0] = 0;
}
istream& operator >> (istream& in, DaThuc& dt) {
    cout << "Nhap bac cua da thuc: ";
    int newBac;
    in >> newBac;
    dt.bac = newBac;
    cout << endl;
    delete[]  dt.heSo;
    dt.heSo = new double[dt.bac + 1];
    for (int i = dt.bac; i >= 0; i--)
        {
            cout << "Nhap he so cua x^" << i << endl;
            in >> dt.heSo[i];
        }
    return in;
}
ostream& operator << (ostream& out, DaThuc& dt) {
    if(dt.bac == 0 && dt.heSo[dt.bac] == 0) {
        out << 0;
        return out;
    }
    else {
        bool isFirst = true;
        for (int i = dt.bac; i >= 0; i--) {
            if(dt.heSo[i] != 0) {
                if(dt.heSo[i] > 0 && !isFirst) cout << " + ";
                if(dt.heSo[i] < 0) cout << (isFirst ? "-" : " - ");

                double val = abs(dt.heSo[i]);
                if(val != 1 && i != 0) cout << val;
                if(i > 0) cout << "x";
                if(i > 1) cout << "^" << i;

                isFirst = 0;
 
            }

        }
    }
    return out;
}
void DaThuc::chuanHoa() {
    int n = bac;
    while (n > 0 && heSo[n] == 0) {
        n--;
    }
}
int DaThuc:: getBac() {
    return bac;
}
double* DaThuc::getHeSo() {
    return heSo;
}

DaThuc DaThuc:: operator+  (const DaThuc& dt) {
    int maxBac = max(dt.bac, this-> bac);
    DaThuc result;
    delete[] result.heSo;
    result.bac = maxBac;
    result.heSo = new double[maxBac + 1]{0};
    for(int i = 0; i <= maxBac; i++) {
        double a = (i <= this-> bac ) ? this->heSo[i] : 0;
        double b = (i <= dt.bac) ? dt.heSo[i] : 0;
        result.heSo[i] = a + b;
    }
    result.chuanHoa();
    return result;
}
DaThuc DaThuc:: operator- (const DaThuc& dt) {
    int maxBac = max(dt.bac, this-> bac);
    DaThuc result;
    delete[] result.heSo;
    result.bac = maxBac;
    result.heSo = new double[maxBac + 1]{0};
    for(int i = 0; i <= maxBac; i++) {
        double a = (i <= this-> bac ) ? this->heSo[i] : 0;
        double b = (i <= dt.bac) ? dt.heSo[i] : 0;
        result.heSo[i] = a - b;
    }
    result.chuanHoa();
    return result;
}
DaThuc DaThuc:: operator* (const DaThuc& dt) const{
    int n = this->bac + dt.bac;
    DaThuc result;
    delete[] result.heSo;
    result.bac = n;
    result.heSo = new double[n + 1]{0};
    for (int i = 0; i <= this-> bac; i++) {
        for (int j = 0; j <= dt.bac; j++) {
            result.heSo[i + j] += dt.heSo[j] * this->heSo[i];
        }
    }
    result.chuanHoa();
    return result;
}
//chia lay phan nguyen
DaThuc DaThuc:: operator/ (const DaThuc& dt) const{
    if(dt.bac == 0 && dt.heSo[0] == 0) {
        throw invalid_argument("Loi: Khong the chia cho da thuc 0");
    }
    int n = (this->bac - dt.bac);
    DaThuc result;
    if(n < 0) {
        return DaThuc();
    }
    else if(n == 0) {
        result.heSo[bac - 1] = this->heSo[bac] / dt.heSo[bac];
        result.bac = this-> bac;
        return result;
    }
  
    else {
        DaThuc du = *this;
        while (du.bac >= dt.bac && !(du.bac == 0 && du.heSo[0] == 0)) {
            int bacHienTai = du.bac - dt.bac;
            double heSoHienTai = du.heSo[du.bac] / dt.heSo[dt.bac];

            result.heSo[bacHienTai] = heSoHienTai;

            DaThuc temp;
            temp.bac = bacHienTai;
            temp.heSo[bacHienTai] = heSoHienTai;

            du = du - (dt * temp);
        }
    }
    return result;

}
double DaThuc:: operator() (double x) const {
    double val = 0;
    for (int i = 0; i < bac; i ++) {
        val += pow(x, i) * heSo[i];
    }
    return val;
}