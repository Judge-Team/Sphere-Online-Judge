#include <stdio.h>
#include <stdlib.h>

enum State{
    LEFT,
    OP,
    RIGHT,
    END,
};

struct Node {
    struct Node * left;
    struct Node * right;
    char op;
};

struct Node * get_node()
{
    struct Node * node = malloc(sizeof(struct Node));
    if (NULL != node) {
        node->left = NULL;
        node->right = NULL;
        node->op = 0;
    }

    return node;
}

int parse_expression(const char * expression, struct Node ** tree)
{
    int index = 0;
    enum State state = LEFT;
    struct Node * node = get_node();

    if (NULL == node) {
        goto end;
    }

    for (;;) {
        switch (state) {
        case LEFT:
            switch (expression[index]) {
            case '(':
                ++index;
                index += parse_expression(&expression[index], &node->left);
                break;
            default: // operand
                node->left = get_node();
                if (NULL == node->left) {
                    goto end;
                }
                node->left->op = expression[index];
                ++index;
                break;
            }
            state = OP;
            break;
        case OP:
            node->op = expression[index];
            ++index;
            state = RIGHT;
            break;
        case RIGHT:
            switch (expression[index]) {
            case '(':
                ++index;
                index += parse_expression(&expression[index], &node->right);
                break;
            default: // operand
                node->right = get_node();
                if (NULL == node->right) {
                    goto end;
                }
                node->right->op = expression[index];
                ++index;
            }
            ++index;
            goto end;
        default:
            // ASSERT(0);
            break;
        }
    }
end:
    *tree = node;
    return index;
}

int is_leaf(const struct Node * node)
{
    return (NULL == node->left);
}

void print_tree(const struct Node * tree)
{
    if (!is_leaf(tree)) {
        print_tree(tree->left);
        print_tree(tree->right);
    }

    if (0 != tree->op) {
        printf("%c", tree->op);
    }

    return;
}

void transform_to_rpn()
{
    char * expression = malloc(400);
    int dummy = 0;
    struct Node * tree = NULL;

    if (NULL == expression) {
        return;
    }

    scanf("%s", expression);
    parse_expression(expression, &tree);
    print_tree(tree);

    return;
}

int main()
{
    int num = 0;

    scanf("%d", &num);

    for (int i = 0; i < num; ++i) {
        transform_to_rpn();
        printf("\n");
    }

    return 0;
}
