#include <stdio.h>
#include "painel.h"
void mostrarPainel(Fila *f) {
    printf("\n==============================================\n");
    printf("        PAINEL DE ATENDIMENTO - CLINICA\n");
    printf("==============================================\n");
    Paciente prox;
    if (buscarProximaSenha(f, &prox) == 0) {
        printf("  SENHA A SER ATENDIDA: NENHUMA\n");
        printf("  Aguardando pacientes...\n");
    } else {
        printf("  PROXIMA SENHA: %s\n", prox.codigo);
        printf("  PACIENTE: %s | Idade: %d\n", prox.nome, prox.idade);
        if (prox.tipo == 'U') printf("  CLASSIFICACAO: URGENTE (Idoso +80)\n");
        if (prox.tipo == 'P') printf("  CLASSIFICACAO: PREFERENCIAL\n");
        if (prox.tipo == 'N') printf("  CLASSIFICACAO: NORMAL\n");
    }
    printf("  Total aguardando: U=%d | P=%d | N=%d\n", f->contU, f->contP, f->contN);
    printf("==============================================\n");
}
