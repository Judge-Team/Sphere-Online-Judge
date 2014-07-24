#include <stdio.h>
#include <string.h>

enum {
    IDENTIFIER_LEN = 100,
};

enum Mode{
    UNKNOWN,
    CPP_TO_JAVA,
    JAVA_TO_CPP,
};

int is_lower_case(const char c)
{
    if (c >= 'a' && c <= 'z') {
        return 1;
    }
    return 0;
}

int is_upper_case(const char c)
{
    if (c >= 'A' && c <= 'Z') {
        return 1;
    }
    return 0;
}

int is_underscore(const char c)
{
    return ('_' == c);
}

char to_lower(const char c)
{
    if (is_upper_case(c)) {
        return c + 'a' - 'A';
    }
    return 0;
}

char to_upper(const char c)
{
    if (is_lower_case(c)) {
        return c + 'A' - 'a';
    }
    return 0;
}

int convert(char * new_id, const char * old_id)
{
    enum Mode mode = UNKNOWN;
    int old_id_len = strlen(old_id);


    // The first character is always lower case.
    if (!is_lower_case(old_id[0])) {
        return 0;
    }

    new_id[0] = old_id[0];

    int new_index = 1;
    for (int old_index = 1; old_index < old_id_len; ++old_index, ++new_index) {
        if (is_lower_case(old_id[old_index])) {
            new_id[new_index] = old_id[old_index];
        } else if (is_upper_case(old_id[old_index]) && CPP_TO_JAVA != mode) {
            mode = JAVA_TO_CPP;
            new_id[new_index] = '_';
            ++new_index;
            new_id[new_index] = to_lower(old_id[old_index]);
        } else if (is_underscore(old_id[old_index]) && JAVA_TO_CPP != mode) {
            mode = CPP_TO_JAVA;
            ++old_index;

            // If this underscore is the last character, we will read the '\0'.
            if (is_lower_case(old_id[old_index])) {
                new_id[new_index] = to_upper(old_id[old_index]);
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }
    new_id[new_index] = '\0';
    return 1;
}

int main()
{
    char old_id[IDENTIFIER_LEN + 1] = {0};
    char new_id[IDENTIFIER_LEN * 2 - 1 + 1] = {0};

    for (;;) {
        if (EOF == scanf("%s", old_id)) {
            break;
        }

        if (convert(new_id, old_id)) {
            printf("%s\n", new_id);
        } else {
            printf("Error!\n");
        }
    }

    return 0;
}
