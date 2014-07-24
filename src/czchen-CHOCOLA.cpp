#include <stdio.h>
#include <stdlib.h>

enum {
    CHOCOLATE_SIZE = 1000,
};

struct cost_entry {
    int cost;
    int accumulative_cost;
};

void build_accumulative_cost(const int len, struct cost_entry table[])
{
    table[len - 1].accumulative_cost = table[len - 1].cost;

    for (int i = len - 2; i >= 0; --i) {
        table[i].accumulative_cost = table[i].cost + table[i + 1].accumulative_cost;
    }
}

void load(const int len, struct cost_entry entry[])
{
    for (int i = 0; i < len ; ++i) {
        scanf("%d", &entry[i].cost);
    }
    return;
}

int compare(const void * x, const void * y)
{
    return ((const struct cost_entry*)y)->cost - ((const struct cost_entry*)x)->cost;
}

int get_cost(const int len_x, struct cost_entry cost_x[], const int len_y, struct cost_entry cost_y[])
{
    int cost = 0;

    qsort(cost_x, len_x, sizeof(cost_x[0]), compare);
    qsort(cost_y, len_y, sizeof(cost_y[0]), compare);

    build_accumulative_cost(len_x, cost_x);
    build_accumulative_cost(len_y, cost_y);

    int cutted_x = 0;
    int cutted_y = 0;

    while (len_x > cutted_x && len_y > cutted_y) {
        if (cost_x[cutted_x].cost > cost_y[cutted_y].cost) {
            cost += cost_x[cutted_x].cost;
            cost += cost_y[cutted_y].accumulative_cost;
            ++cutted_x;
        } else {
            cost += cost_y[cutted_y].cost;
            cost += cost_x[cutted_x].accumulative_cost;
            ++cutted_y;
        }
    }

    if (len_x > cutted_x) {
        cost += cost_x[cutted_x].accumulative_cost;
    } else {
        cost += cost_y[cutted_y].accumulative_cost;
    }

    return cost;
}

int main()
{
    int num = 0;
    int len_x;
    int len_y;
    struct cost_entry cost_x[CHOCOLATE_SIZE];
    struct cost_entry cost_y[CHOCOLATE_SIZE];

    scanf("%d", &num);

    for (int i = 0; i < num; ++i) {
        scanf("%d %d", &len_x, &len_y);
        --len_x;
        --len_y;
        load(len_x, cost_x);
        load(len_y, cost_y);
        int cost = get_cost(len_x, cost_x, len_y, cost_y);
        printf("%d\n", cost);
    }

    return 0;
}
