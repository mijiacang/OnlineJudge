/*
求两个数A和B的最大公约数。 1<=A,B<=2^31-1
*/
#include <cstdio>
int main() {
     int x, y;
    scanf("%d %d", &x, &y);
    while (y) {
        int t = x;
        x = y;
        y = t % y;
    }
    printf("%d", x);
    return 0;
}