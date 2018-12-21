#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double m = 0;
    int k = 0, n, t;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> t;
        if (t % 2 == 0) {
            m += t; k++;
        }
    }
    m /= k;
    cout<<fixed<<setprecision(2) << m << endl;
    return 0;
}
