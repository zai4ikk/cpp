#include <iostream>
#include <bitset>
using namespace std;

int main() {
    float num;
    cout << "Enter a float: ";
    cin >> num;
    unsigned int* binary = reinterpret_cast<unsigned int*>(&num);
    bitset<sizeof(float)*8> mantissa(*binary & 0x7FFFFF);
    bitset<sizeof(float)*8> exponent((*binary >> 23) & 0xFF);
    bitset<sizeof(float)*8> sign((*binary >> 31) & 0x1);
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