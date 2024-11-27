//
// Created by Marcos on 17/11/2024.
//

#include "BinaryTree.h"

int general_id = -1;
struct node_bt *start_bt = NULL;
struct node_bt *new_bt = NULL;
struct node_bt *aux_bt = NULL;
struct node_bt *current_bt = NULL;
struct node_bt *del_bt = NULL;
struct node_bt *aux_left = NULL;
struct node_bt *aux_right = NULL;
struct node_bt *parent = NULL;
bool esquerda;

void initialize_bt() {
    new_bt = malloc(sizeof(struct node_bt));
}

void add_bt(struct node_bt *who_bt, struct node_bt *where_bt) {

    if (start_bt == NULL) {
        start_bt = malloc(sizeof(struct node_bt));
        memcpy(start_bt, who_bt,sizeof(struct node_bt));
        start_bt->left = NULL;
        start_bt->right = NULL;

    }else {
        aux_bt = malloc(sizeof(struct node_bt));
        memcpy(aux_bt, who_bt, sizeof(struct node_bt));
        current_bt = where_bt;
        if(who_bt->cpf > where_bt->cpf) {
            add_right();
        }else {
            add_left();
        }
    }
}

void add_right() {
    if (current_bt->right == NULL) {
        current_bt->right = aux_bt;
    }else {
        add_bt(aux_bt, current_bt->right);
    }
}

void add_left() {
    if (current_bt->left == NULL) {
        current_bt->left = aux_bt;
    }else {
        add_bt(aux_bt, current_bt->left);
    }
}



bool search_cpf_bt(const long long cpf, struct node_bt *where_bt) {
    if (start_bt == NULL) {
        return false;
    }
    if (where_bt->cpf == cpf) {
        general_id = where_bt->id;
        del_bt = where_bt;
        return true;
    }
    if(where_bt->right != NULL && cpf > where_bt->cpf) {
        parent = where_bt;
        search_cpf_bt(cpf, where_bt->right);
    }else if(where_bt->left != NULL && cpf < where_bt->cpf) {
        parent = where_bt;
        search_cpf_bt(cpf, where_bt->left);
    }else {
        return false;
    }
}

void delete_bt() {

        if(del_bt->right == NULL && del_bt->left == NULL) {
            del_bt = NULL;
            parent = NULL;
        }else if(del_bt->right == NULL && del_bt->left != NULL) {
            aux_left = del_bt->left;
            del_bt = NULL;
            parent = NULL;
            add_bt(aux_left, start_bt);
        }else if(del_bt->right != NULL && del_bt->left == NULL) {
            aux_right = del_bt->right;
            del_bt = NULL;
            parent = NULL;
            add_bt(aux_right, start_bt);
        }else {
            aux_left = del_bt->left;
            aux_right = del_bt->right;
            del_bt = NULL;
            parent = NULL;
            add_bt(aux_left, start_bt);
            add_bt(aux_right, start_bt);
        }
}
