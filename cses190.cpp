#include <iostream>
#include <iomanip>
using namespace std;
  
int n, r[105];
double ans;
  
int main() {
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> r[i];
        for (int j = 1; j < i; j++){
            for (int k = 1; k <= r[i]; k++){
                if (r[j] > k) ans += (double)(r[j]-k)/r[j]/r[i];
            }
        }
    }
    cout << fixed << setprecision(6) << ans << "\n";
}