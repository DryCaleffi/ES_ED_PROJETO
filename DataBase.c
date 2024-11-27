//
// Created by Marcos on 14/11/2024.
//
#include "DataBase.h"

int TableSize = 100;
int indice = 0;
struct table *funcionario = NULL;
struct table *new_db = NULL ;

void initialize_db() {
    funcionario = malloc(TableSize * sizeof(struct table));

}

void resize_db() {
    TableSize+= TableSize/2;
    struct table *aux = malloc(TableSize*sizeof(struct table));

    for (int i = 0; i<indice; i++){
        aux[i] = funcionario[i];
    }
    free(funcionario);
    funcionario = aux;
}


void new_enroll_db() {
    new_db[indice].id = indice;
    new_db[indice].active = true;
    printf("Bem vindo a tela de cadastro de funcioanrio, por favor digite corretamente os dados pedidos!!!\n\n");
    printf("CPF:\n");
        scanf("%lld", &new_db[indice].cpf);

        while(search_cpf_bt(new_db[indice].cpf, start_bt)) {
            printf("CPF ja cadastrado, digite novamente:\n");
            scanf("%lld", &new_db[indice].cpf);
        }

        fflush(stdin);
        printf("\nNome:\n");
            fgets(new_db[indice].name, sizeof(new_db[indice].name), stdin);

        printf("\nData nascimento:\n");
            fgets(new_db[indice].birth_date, sizeof(new_db[indice].birth_date), stdin);

        printf("\nData admissao:\n");
            fgets(new_db[indice].admission_date, sizeof(new_db[indice].admission_date), stdin);

        printf("\nSalario:\n");
            scanf("%f", &new_db[indice].salary);
            fflush(stdin);

        printf("\nEmail:\n");
            fgets(new_db[indice].email, sizeof(new_db[indice].email), stdin);

        printf("\nCargo:\n");
            fgets(new_db[indice].position, sizeof(new_db[indice].position), stdin);

        printf("\nTelefone:\n");
            fgets(new_db[indice].phone, sizeof(new_db[indice].phone), stdin);

        printf("\nDigite o numero do departamento correspondente:\n");
        printf("1- Logistica\t2- RH\t 3- Finaceiro\n4- Vendas\t5- TI\t6- Juridico\n");
            scanf("%d", &new_db[indice].department);
            fflush(stdin);
                while(new_db[indice].department < 1 || new_db[indice].department > 6) {
                    printf("\nOpcao invalida, tente novamente\n");
                    printf("1- Logistica\t2- RH\t 3- Finaceiro\n4- Vendas\t5- TI\t6- Juridico\n");
                        scanf("%d", &new_db[indice].department);
                        fflush(stdin);
                }

        printf("\n\nEndereco\nRua:\n");
            fgets(new_db[indice].address.street, sizeof(new_db[indice].address.street), stdin);

        printf("\nNumero:\n");
            fgets(new_db[indice].address.number, sizeof(new_db[indice].address.number), stdin);

        printf("\nBairro:\n");
            fgets(new_db[indice].address.district, sizeof(new_db[indice].address.district), stdin);

        printf("\nCidade:\n");
            fgets(new_db[indice].address.city, sizeof(new_db[indice].address.city), stdin);

        printf("\nEstado:\n");
            fgets(new_db[indice].address.state, sizeof(new_db[indice].address.state), stdin);

        new_bt->cpf = new_db[indice].cpf;
        new_bt->id = new_db[indice].id;
        new_bt->left = NULL;
        new_bt->right = NULL;

        new_dll->id = new_db[indice].id;
        strcpy(new_dll->name, new_db[indice].name);
        new_dll->next = NULL;
        new_dll->previous = NULL;
}

void add_db() {
    new_enroll_db();
    funcionario[indice] = new_db[indice];
    indice = indice + 1;
}

void print_dado_db(int idd) {
    printf("\n================ DADOS DO FUNCIONARIO ================\n");
    printf("ID:              %d\n", funcionario[idd].id);
    printf("Nome:            %s\n", funcionario[idd].name);
    printf("CPF:             %lld\n", funcionario[idd].cpf);
    printf("Data Nascimento: %s\n", funcionario[idd].birth_date);
    printf("Data Admissao:   %s\n", funcionario[idd].admission_date);
    printf("Salario:         R$%.2lf\n", funcionario[idd].salary);
    printf("E-mail:          %s\n", funcionario[idd].email);
    printf("Cargo:           %s\n", funcionario[idd].position);
    printf("Telefone:        %s\n", funcionario[idd].phone);

    printf("Departamento:    ");
    switch (funcionario[idd].department) {
        case 1:
            printf("Logistica\n");
        break;
        case 2:
            printf("RH\n");
        break;
        case 3:
            printf("Financeiro\n");
        break;
        case 4:
            printf("Vendas\n");
        break;
        case 5:
            printf("TI\n");
        break;
        case 6:
            printf("Juridico\n");
        break;
    }

    printf("\n================ ENDERECO =================\n");
    printf("Rua:      %s\n", funcionario[idd].address.street);
    printf("Numero:   %s\n", funcionario[idd].address.number);
    printf("Bairro:   %s\n", funcionario[idd].address.district);
    printf("Cidade:   %s\n", funcionario[idd].address.city);
    printf("Estado:   %s\n", funcionario[idd].address.state);

    printf("======================================================\n");
}

void delete_cpf_db(const int idd) {
    funcionario[idd].active = NULL;
}

long long find_cpf_db(int idd) {
    for (int i = 0; i <= indice; i++) {
        if(funcionario[i].id == idd && funcionario[i].active) {
            return funcionario[i].cpf;
        }
    }
    return -1;
}

void alter_dado_db(int idd) {
    int opcao;

    while(opcao != 99) {

        printf("\nSelecione o dado a ser alterado");
        printf("\n=============================\n");
        printf("%d- Data de nascimento\n", DATA_NASCIMENTO);
        printf("%d- Data de admissao\n", DATA_ADMISSAO);
        printf("%d- Salaraio\n", SALARIO);
        printf("%d- Email\n", EMAIL);
        printf("%d- Cargo\n", CARGO);
        printf("%d- Telefone\n", TELEFONE);
        printf("%d- Departamento\n", DEPARTAMENTO);
        printf("%d- Endereco\n", ENDERECO);
        printf("99- Finalizar\n");
        scanf("%d", &opcao);
        fflush(stdin);

        switch(opcao) {
            case DATA_NASCIMENTO:
                printf("\nData nascimento:\n");
                    fgets(funcionario[general_id].birth_date, sizeof(funcionario[general_id].birth_date), stdin);
                printf("Dado alterado\n");
                printf("-------------\n");
            break;

            case DATA_ADMISSAO:
                printf("\nData adimissao:\n");
                    fgets(funcionario[general_id].admission_date, sizeof(funcionario[general_id].admission_date), stdin);
                printf("Dado alterado\n");
                printf("-------------\n");
            break;

            case SALARIO:
                printf("\nSalario:\n");
                    scanf("%f", &funcionario[general_id].salary);
                fflush(stdin);
                printf("Dado alterado\n");
                printf("-------------\n");
            break;

            case EMAIL:
                printf("\nEmail:\n");
                    fgets(funcionario[general_id].email, sizeof(funcionario[general_id].email), stdin);
                printf("Dado alterado\n");
                printf("-------------\n");
            break;

            case CARGO:
                printf("\nCargo:\n");
                    fgets(funcionario[general_id].position, sizeof(funcionario[general_id].position), stdin);
                printf("Dado alterado\n");
                printf("-------------\n");
            break;

            case TELEFONE:
                printf("\nTelefone:\n");
                    fgets(funcionario[general_id].phone, sizeof(funcionario[general_id].phone), stdin);
                printf("Dado alterado\n");
                printf("-------------\n");
            break;

            case DEPARTAMENTO:
                printf("\nDigite o numero do departamento correspondente:\n");
                printf("1- Logistica\t2- RH\t 3- Finaceiro\n4- Vendas\t5- TI\t6- Juridico\n");
                    scanf("%d", &funcionario[general_id].department);
                fflush(stdin);
                while(funcionario[general_id].department < 1 || funcionario[general_id].department > 6) {
                    printf("\nOpcao invalida, tente novamente\n");
                    printf("1- Logistica\t2- RH\t 3- Finaceiro\n4- Vendas\t5- TI\t6- Juridico\n");
                    scanf("%d", &funcionario[general_id].department);
                    fflush(stdin);
                }
                printf("Dado alterado\n");
                printf("-------------\n");
            break;

            case ENDERECO:
                printf("\n\nEndereco\nRua:\n");
                    fgets(funcionario[general_id].address.street, sizeof(funcionario[general_id].address.street), stdin);

                printf("\nNumero:\n");
                    fgets(funcionario[general_id].address.number, sizeof(funcionario[general_id].address.number), stdin);

                printf("\nBairro:\n");
                    fgets(funcionario[general_id].address.district, sizeof(funcionario[general_id].address.district), stdin);

                printf("\nCidade:\n");
                    fgets(funcionario[general_id].address.city, sizeof(funcionario[general_id].address.city), stdin);

                printf("\nEstado:\n");
                    fgets(funcionario[general_id].address.state, sizeof(funcionario[general_id].address.state), stdin);
                printf("Dado alterado\n");
                printf("-------------\n");
            break;

            case 99:
            break;

            default:
                printf("Opcao invalida!\n");
            break;
        }
    }
}



