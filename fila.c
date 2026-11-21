#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "utils.h"

void inicializarFila(Fila *f) {
    f->inicioU = NULL; f->inicioP = NULL; f->inicioN = NULL;
    f->fimU = NULL; f->fimP = NULL; f->fimN = NULL;
    f->contU = 0; f->contP = 0; f->contN = 0;
    f->codN = 0; f->codP = 0; f->codU = 0;
    f->totalPacientes = 0;
    f->totalAtendidos = 0;
}

void adicionarNaFila(Fila *f, Paciente p) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) { printf("Erro: sem memoria!\n"); return; }
    novo->dados = p;
    novo->proximo = NULL;
    if (p.tipo == 'U') {
        if (f->inicioU == NULL) f->inicioU = novo;
        else f->fimU->proximo = novo;
        f->fimU = novo; f->contU++;
    } else if (p.tipo == 'P') {
        if (f->inicioP == NULL) f->inicioP = novo;
        else f->fimP->proximo = novo;
        f->fimP = novo; f->contP++;
    } else {
        if (f->inicioN == NULL) f->inicioN = novo;
        else f->fimN->proximo = novo;
        f->fimN = novo; f->contN++;
    }
    f->totalPacientes++;
}

int buscarProximaSenha(Fila *f, Paciente *saida) {
    if (f->inicioU != NULL) { *saida = f->inicioU->dados; return 1; }
    if (f->inicioP != NULL) { *saida = f->inicioP->dados; return 1; }
    if (f->inicioN != NULL) { *saida = f->inicioN->dados; return 1; }
    return 0;
}

void opcao02_registrarAtendimento(Fila *f) {
    printf("\n--- REGISTRAR ATENDIMENTO ---\n");
    No *remover = NULL;
    No **inicio = NULL;
    No **fim = NULL;
    int *contador = NULL;
    if (f->inicioU != NULL) { remover = f->inicioU; inicio = &f->inicioU; fim = &f->fimU; contador = &f->contU; }
    else if (f->inicioP != NULL) { remover = f->inicioP; inicio = &f->inicioP; fim = &f->fimP; contador = &f->contP; }
    else if (f->inicioN != NULL) { remover = f->inicioN; inicio = &f->inicioN; fim = &f->fimN; contador = &f->contN; }
    else { printf("Nenhum paciente aguardando.\n"); return; }
    printf("Chamando senha %s - %s\n", remover->dados.codigo, remover->dados.nome);
    printf("1 - Finalizar atendimento\n");
    printf("2 - Paciente nao compareceu / Cancelar\n");
    int op = lerInteiro("Escolha: ");
    if (op == 1) printf("Atendimento de %s (%s) FINALIZADO com sucesso!\n", remover->dados.nome, remover->dados.codigo);
    else printf("Senha %s marcada como NAO COMPARECEU.\n", remover->dados.codigo);
    *inicio = remover->proximo;
    if (*inicio == NULL) *fim = NULL;
    free(remover);
    (*contador)--;
    f->totalAtendidos++;
}

void listarFilas(Fila *f) {
    printf("\n--- FILAS DE ESPERA ---\n");
    printf("URGENTE (U):\n");
    for (No *p = f->inicioU; p != NULL; p = p->proximo)
        printf("  [%s] %s - %d anos - %s\n", p->dados.codigo, p->dados.nome, p->dados.idade, p->dados.genero);
    printf("PREFERENCIAL (P):\n");
    for (No *p = f->inicioP; p != NULL; p = p->proximo)
        printf("  [%s] %s - %d anos - %s\n", p->dados.codigo, p->dados.nome, p->dados.idade, p->dados.genero);
    printf("NORMAL (N):\n");
    for (No *p = f->inicioN; p != NULL; p = p->proximo)
        printf("  [%s] %s - %d anos - %s\n", p->dados.codigo, p->dados.nome, p->dados.idade, p->dados.genero);
    printf("\nTotal atendidos hoje: %d\n", f->totalAtendidos);
}

void liberarFila(Fila *f) {
    No *atual, *temp;
    atual = f->inicioU;
    while (atual != NULL) { temp = atual; atual = atual->proximo; free(temp); }
    atual = f->inicioP;
    while (atual != NULL) { temp = atual; atual = atual->proximo; free(temp); }
    atual = f->inicioN;
    while (atual != NULL) { temp = atual; atual = atual->proximo; free(temp); }
    f->inicioU = f->inicioP = f->inicioN = NULL;
    f->fimU = f->fimP = f->fimN = NULL;
}
