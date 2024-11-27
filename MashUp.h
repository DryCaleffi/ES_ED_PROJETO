//
// Created by Marcos on 14/11/2024.
//

#ifndef MASHUP_H
#define MASHUP_H
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "BinaryTree.h"
#include "DataBase.h"
#include "DoubleLinkedList.h"

enum {
    OP_NAO_SELECIONADA = 0,
    OP_ADICIONAR,
    OP_LISTAR_ALFABETICO,
    OP_LISTAR_DEPARTAMENTO,
    OP_RELATORIO_FUNCIONARIO,
    OP_PESQUISAR_CPF,
    OP_EXCLUIR,
    OP_ALTERAR,
    OP_SAIR,
    CPF = 1,
    LISTA,
    CANCELAR,
    DATA_NASCIMENTO = 1,
    DATA_ADMISSAO,
    SALARIO,
    EMAIL,
    CARGO,
    TELEFONE,
    DEPARTAMENTO,
    ENDERECO
};

// variáveis
extern int general_id;
extern int op;
extern long long keep_data;

// protótipos
void initialize();
void add();
void alphabetical_sort();
void cpf_search(long long cpf);
void report();
void delete();
void list_departament();
void pre_fill();
void free_all();
void alter_data();

#endif //MASHUP_H
