#ifndef PACIENTE_H
#define PACIENTE_H
#define TAM_NOME 100
typedef struct {
    char codigo[10];
    char nome[TAM_NOME];
    int idade;
    char genero[20];
    int gestante;
    int deficiencia;
    char qualDeficiencia[100];
    char tipo;
    int atendido;
} Paciente;
char classificarSenha(int idade, int gestante, int deficiencia);
void gerarCodigo(char *codigo, char tipo, int numero);
Paciente cadastrarPaciente(int *codN, int *codP, int *codU);
#endif
