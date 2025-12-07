#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

bool listIsOrdered(struct list *l) {
    struct node *head = l->head;
    if (head == NULL) {
        return true;
    }
    if (head->next == NULL) {
        return true;
    }

    if (head->value <= head->next->value) {
        bool ordered = true;
        head = head->next;
        while (ordered && head->next != NULL) {
            if (head->value > head->next->value) {
                ordered = false;
            }
            head = head->next;
        }
        return ordered;
    } else if (head->value >= head->next->value) {
        bool ordered = true;
        head = head->next;
        while (ordered && head->next != NULL) {
            if (head->value < head->next->value) {
                ordered = false;
            }
            head = head->next;
        }
        return ordered;
    }
    return true;
}