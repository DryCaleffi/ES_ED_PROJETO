//
// Created by Marcos on 17/11/2024.
//

#include "DoubleLinkedList.h"

struct node_dll *start_dll = NULL;
struct node_dll *new_dll = NULL;
struct node_dll *current_dll = NULL;
struct node_dll *previous_dll = NULL;
struct node_dll *delete_dll = NULL;
struct node_dll *print_dll = NULL;

void initialize_dll() {
    new_dll = malloc(100*sizeof(struct node_dll));
    print_dll = malloc(100*sizeof(struct node_dll));
}

void add_dll(struct node_dll *str1) {
    if(start_dll == NULL) {
        start_dll = malloc(100*sizeof(struct node_dll));
        start_dll = new_dll;
        new_dll->next = NULL;
        new_dll->previous = NULL;

    }else if (compare(new_dll->name, start_dll->name)) {
        new_dll->next = start_dll;
        new_dll->previous = NULL;
        start_dll->previous = new_dll;
        start_dll = new_dll;

    }else if (start_dll->next == NULL) {
        start_dll->next = new_dll;
        new_dll->previous = start_dll;
        new_dll->next = NULL;

        }else{
            struct node_dll *current_dll = start_dll;
            while (current_dll->next != NULL && !compare(new_dll->name, current_dll->next->name)) {
                current_dll = current_dll->next;
            }
            new_dll->next = current_dll->next;
            if (current_dll->next != NULL) {
                current_dll->next->previous = new_dll;
            }
            current_dll->next = new_dll;
            new_dll->previous = current_dll;
        }
}

bool compare(const char *str1, const char *str2) {
    return stricmp(str1, str2) < 0;  // Retorna verdadeiro se str1 < str2
}

void alphabetic_sort_dll() {
    if(start_dll == NULL) {
        printf("Lista vazia\n");
        return;
    }
    printf("\n  -ID-  |  Nome\n");
    printf("-------------------------------------------\n");
    print_dll = start_dll;
    while (print_dll != NULL) {
        printf(" %4d   |  %s", print_dll->id, print_dll->name);
        printf("-------------------------------------------\n");
        print_dll = print_dll->next;
    }
}

void delete_cpf_dll(const int idd) {
    delete_dll = start_dll;
    while (delete_dll != NULL) {
        if (delete_dll->id == idd) {
            if (delete_dll == start_dll) {
                start_dll = delete_dll->next;
                if (start_dll != NULL) {
                    start_dll->previous = NULL;
                }
            }
            else if (delete_dll->next == NULL) {
                delete_dll->previous->next = NULL;
            }
            else {
                delete_dll->previous->next = delete_dll->next;
                delete_dll->next->previous = delete_dll->previous;
            }
            free(delete_dll);
                        return;
        }
        delete_dll = delete_dll->next;
    }
}

void print_id_dll(const int idd) {
    print_dll = start_dll;
    while (print_dll != NULL) {
        if(print_dll->id == idd) {
            printf(" %4d   |  %s", print_dll->id, print_dll->name);
            printf("-------------------------------------------\n");
        }
        print_dll = print_dll->next;
    }
}