#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int res = n ^ ((1 << 31) - 1);
    cout << "Toggled bits: " << res << endl;
    return 0;
}
