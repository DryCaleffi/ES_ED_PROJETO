//
// Created by Marcos on 14/11/2024.
//

#ifndef DATABASE_H
#define DATABASE_H
#include "MashUp.h"

// constantes
struct address {
    char number[8];
    char street[60];
    char district[50];
    char city[40];
    char state[40];
};

struct table {
    int id;
    char name[50];
    long long cpf;
    char birth_date[20];
    char admission_date[20];
    float salary;
    int department;
    char position[30];
    char phone[25];
    char email[60];
    struct address address;
    bool active;
};

// variáveis
extern int TableSize;
extern int indice;
extern struct table *funcionario;
extern struct table *new_db;

// protótipos
void initialize_db();
void resize_db();
void new_enroll_db();
void add_db();
void print_dado_db(int idd);
void delete_cpf_db(int idd);
long long find_cpf_db(int idd);
void alter_dado_db(int idd);

#endif //DATABASE_H
