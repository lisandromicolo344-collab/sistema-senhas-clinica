# Sistema de Senhas - Clínica

Sistema de gerenciamento de senhas de atendimento em C.

## Classificação
- **U - Urgente:** Idoso acima de 80 anos -> U001, U002...
- **P - Preferencial:** Gestante ou pessoa com deficiência -> P001, P002...
- **N - Normal:** Demais casos -> N001, N002...

Prioridade de chamada: U > P > N

## Estrutura modular
- `main.c` - Menu principal
- `paciente.h/.c` - Cadastro e classificação
- `fila.h/.c` - Lista encadeada com malloc / free
- `painel.h/.c` - Painel de atendimento
- `utils.h/.c` - Funções de leitura

## Como compilar e rodar
```bash
gcc main.c paciente.c fila.c painel.c utils.c -o clinica
./clinica
