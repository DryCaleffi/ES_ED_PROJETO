//
// Created by Marcos on 17/11/2024.
//

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "MashUp.h"

// constantes
struct node_dll {
    int id;
    char name[50];
    struct node_dll *next;
    struct node_dll *previous;
};

// variáveis
extern struct node_dll *start_dll;
extern struct node_dll *new_dll;
extern struct node_dll *current_dll;
extern struct node_dll *previous_dll;
extern struct node_dll *print_dll;
extern struct node_dll *delete_dll;

// protótipos
void add_dll(struct node_dll *str1);
bool compare(const char *str1, const char *str2);
void initialize_dll();
void alphabetic_sort_dll() ;
void delete_cpf_dll(int idd);
void print_id_dll(int idd);

#endif //DOUBLELINKEDLIST_H
