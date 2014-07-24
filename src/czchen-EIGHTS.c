#include <stdio.h>

void print_result()
{
    long long input = 0;
    long long output_head = 0;
    long long output_tail = 0;

    scanf("%Ld", &input);

    --input;

    output_head = input / 4;
    output_tail = input % 4;

    switch (input % 4) {
    case 0:
        output_tail = 192;
        break;
    case 1:
        output_tail = 442;
        break;
    case 2:
        output_tail = 692;
        break;
    case 3:
        output_tail = 942;
        break;
    default:
        break;
    }

    if (output_head)
        printf("%Ld", output_head);

    printf("%Ld\n", output_tail);

    return;
}

int main()
{
    size_t num = 0;

    scanf("%zd", &num);

    for (int i = 0; i < num; ++i) {
        print_result();
    }

    return 0;
}
