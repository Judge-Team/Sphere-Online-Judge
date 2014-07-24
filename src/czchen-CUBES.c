#include <stdio.h>

enum {
    MAX_CUBE_SIZE = 101,
};

int g_cube_table[MAX_CUBE_SIZE];

void build_cube_table()
{
    for (int i = 0; i < sizeof (g_cube_table) / sizeof (g_cube_table[0]); ++i) {
        g_cube_table[i] = i * i * i;
    }
    return;
}

void print_if_perfect_cube(const int a, const int b, const int c, const int d)
{
    if (g_cube_table[a] == g_cube_table[b] + g_cube_table[c] + g_cube_table[d]) {
        printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
    }
    return;
}

void find_perfect_cube()
{
    for (int a = 2; a < MAX_CUBE_SIZE; ++a) {
        for (int b = 2; b < a; ++b) {
            for (int c = b; c < a; ++c) {
                if (g_cube_table[a] <= g_cube_table[b] + g_cube_table[c])
                    break;

                for (int d = c; d < a; ++d) {
                    if (g_cube_table[a] < g_cube_table[b] + g_cube_table[c] + g_cube_table[d])
                        break;
                    print_if_perfect_cube(a, b, c, d);
                }
            }
        }
    }
}

int main()
{
    build_cube_table();
    find_perfect_cube();
    return 0;
}

