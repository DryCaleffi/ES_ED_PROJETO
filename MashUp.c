//
// Created by Marcos on 14/11/2024.
//

#include "MashUp.h"

long long keep_data;
int op;
bool test;
bool test2;

void initialize() {
    initialize_db();
}

void add() {
    initialize_bt();
    initialize_dll();
    new_db = malloc(TableSize * sizeof(struct table));
    add_db();
    add_bt(new_bt, start_bt);
    add_dll(new_dll);
    printf("\nCadastro concluido\n");
    printf("--------------------\n");
}

void alphabetical_sort() {
    alphabetic_sort_dll();
}

void cpf_search(const long long cpf) {
    if(search_cpf_bt(cpf, start_bt)) {
        if(funcionario[general_id].active) {
            print_dado_db(general_id);
        } else {
            printf("CPF nao encontrado\n");
        }
    }else {
        printf("CPF nao encontrado\n");
    }
}

void report() {
    if (indice == 0) {
        printf("Tabela vazia\n");
    }else {
        for(int i = 0; i < indice; i++) {
            if(funcionario[i].active){print_dado_db(i);}
        }
    }
}

void free_all() {
    free(funcionario);
    free(start_bt);
    free(start_dll);
}

void delete(){
    op = OP_NAO_SELECIONADA;
    while(op != CANCELAR) {
        printf("\n%d - Por cpf\n", CPF);
        printf("%d - Por lista\n", LISTA);
        printf("%d - Cancelar\n", CANCELAR);
        scanf("%d", &op);
        switch(op) {
            case CPF:
                printf("\nDigite o cpf:\n");
                    scanf("%lld", &keep_data);
                    if(search_cpf_bt(keep_data, start_bt)) {
                        delete_bt(general_id);
                        delete_cpf_db(general_id);
                        delete_cpf_dll(general_id);
                        op = CANCELAR;
                        printf("\nExcluido com secesso\n");
                        printf("----------------------\n");
                    }else {
                        printf("CPF nao encontrado\n");
                    }
            break;

            case LISTA:
                alphabetical_sort();
                printf("\nDigite o ID que deseja excluir:");
                    scanf("%lld", &keep_data);
                    fflush(stdin);
                    if(find_cpf_db(keep_data) == -1) {
                        printf("ID nao encontrado\n");
                    }else {
                        search_cpf_bt(find_cpf_db(keep_data), start_bt);
                        delete_bt(general_id);
                        delete_cpf_db(general_id);
                        delete_cpf_dll(general_id);
                        op = CANCELAR;
                        printf("\nExcluido com secesso\n");
                        printf("----------------------\n");
                    }
            break;

            case CANCELAR:
            break;

            default:
                printf("\nOpcao invalida\n");
                op = OP_NAO_SELECIONADA;
            break;
        }
    }
}

void alter_data(){
    op = OP_NAO_SELECIONADA;
    while(op != CANCELAR) {
        printf("\n%d - Por cpf\n", CPF);
        printf("%d - Por lista\n", LISTA);
        printf("%d - Cancelar\n", CANCELAR);
        scanf("%d", &op);
        switch(op) {
            case CPF:
                printf("\nDigite o cpf:\n");
            scanf("%lld", &keep_data);
            if(search_cpf_bt(keep_data, start_bt)) {
                alter_dado_db(general_id);
                op = CANCELAR;
            }else {
                printf("CPF nao encontrado\n");
            }
            break;

            case LISTA:
                alphabetical_sort();
            printf("\nDigite o ID que deseja alterar:");
            scanf("%lld", &keep_data);
            fflush(stdin);
            if(find_cpf_db(keep_data) == -1) {
                printf("ID nao encontrado\n");
            }else {
                search_cpf_bt(find_cpf_db(keep_data), start_bt);
                alter_dado_db(general_id);
                op = CANCELAR;
            }
            break;

            case CANCELAR:
                break;

            default:
                printf("\nOpcao invalida\n");
            op = OP_NAO_SELECIONADA;
            break;
        }
    }
}


void list_departament() {
    test = false;
    test2 = false;
    printf("\nLogistica\n");
    printf("------------\n");
    for(int i = 0; i < indice; i++) {
        if(funcionario[i].active && funcionario[i].department == 1) {
            if(!test2) {
                printf("\n  -ID-  |  Nome\n");
                printf("-----------------\n");
                test2 = true;
            }
            print_id_dll(funcionario[i].id);
            test = true;
        }
    }
    if(!test) {
        printf("Departamento vazio\n");
        printf("------------------\n");
    }
    test = false;
    test2 = false;
    printf("\n\nRH\n");
    printf("------------\n");
    for(int i = 0; i < indice; i++) {
        if(funcionario[i].active && funcionario[i].department == 2) {
            if(!test2) {
                printf("\n  -ID-  |  Nome\n");
                printf("-----------------\n");
                test2 = true;
            }
            print_id_dll(funcionario[i].id);
            test = true;
        }
    }
    if(!test) {
        printf("Departamento vazio\n");
        printf("------------------\n");
    }
    test = false;
    test2 = false;
    printf("\n\nFinanceiro\n");
    printf("------------\n");
    for(int i = 0; i < indice; i++) {
        if(funcionario[i].active && funcionario[i].department == 3) {
            if(!test2) {
                printf("\n  -ID-  |  Nome\n");
                printf("-----------------\n");
                test2 = true;
            }
            print_id_dll(funcionario[i].id);
            test = true;
        }
    }
    if(!test) {
        printf("Departamento vazio\n");
        printf("------------------\n");
    }
    test = false;
    test2 = false;
    printf("\n\nVendas\n");
    printf("------------\n");
    for(int i = 0; i < indice; i++) {
        if(funcionario[i].active && funcionario[i].department == 4) {
            if(!test2) {
                printf("\n  -ID-  |  Nome\n");
                printf("-----------------\n");
                test2 = true;
            }
            print_id_dll(funcionario[i].id);
            test = true;
        }
    }
    if(!test) {
        printf("Departamento vazio\n");
        printf("------------------\n");
    }
    test = false;
    test2 = false;
    printf("\n\nTI\n");
    printf("------------\n");
    for(int i = 0; i < indice; i++) {
        if(funcionario[i].active && funcionario[i].department == 5) {
            if(!test2) {
                printf("\n  -ID-  |  Nome\n");
                printf("-----------------\n");
                test2 = true;
            }
            print_id_dll(funcionario[i].id);
            test = true;
        }
    }
    if(!test) {
        printf("Departamento vazio\n");
        printf("------------------\n");
    }
    test = false;
    test2 = false;
    printf("\n\nJuridico\n");
    printf("------------\n");
    for(int i = 0; i < indice; i++) {
        if(funcionario[i].active && funcionario[i].department == 6) {
            if(!test2) {
                printf("\n  -ID-  |  Nome\n");
                printf("-----------------\n");
                test2 = true;
            }
            print_id_dll(funcionario[i].id);
            test = true;
        }
    }
    if(!test) {
        printf("Departamento vazio\n");
        printf("------------------\n");
    }
}

void pre_fill() {

    // Add 2
    initialize_bt();
    initialize_dll();
    new_db = malloc(TableSize * sizeof(struct table));

    new_db[indice].id = indice;
    new_db[indice].active = true;
    new_db[indice].cpf = 78978978900;
    strcpy(new_db[indice].name, "Adryelle Caroline de Souza Calefi\n");
    strcpy(new_db[indice].birth_date, "15/02/2005\n");
    strcpy(new_db[indice].admission_date, "08/10/2024\n");
    new_db[indice].salary = 7841;
    strcpy(new_db[indice].email, "adryelle.calefi@fatec.sp.gov.br\n");
    strcpy(new_db[indice].position, "Analista\n");
    strcpy(new_db[indice].phone, "(19)98767-6849\n");
    new_db[indice].department = 5;
    strcpy(new_db[indice].address.street, "Rua Ariovaldo Silvera Franco\n");
    strcpy(new_db[indice].address.number, "567\n");
    strcpy(new_db[indice].address.district, "Jardim 31 de Marco\n");
    strcpy(new_db[indice].address.city, "Mogi Mirim\n");
    strcpy(new_db[indice].address.state, "SP\n");

    new_bt->cpf = new_db[indice].cpf;
    new_bt->id = new_db[indice].id;
    new_bt->left = NULL;
    new_bt->right = NULL;
    new_dll->id = new_db[indice].id;
    strcpy(new_dll->name, new_db[indice].name);
    new_dll->next = NULL;
    new_dll->previous = NULL;

    funcionario[indice] = new_db[indice];
    indice = indice + 1;

    add_bt(new_bt, start_bt);
    add_dll(new_dll);


    // Add 1
    initialize_bt();
    initialize_dll();
    new_db = malloc(TableSize * sizeof(struct table));

    new_db[indice].id = indice;
    new_db[indice].active = true;
    new_db[indice].cpf = 45645645600;
    strcpy(new_db[indice].name, "Tabata Etiele Roberto da Silva\n");
    strcpy(new_db[indice].birth_date, "27/04/1999\n");
    strcpy(new_db[indice].admission_date, "15/08/2023\n");
    new_db[indice].salary = 230;
    strcpy(new_db[indice].email, "tabata.silva6@fatec.sp.gov.br\n");
    strcpy(new_db[indice].position, "Desempregada do RH\n");
    strcpy(new_db[indice].phone, "(19)99593-0962\n");
    new_db[indice].department = 2;
    strcpy(new_db[indice].address.street, "Rua Ariovaldo Silvera Franco\n");
    strcpy(new_db[indice].address.number, "567\n");
    strcpy(new_db[indice].address.district, "Jardim 31 de Marco\n");
    strcpy(new_db[indice].address.city, "Mogi Mirim\n");
    strcpy(new_db[indice].address.state, "SP\n");

    new_bt->cpf = new_db[indice].cpf;
    new_bt->id = new_db[indice].id;
    new_bt->left = NULL;
    new_bt->right = NULL;
    new_dll->id = new_db[indice].id;
    strcpy(new_dll->name, new_db[indice].name);
    new_dll->next = NULL;
    new_dll->previous = NULL;

    funcionario[indice] = new_db[indice];
    indice = indice + 1;

    add_bt(new_bt, start_bt);
    add_dll(new_dll);


    // Add 1
    initialize_bt();
    initialize_dll();
    new_db = malloc(TableSize * sizeof(struct table));

    new_db[indice].id = indice;
    new_db[indice].active = true;
    new_db[indice].cpf = 47014591860;
    strcpy(new_db[indice].name, "Marcos Moreira Martins\n");
    strcpy(new_db[indice].birth_date, "27/04/1999\n");
    strcpy(new_db[indice].admission_date, "15/08/2023\n");
    new_db[indice].salary = 185;
    strcpy(new_db[indice].email, "marcos.martins19@fatec.sp.gov.br\n");
    strcpy(new_db[indice].position, "Conferente Desempregado\n");
    strcpy(new_db[indice].phone, "(19)97158-4194\n");
    new_db[indice].department = 1;
    strcpy(new_db[indice].address.street, "Rua Ariovaldo Silvera Franco\n");
    strcpy(new_db[indice].address.number, "567\n");
    strcpy(new_db[indice].address.district, "Jardim 31 de Marco\n");
    strcpy(new_db[indice].address.city, "Mogi Mirim\n");
    strcpy(new_db[indice].address.state, "SP\n");

    new_bt->cpf = new_db[indice].cpf;
    new_bt->id = new_db[indice].id;
    new_bt->left = NULL;
    new_bt->right = NULL;
    new_dll->id = new_db[indice].id;
    strcpy(new_dll->name, new_db[indice].name);
    new_dll->next = NULL;
    new_dll->previous = NULL;

    funcionario[indice] = new_db[indice];
    indice = indice + 1;

    add_bt(new_bt, start_bt);
    add_dll(new_dll);


    // Add 3
    initialize_bt();
    initialize_dll();
    new_db = malloc(TableSize * sizeof(struct table));

    new_db[indice].id = indice;
    new_db[indice].active = true;
    new_db[indice].cpf = 12312312300;
    strcpy(new_db[indice].name, "Brenda Ingrid Gaudencio\n");
    strcpy(new_db[indice].birth_date, "28/10/2000\n");
    strcpy(new_db[indice].admission_date, "10/06/2024\n");
    new_db[indice].salary = 6522;
    strcpy(new_db[indice].email, "brenda.gaudencio@fatec.sp.gov.br\n");
    strcpy(new_db[indice].position, "Dsenvolvedora\n");
    strcpy(new_db[indice].phone, "(19)99989-4168\n");
    new_db[indice].department = 5;
    strcpy(new_db[indice].address.street, "Rua Ariovaldo Silvera Franco\n");
    strcpy(new_db[indice].address.number, "567\n");
    strcpy(new_db[indice].address.district, "Jardim 31 de Marco\n");
    strcpy(new_db[indice].address.city, "Mogi Mirim\n");
    strcpy(new_db[indice].address.state, "SP\n");

    new_bt->cpf = new_db[indice].cpf;
    new_bt->id = new_db[indice].id;
    new_bt->left = NULL;
    new_bt->right = NULL;
    new_dll->id = new_db[indice].id;
    strcpy(new_dll->name, new_db[indice].name);
    new_dll->next = NULL;
    new_dll->previous = NULL;

    funcionario[indice] = new_db[indice];
    indice = indice + 1;

    add_bt(new_bt, start_bt);
    add_dll(new_dll);





    // Add 5
    initialize_bt();
    initialize_dll();
    new_db = malloc(TableSize * sizeof(struct table));

    new_db[indice].id = indice;
    new_db[indice].active = true;
    new_db[indice].cpf = 12345678901;
    strcpy(new_db[indice].name, "Pietra Goncalves\n");
    strcpy(new_db[indice].birth_date, "10/05/1997\n");
    strcpy(new_db[indice].admission_date, "01/08/2020\n");
    new_db[indice].salary = 4200.89;
    strcpy(new_db[indice].email, "pigoncalves@gmail.com\n");
    strcpy(new_db[indice].position, "Analista\n");
    strcpy(new_db[indice].phone, "(11)98765-4321\n");
    new_db[indice].department = 5;
    strcpy(new_db[indice].address.street, "Rua das Acacias\n");
    strcpy(new_db[indice].address.number, "234\n");
    strcpy(new_db[indice].address.district, "Jardim Florido\n");
    strcpy(new_db[indice].address.city, "Mogi Guacu\n");
    strcpy(new_db[indice].address.state, "SP\n");

    new_bt->cpf = new_db[indice].cpf;
    new_bt->id = new_db[indice].id;
    new_bt->left = NULL;
    new_bt->right = NULL;
    new_dll->id = new_db[indice].id;
    strcpy(new_dll->name, new_db[indice].name);
    new_dll->next = NULL;
    new_dll->previous = NULL;

    funcionario[indice] = new_db[indice];
    indice = indice + 1;

    add_bt(new_bt, start_bt);
    add_dll(new_dll);


    // Add 6
    initialize_bt();
    initialize_dll();
    new_db = malloc(TableSize * sizeof(struct table));

    new_db[indice].id = indice;
    new_db[indice].active = true;
    new_db[indice].cpf = 98765432100;
    strcpy(new_db[indice].name, "Eloa Fernandes\n");
    strcpy(new_db[indice].birth_date, "22/1/1994\n");
    strcpy(new_db[indice].admission_date, "15/03/2019\n");
    new_db[indice].salary = 5620;
    strcpy(new_db[indice].email, "eloa.fernandes@gmail.com\n");
    strcpy(new_db[indice].position, "Gerente\n");
    strcpy(new_db[indice].phone, "(21)98765-4321\n");
    new_db[indice].department = 4;
    strcpy(new_db[indice].address.street, "Avenida atlantica\n");
    strcpy(new_db[indice].address.number, "1201\n");
    strcpy(new_db[indice].address.district, "Praia Grande\n");
    strcpy(new_db[indice].address.city, "Mogi Mirim\n");
    strcpy(new_db[indice].address.state, "SP\n");

    new_bt->cpf = new_db[indice].cpf;
    new_bt->id = new_db[indice].id;
    new_bt->left = NULL;
    new_bt->right = NULL;
    new_dll->id = new_db[indice].id;
    strcpy(new_dll->name, new_db[indice].name);
    new_dll->next = NULL;
    new_dll->previous = NULL;

    funcionario[indice] = new_db[indice];
    indice = indice + 1;

    add_bt(new_bt, start_bt);
    add_dll(new_dll);


// Add 7
    initialize_bt();
    initialize_dll();
    new_db = malloc(TableSize * sizeof(struct table));

    new_db[indice].id = indice;
    new_db[indice].active = true;
    new_db[indice].cpf = 45678912309;
    strcpy(new_db[indice].name, "Benicio de castro Goncalves\n");
    strcpy(new_db[indice].birth_date, "05/07/2000\n");
    strcpy(new_db[indice].admission_date, "20/06/2021\n");
    new_db[indice].salary = 3532;
    strcpy(new_db[indice].email, "benicio_castro@gmail.com\n");
    strcpy(new_db[indice].position, "Desenvolvedor\n");
    strcpy(new_db[indice].phone, "(19)98765-4321\n");
    new_db[indice].department = 5;
    strcpy(new_db[indice].address.street, "Avenida da Saudade\n");
    strcpy(new_db[indice].address.number, "78\n");
    strcpy(new_db[indice].address.district, "Centro\n");
    strcpy(new_db[indice].address.city, "Campinas\n");
    strcpy(new_db[indice].address.state, "SP\n");

    new_bt->cpf = new_db[indice].cpf;
    new_bt->id = new_db[indice].id;
    new_bt->left = NULL;
    new_bt->right = NULL;
    new_dll->id = new_db[indice].id;
    strcpy(new_dll->name, new_db[indice].name);
    new_dll->next = NULL;
    new_dll->previous = NULL;

    funcionario[indice] = new_db[indice];
    indice = indice + 1;

    add_bt(new_bt, start_bt);
    add_dll(new_dll);


    // Add 8
    initialize_bt();
    initialize_dll();
    new_db = malloc(TableSize * sizeof(struct table));

    new_db[indice].id = indice;
    new_db[indice].active = true;
    new_db[indice].cpf = 78912345608;
    strcpy(new_db[indice].name, "Fernanda Benite\n");
    strcpy(new_db[indice].birth_date, "14/02/2003\n");
    strcpy(new_db[indice].admission_date, "10/01/2023\n");
    new_db[indice].salary = 2000.35;
    strcpy(new_db[indice].email, "fer.benite@gmail.com\n");
    strcpy(new_db[indice].position, "Estagiaria\n");
    strcpy(new_db[indice].phone, "(19)98765-4321\n");
    new_db[indice].department = 3;
    strcpy(new_db[indice].address.street, "Rua do sol\n");
    strcpy(new_db[indice].address.number, "101\n");
    strcpy(new_db[indice].address.district, "Vila Nova\n");
    strcpy(new_db[indice].address.city, "Mogi Guacu\n");
    strcpy(new_db[indice].address.state, "SP\n");

    new_bt->cpf = new_db[indice].cpf;
    new_bt->id = new_db[indice].id;
    new_bt->left = NULL;
    new_bt->right = NULL;
    new_dll->id = new_db[indice].id;
    strcpy(new_dll->name, new_db[indice].name);
    new_dll->next = NULL;
    new_dll->previous = NULL;

    funcionario[indice] = new_db[indice];
    indice = indice + 1;

    add_bt(new_bt, start_bt);
    add_dll(new_dll);
}