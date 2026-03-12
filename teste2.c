#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[50];
    char telefone[20];
    char email[50];
} Contato;

void cadastrarContato(Contato contatos[], int *total);
void listarContatos(Contato contatos[], int total);
int buscarContato(Contato contatos[], int total, char nome[]);
void editarContato(Contato contatos[], int total);
void removerContato(Contato contatos[], int *total);
int contarNomeGrande(Contato contatos[], int total, int indice, int tamanho);

int main() {

    Contato contatos[MAX];
    int total = 0;
    int op;

    do {

        printf("\n1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Buscar\n");-+
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

void cadastrarContato(Contato contatos[], int *total) {

    if(*total >= MAX) {
        printf("Agenda cheia\n");
        return;
    }

    printf("Nome: ");
    scanf("%s", contatos[*total].nome);

    printf("Telefone: ");
    scanf("%s", contatos[*total].telefone);

    printf("Email: ");
    scanf("%s", contatos[*total].email);

    (*total)++;
}

void listarContatos(Contato contatos[], int total) {

    int i;

    if(total == 0) {
        printf("Nenhum contato\n");
        return;
    }

    for(i = 0; i < total; i++) {

        printf("\nContato %d\n", i);
        printf("Nome: %s\n", contatos[i].nome);
        printf("Telefone: %s\n", contatos[i].telefone);
        printf("Email: %s\n", contatos[i].email);
    }
}

int buscarContato(Contato contatos[], int total, char nome[]) {

    int i;

    for(i = 0; i < total; i++) {

        if(strcmp(contatos[i].nome, nome) == 0) {
            return i;
        }
    }

    return -1;
}

void editarContato(Contato contatos[], int total) {

    char nome[50];
    int pos;

    printf("Nome do contato: ");
    scanf("%s", nome);

    pos = buscarContato(contatos, total, nome);

    if(pos == -1) {
        printf("Contato nao encontrado\n");
        return;
    }

    printf("Novo telefone: ");
    scanf("%s", contatos[pos].telefone);

    printf("Novo email: ");
    scanf("%s", contatos[pos].email);
}

void removerContato(Contato contatos[], int *total) {

    char nome[50];
    int pos;
    int i;

    printf("Nome do contato para remover: ");
    scanf("%s", nome);

    pos = buscarContato(contatos, *total, nome);

    if(pos == -1) {
        printf("Contato nao encontrado\n");
        return;
    }

    for(i = pos; i < *total - 1; i++) {
        contatos[i] = contatos[i + 1];
    }

    (*total)--;

    printf("Contato removido\n");
}

int contarNomeGrande(Contato contatos[], int total, int indice, int tamanho) {

    int conta = 0;

    if(indice >= total)
        return 0;

    if(strlen(contatos[indice].nome) > tamanho)
        conta = 1;

    return conta + contarNomeGrande(contatos, total, indice + 1, tamanho);
}
