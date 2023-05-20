#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    bitset<sizeof(int)*8> binary(num);
    cout << "Binary representation of " << num << ": ";
    for(int i = 0; i < binary.size(); i++) {
        if(i == 0 || i == binary.size()-1 || (i >= sizeof(int)*8-1 && i < binary.size()-1)) {
            cout << "\033[1m" << binary[i] << "\033[0m";
        }
        else {
            cout << binary[i];
        }
        if((i+1)%4 == 0 && i != binary.size()-1) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
