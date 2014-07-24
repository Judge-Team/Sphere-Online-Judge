#include <stdio.h>

const char NO_NUMBER[] = "No Number\n";

int get_num_step()
{
    int x = 0;
    int y = 0;

    scanf("%d %d", &x, &y);

    if (x%2) { // x is odd
        if (x == y) {
            return x * 2 - 1;
        } else if ((x - 2) == y) {
            return x * 2 - 3;
        }
    } else { // x is even
        if (x == y) {
            return x * 2;
        } else if ((x - 2) == y) {
            return x * 2 - 2;
        }
    }

    return -1;
}

int main()
{
    int num = 0;

    scanf("%d", &num);

    for (int i = 0; i < num; ++i) {
        int step = get_num_step();
        if (-1 != step) {
            printf("%d\n", step);
        } else {
            printf("No Number\n");
        }
    }

    return 0;
}
