#include <stdio.h>

void print_reverse_number()
{
    int sum = 0;

    for (int i = 0; i < 2; ++i) {
        for (int j = 1;;j *= 10) {
            char c = 0;
            scanf("%c", &c);
            if (' ' == c || '\n' == c) {
                break;
            }
            sum += j * (c - '0');
#ifdef CZCHEN_DEBUG
            printf("current sum num = %d\n", sum);
#endif
        }
#ifdef CZCHEN_DEBUG
        printf("\n");
#endif
    }

    int reverse_sum = 0;

    while (sum) {
        reverse_sum *= 10;
        reverse_sum += (sum % 10);
        sum /= 10;
    }

    printf("%d\n", reverse_sum);
    return;
}

int main()
{
    int num = 0;

    scanf("%d\n", &num);

    for (int i = 0; i < num; ++i) {
        print_reverse_number();
    }

    return 0;
}
