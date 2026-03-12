#ifndef CONTATOS_H
#define CONTATOS_H

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

#endif
