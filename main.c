#include <stdio.h>
#include "atendimento.h"

int main(void) {
    /* Complete as chamadas indicadas nos comentarios. */
    Atendimento *hospital = NULL;
    Paciente chamado;
    Paciente proximo;

    /* Criar atendimento com capacidade para 6 pacientes. */


    /* Cadastrar, nesta ordem:
       Alfredo, 31 anos
       Bruno, 10 anos
       Claudio, 29 anos
       Darcy, 31 anos
       Ester, 56 anos
       Jeronimo, 62 anos
    */


    printf("\n Pacientes na espera: %d\n", hospital->quantidade);

    /* Consultar o proximo paciente, sem remove-lo,
       e imprimir sua senha e nome. */


    printf("\nIndice da senha 2: %d\n", buscarPaciente(hospital, 2));
    printf("\nIndice da senha 99: %d\n", buscarPaciente(hospital, 99));
    imprimirEspera(hospital);

   /* Tentar cadastrar Gabi, 36 anos.
      O programa deve imprimir uma mensagem indicando
      que o vetor esta cheio. */


    /* Chamar os proximos tres pacientes.
       Para cada chamada bem-sucedida, imprimir a senha e o nome. */


    printf("Pacientes restantes: %d\n", hospital->quantidade);


    imprimirEspera(hospital);

    /* Liberar atendimento. */


    printf("Estrutura liberada: %s\n", hospital == NULL ? "sim" : "nao");
    return 0;
}
