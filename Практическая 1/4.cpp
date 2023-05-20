#include <iostream>
#include <bitset>
using namespace std;

int main() {
    double num;
    cout << "Enter a double: ";
    cin >> num;
    unsigned long long* binary = reinterpret_cast<unsigned long long*>(&num);
    bitset<sizeof(double)*8> mantissa(*binary & 0xFFFFFFFFFFFFF);
    bitset<sizeof(double)*8> exponent((*binary >> 52) & 0x7FF);
    bitset<sizeof(double)*8> sign((*binary >> 63) & 0x1);
    cout << "Binary representation of " << num << ": ";
    cout << sign << " ";
    for(int i = 0; i < exponent.size(); i++) {
        if(i == 0 || i == exponent.size()-1) {
            cout << "\033[1m" << exponent[i] << "\033[0m";
        }
        else {
            cout << exponent[i];
        }
    }
    cout << " ";
    for(int i = 0; i < mantissa.size(); i++) {
        if(i == 0) {
            cout << "\033[1m" << mantissa[i] << "\033[0m";
        }
        else {
            cout << mantissa[i];
        }
        if((i+1)%4 == 0 && i != mantissa.size()-1) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}