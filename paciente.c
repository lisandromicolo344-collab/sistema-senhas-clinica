#include <stdio.h>
#include <string.h>
#include "paciente.h"
#include "utils.h"

char classificarSenha(int idade, int gestante, int deficiencia) {
    if (idade > 80) return 'U';
    if (gestante == 1 || deficiencia == 1) return 'P';
    return 'N';
}

void gerarCodigo(char *codigo, char tipo, int numero) {
    sprintf(codigo, "%c%03d", tipo, numero);
}

Paciente cadastrarPaciente(int *codN, int *codP, int *codU) {
    Paciente novo;
    novo.atendido = 0;
    novo.gestante = 0;
    novo.deficiencia = 0;
    strcpy(novo.qualDeficiencia, "-");
    printf("\n--- RETIRAR SENHA ---\n");
    printf("Nome do paciente: ");
    lerTexto(novo.nome, TAM_NOME);
    novo.idade = lerInteiro("Idade: ");
    printf("Genero (1-Masculino / 2-Feminino / 3-Outro): ");
    int opGenero = lerInteiro("");
    if (opGenero == 1) strcpy(novo.genero, "Masculino");
    else if (opGenero == 2) strcpy(novo.genero, "Feminino");
    else strcpy(novo.genero, "Outro");
    if (strcmp(novo.genero, "Feminino") == 0) {
        int resp = lerInteiro("Esta gestante? (1-Sim / 0-Nao): ");
        novo.gestante = (resp == 1) ? 1 : 0;
    }
    int respDef = lerInteiro("Possui alguma deficiencia? (1-Sim / 0-Nao): ");
    novo.deficiencia = (respDef == 1) ? 1 : 0;
    if (novo.deficiencia == 1) {
        printf("Qual deficiencia? ");
        lerTexto(novo.qualDeficiencia, 100);
    }
    novo.tipo = classificarSenha(novo.idade, novo.gestante, novo.deficiencia);
    if (novo.tipo == 'U') { (*codU)++; gerarCodigo(novo.codigo, 'U', *codU); }
    else if (novo.tipo == 'P') { (*codP)++; gerarCodigo(novo.codigo, 'P', *codP); }
    else { (*codN)++; gerarCodigo(novo.codigo, 'N', *codN); }
    printf("\n>>> SENHA GERADA: %s <<<\n", novo.codigo);
    if (novo.tipo == 'U') printf("    Tipo: URGENTE - Idoso acima de 80 anos\n");
    if (novo.tipo == 'P') printf("    Tipo: PREFERENCIAL - Gestante / Deficiencia\n");
    if (novo.tipo == 'N') printf("    Tipo: NORMAL\n");
    printf("    Paciente: %s\n", novo.nome);
    return novo;
}
