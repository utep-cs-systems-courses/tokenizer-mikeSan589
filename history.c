#include "history.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

List* init_history() {
    List *list = malloc(sizeof(List));
    list->root = NULL;
    return list;
}

void add_history(List *list, char *str) {
    Item *item = malloc(sizeof(Item));
    item->str = strdup(str); // Duplicate the string to store in history
    item->next = NULL;

    if (list->root == NULL) {
        item->id = 1;
        list->root = item;
    } else {
        Item *temp = list->root;
        int id = 1;
        while (temp->next != NULL) {
            temp = temp->next;
            id++;
        }
        item->id = id + 1;
        temp->next = item;
    }
}

char *get_history(List *list, int id) {
    Item *temp = list->root;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp->str;
        }
        temp = temp->next;
    }
    return NULL;
}

void print_history(List *list) {
    Item *temp = list->root;
    while (temp != NULL) {
        printf("%d: %s\n", temp->id, temp->str);
        temp = temp->next;
    }
}

void free_history(List *list) {
    Item *current = list->root;
    Item *next;
    while (current != NULL) {
        next = current->next;
        free(current->str);
        free(current);
        current = next;
    }
    free(list);
}
