#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "paciente.h"
#include "painel.h"
#include "utils.h"

int main() {
    Fila fila;
    inicializarFila(&fila);
    int opcao;
    do {
        mostrarPainel(&fila);
        printf("\nMENU:\n");
        printf("01 - Retirar Senha\n");
        printf("02 - Registrar Atendimento (Chamar Proxima)\n");
        printf("03 - Listar Filas / Atendidos\n");
        printf("00 - Sair\n");
        opcao = lerInteiro("Escolha uma opcao: ");
        switch (opcao) {
            case 1: {
                Paciente p = cadastrarPaciente(&fila.codN, &fila.codP, &fila.codU);
                adicionarNaFila(&fila, p);
                break;
            }
            case 2: opcao02_registrarAtendimento(&fila); break;
            case 3: listarFilas(&fila); break;
            case 0: printf("Encerrando sistema...\n"); break;
            default: printf("Opcao invalida!\n"); break;
        }
        if (opcao != 0) {
            printf("\nPressione ENTER para continuar...");
            getchar();
            system("clear");
        }
    } while (opcao != 0);
    liberarFila(&fila);
    return 0;
}
