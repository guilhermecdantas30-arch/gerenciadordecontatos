#include <stdio.h>
#include "../include/contatos.h"

int main() {

    Contato contatos[MAX];
    int total = 0;
    int op;

    do {

        printf("\n1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Buscar\n");
        printf("4 - Editar\n");
        printf("5 - Excluir\n");
        printf("6 - Estatisticas\n");
        printf("7 - Sair\n");

        printf("Opcao: ");
        scanf("%d", &op);

        if(op == 1) cadastrarContato(contatos, &total);

        else if(op == 2) listarContatos(contatos, total);

        else if(op == 3) {
            char nome[50];
            int pos;

            printf("Nome: ");
            scanf("%s", nome);

            pos = buscarContato(contatos, total, nome);

            if(pos == -1)
                printf("Nao encontrado\n");
            else
                printf("Encontrado na posicao %d\n", pos);
        }

        else if(op == 4) editarContato(contatos, total);

        else if(op == 5) removerContato(contatos, &total);

        else if(op == 6) {
            int n;
            int r;

            printf("Contar nomes maiores que: ");
            scanf("%d", &n);

            r = contarNomeGrande(contatos, total, 0, n);

            printf("Resultado: %d\n", r);
        }

    } while(op != 7);

    return 0;
}
