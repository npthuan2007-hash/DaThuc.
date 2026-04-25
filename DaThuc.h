#ifndef DATHUC_H
#define DATHUC_H

#include <iostream>

using namespace std;

class DaThuc{
private: 
    int bac;
    double* heSo;
    void chuanHoa();
public:
    DaThuc();

    friend std::istream& operator >> (std:: istream& in, DaThuc& dt);
    friend std::ostream& operator << (std:: ostream& out, DaThuc& dt);

    DaThuc operator + (const DaThuc& dt);
    DaThuc operator - (const DaThuc& dt);
    DaThuc operator * (const DaThuc& dt) const;
    DaThuc operator / (const DaThuc& dt) const;
    
    double operator () (double x) const;
    

    int getBac();
    double* getHeSo();
    
    

};
#endif