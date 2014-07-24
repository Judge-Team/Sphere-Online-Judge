#include <stdio.h>

int main()
{
    int x;
    while (scanf("%d", &x) == 1) {
        if (x == 42) {
            break;
        }
        printf("%d\n", x);
    }

    return 0;
}
