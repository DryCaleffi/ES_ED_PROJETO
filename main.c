        // *Nomes* //
    //  Adryelle Calefi  //
    //  Brenda Gaudêncio //
    //  Marcos Moreira   //
    //  Tabata Etiele    //

#include "MashUp.h"

long long cpf;

// protótipos
int menu();

int main(void)
{
    int opcao = OP_NAO_SELECIONADA;

    initialize();

    while(opcao != OP_SAIR) {
        opcao = menu();
        switch(opcao) {
            case OP_ADICIONAR:
                add();
            break;

            case OP_LISTAR_ALFABETICO:
                alphabetical_sort();
            break;

            case OP_LISTAR_DEPARTAMENTO:
                list_departament();
            break;

            case OP_RELATORIO_FUNCIONARIO:
                report();
            break;

            case OP_PESQUISAR_CPF:
                printf("Digite o numero do cpf do funcionario\n");
                    scanf("%lld", &cpf);
                    fflush(stdin);
                cpf_search(cpf);
            break;

            case OP_EXCLUIR:
                if(start_bt != NULL) {
                    delete();
                } else {
                    printf("Tabela vazia\n");
                }
            break;

            case OP_ALTERAR:
                alter_data();
            break;

            case OP_SAIR:
                free_all();
            break;

            case 99:
                pre_fill();
            break;

            default:
                printf("Opcao invalida!\n");
            break;
        }
    }
    return 0;
}

int menu() {
    op = OP_NAO_SELECIONADA;

    printf("\nMenu\n");
    printf("------\n");
    printf("%d - Adicionar Funcionario\n", OP_ADICIONAR);
    printf("%d - Listar por ordem alfabetica\n", OP_LISTAR_ALFABETICO);
    printf("%d - Listar por departamento\n", OP_LISTAR_DEPARTAMENTO);
    printf("%d - Gerar relatorio\n", OP_RELATORIO_FUNCIONARIO);
    printf("%d - Pesquisar por CPF\n", OP_PESQUISAR_CPF);
    printf("%d - Excluir\n", OP_EXCLUIR);
    printf("%d - Alterar dados\n", OP_ALTERAR);
    printf("%d - Sair\n", OP_SAIR);
    printf("Digite sua opcao: ");
    scanf("%d", &op);
    fflush(stdin);

    return op;
}
