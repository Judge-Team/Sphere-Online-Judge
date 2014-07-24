#include <stdio.h>

typedef struct {
    int l;
    int o;
    int d[10];
} dig_str;

dig_str t[10];

void be(dig_str * e, int x)
{
    e->d[0] = 1;

    for (int i = 1; i < 10; ++i) {
        e->d[i] = (e->d[i - 1] * x) % 10;
        for (int j = 0; j < i; ++j) {
            if (e->d[i] == e->d[j]) {
                e->l = i - j;
                e->o = j;
                return;
            }
        }
    }
}

void b()
{
    for (int i = 0; i < 10; ++i) {
        be(&t[i], i);
    }
}

void p()
{
    int a;
    int b;

    scanf("%d %d", &a, &b);

    a %= 10;

    if (b < t[a].o) {
        printf("%d\n", t[a].d[b]);
        return;
    }

    b -= t[a].o;
    b %= t[a].l;

    printf("%d\n", t[a].d[t[a].o + b]);
}

int main()
{
    int n = 0;

    scanf("%d", &n);

    b();

    for (int i = 0; i < n; ++i) {
        p();
    }

    return 0;
}
