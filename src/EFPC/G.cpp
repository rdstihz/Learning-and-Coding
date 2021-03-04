#include <iostream>

using namespace std;

int main() {

    int T;
    cin >> T;
    for (int k = 1; k <= T; k++) {
        int n;
        double a, b;
        cin >> n >> a >> b;
        int x, y, z;
        int ax, ay, az;
        double maxv = -1e10;
        for (int i = 1; i <= n; i++) {
            cin >> x >> y >> z;
            if (y % 2 == 1 || y > 2 * x + 2) {
                continue;
            }
            if(!(x || y || z))
                continue;
            

            double m = 12 * x + y + 16 * z;
            double q = (x * a + y / 2 * b) / m;
            if (q > maxv) {
                maxv = q;
                ax = x, ay = y, az = z;
            }
        }
        printf("Case %d: ", k);
        if (ax) {
            printf("C");
            if (ax != 1) {
                printf("%d", ax);
            }
        }
        if (ay) {
            printf("H");
            if (ay != 1) {
                printf("%d", ay);
            }
        }
        if (az) {
            printf("O");
            if (az != 1) {
                printf("%d", az);
            }
        }
        printf("\n");
    }

    return 0;
}