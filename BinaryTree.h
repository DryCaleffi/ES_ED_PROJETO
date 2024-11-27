//
// Created by Marcos on 17/11/2024.
//

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "MashUp.h"

// constantes
struct node_bt {
    long long cpf;
    int id;
    struct node_bt *left;
    struct node_bt *right;
};

// variáveis
extern struct node_bt *start_bt;
extern struct node_bt *new_bt;
extern struct node_bt *aux_bt;
extern struct node_bt *current_bt;
extern struct node_bt *del_bt;
extern struct node_bt *aux_left;
extern struct node_bt *aux_right;
extern struct node_bt *parent;

// protótipos
void add_bt(struct node_bt *who_bt, struct node_bt *where_bt);
void initialize_bt();
bool search_cpf_bt(long long cpf, struct node_bt *where_bt);
void add_right();
void add_left();
void delete_bt();
void free_parent();

#endif //BINARYTREE_H
