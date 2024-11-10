#include "list.h"

#include <stdio.h>
#include <stdlib.h>

struct node *init(struct door *door);
struct node *add_door(struct node *elem, struct door *door);
struct node *find_door(int door_id, struct node *root);
struct node *remove_door(struct node *elem, struct node *root);
void destroy(struct node *root);

/*
    struct node* init(struct door* door) -
    инициализация структуры односвязного списка на базе переданной struct door
*/
struct node *init(struct door *door)
{
    struct node *new_node = malloc(sizeof(struct node));

    if (new_node)
    {
        new_node->door = door;
        new_node->next = NULL;
    }

    return new_node;
}

/*
    struct node* add_door(struct node* elem, struct door* door) -
    вставка нового элемента struct door в односвязный список после переданного узла elem
*/
struct node *add_door(struct node *elem, struct door *door)
{
    if (!elem)
        return NULL;
    struct node *new_node = init(door);
    if (new_node)
    {
        new_node->next = elem->next;
        elem->next = new_node;
    }
    return new_node;
}

/*
    struct node* find_door(int door_id, struct node* root) - поиск двери в списке по её id
*/
struct node *find_door(int door_id, struct node *root)
{
    for (struct node *current = root; current; current = current->next)
    {
        if (current->door->id == door_id)
        {
            return current;
        }
    }
    return NULL;
}

/*
    struct node* remove_door(struct node* elem, struct node* root) -
    удаление элемента списка
*/
struct node *remove_door(struct node *elem, struct node *root)
{
    if (!elem || !root)
        return NULL;
    if (root == elem)
    {
        struct node *new_root = root->next;
        free(root);
        return new_root;
    }
    for (struct node *current = root; current->next; current = current->next)
    {
        if (current->next == elem)
        {
            current->next = elem->next;
            free(elem);
            break;
        }
    }
    return root;
}

/*
    void destroy(struct node* root) - освобождение памяти, занимаемой структурой списка
*/
void destroy(struct node *root)
{
    while (root)
    {
        struct node *next = root->next;
        free(root);
        root = next;
    }
}
