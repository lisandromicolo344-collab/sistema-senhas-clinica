#ifndef FILA_H
#define FILA_H
#include "paciente.h"
typedef struct No {
    Paciente dados;
    struct No *proximo;
} No;
typedef struct {
    No *inicioU, *inicioP, *inicioN;
    No *fimU, *fimP, *fimN;
    int contU, contP, contN;
    int codN, codP, codU;
    int totalPacientes;
    int totalAtendidos;
} Fila;
void inicializarFila(Fila *f);
void adicionarNaFila(Fila *f, Paciente p);
int buscarProximaSenha(Fila *f, Paciente *saida);
void opcao02_registrarAtendimento(Fila *f);
void listarFilas(Fila *f);
void liberarFila(Fila *f);
#endif
