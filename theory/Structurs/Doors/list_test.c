#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#define TEST_COUNT 3
#define SUCCESS 0
#define FAIL -1

int test_add_door();
int test_remove_door();
int test_find_door();

int main()
{
    int result = SUCCESS;
    int test;
    char *name_test;

    for (int i = 0; i < TEST_COUNT; i++)
    {
        if (i == 0)
        {
            test = test_add_door();
            name_test = "Test func: Add add_door and init ->";
        }
        else if (i == 1)
        {
            test = test_remove_door();
            name_test = "Test func: Add remove_door and destroy ->";
        }
        else if (i == 2)
        {
            test = test_find_door();
            name_test = "Test func: Add find_door ->";
        }
        else
        {
            test = 0;
        }

        if (test == SUCCESS)
        {
            printf("%s SUCCESS\n", name_test);
        }
        else
        {
            printf("%s FIEL\n", name_test);
        }
    }

    return result;
}

int test_add_door()
{
    struct door door1 = {1, 0};
    struct door door2 = {2, 0};
    struct node *root = init(&door1);

    if (!root)
        return FAIL;

    struct node *new_node = add_door(root, &door2);
    if (!new_node || new_node->door->id != 2)
    {
        destroy(root);
        return FAIL;
    }

    destroy(root);

    return SUCCESS;
}

int test_remove_door()
{
    struct door door1 = {1, 0};
    struct door door2 = {2, 0};
    struct node *root = init(&door1);

    if (!root)
        return FAIL;

    struct node *new_node = add_door(root, &door2);

    if (!new_node)
    {
        destroy(root);
        return FAIL;
    }

    root = remove_door(new_node, root);
    if (!root || root->next)
    {
        destroy(root);
        return FAIL;
    }

    destroy(root);

    return SUCCESS;
}

int test_find_door()
{
    struct door door1 = {1, 0};
    struct door door2 = {2, 0};
    struct node *root = init(&door1);

    if (!root)
        return FAIL;

    struct node *new_node = add_door(root, &door2);

    if (!new_node)
    {
        destroy(root);
        return FAIL;
    }

    struct node *found_node = find_door(2, root);

    if (!found_node || found_node->door->id != 2)
    {
        destroy(root);
        return FAIL;
    }

    destroy(root);

    return SUCCESS;
}
