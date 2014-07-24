#include <stdio.h>

int get_number_of_five()
{
    int value = 0;
    int value_tmp = 0;
    int count = 0;

    scanf("%d", &value);

    while (value >= 5) {
        value_tmp = value / 5;
        count += value_tmp;
        value = value_tmp;
    }

    return count;
}

int main ()
{
    int num = 0;

    scanf("%d", &num);

    for (int i = 0; i < num; ++i) {
        int number_of_five = get_number_of_five();
        printf("%d\n", number_of_five);
    }
}
