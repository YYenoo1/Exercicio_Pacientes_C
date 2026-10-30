#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atendimento.h"

/* 1) Aloque a estrutura Atendimento e um vetor de Paciente com malloc.
   Inicialize quantidade=0, capacidade e proximaSenha=1.
   Considere que as alocacoes sao bem-sucedidas. */
Atendimento *criarAtendimento(int capacidade) {
   Atendimento*atendimento=malloc(sizeof(Atendimento));
   atendimento->capacidade=capacidade;
   atendimento->quantidade=0;
   atendimento->proximaSenha=1;
   atendimento->quantidade=malloc(capacidade*sizeof(Paciente));
   return atendimento;
}

/* 2) Se nao houver vaga, imprima uma mensagem e encerre a função. 
   Se houver vaga, cadastre um Paciente no final do vetor.
   Copie o nome, atribua a idade, gere uma senha sequencial e aumente quantidade. */
void cadastrarPaciente(Atendimento *atendimento, const char nome[], int idade) {
   if (atendimento->quantidade>=atendimento->capacidade){
      printf("A capacidade esta cheia");
      return;
   }
   strcy(atendimento->pacientes[atendimento->quantidade].nome, nome);
   atendimento->pacientes[atendimento->quantidade].idade=idade;
   atendimento->pacientes[atendimento->quantidade].senha=atendimento->proximaSenha;
   atendimento->quantidade++;
   atendimento->proximaSenha++;
}

/* 3) Imprima todos os pacientes aguardando, na ordem do vetor,
   mostrando senha, nome e idade. */
void imprimirEspera(const Atendimento *atendimento) {
   for(int i=0; i<atendimento->quantidade; i++){
      printf("Nome: %d\n", atendimento->pacientes[i].nome);
      printf("Idade: %d\n", atendimento->pacientes[i].idade);
      printf("Senha: %d\n", atendimento->pacientes[i].senha);
   }
}

/* 4) Consulte o primeiro paciente sem remove-lo.
   Copie seus dados para *proximo.
   Retorne 1 se houver paciente ou 0 caso contrario. */
int consultarProximo(const Atendimento *atendimento, Paciente *proximo) {
   if (atendimento->quantidade==0){
      printf("Sem pacientes");
      return;
   }
   *proximo=atendimento->pacientes[0];
   return 1;
}

/* 5) Busque um paciente pela senha e retorne seu indice no vetor.
   Retorne -1 quando a senha nao for encontrada. */
int buscarPaciente(const Atendimento *atendimento, int senha) {
   for(int i=0; i<atendimento->quantidade; i++){
      if (atendimento->pacientes[i].senha==senha){
         return i;
      }
   }
   return -1;
}

/* 6) Libere o vetor e a estrutura Atendimento.
   Ao final, *atendimento deve ser NULL. */
void liberarAtendimento(Atendimento **atendimento) {
   free((*atendimento)->pacientes);
   free(*atendimento);
   *atendimento=NULL;
}

/* 7) DESAFIO: Chame o primeiro paciente para atendimento.

   Copie o paciente para *chamado.

   Remova esse paciente do vetor, deslocando os elementos
   seguintes uma posicao para a esquerda.

   Atualize a quantidade de pacientes cadastrados.

   Retorne 1 se houve atendimento ou 0 se nao houver pacientes. */
int chamarProximo(Atendimento *atendimento, Paciente *chamado) {
   if(atendimento->quantidade==0){
      printf("Não há elementos");
      return 0;
   }
   *chamado=atendimento->pacientes[0];
   for(int i=0; i<(atendimento->quantidade-1);i++){
      atendimento->pacientes[i]=atendimento->pacientes[i+1];
   }
   atendimento->quantidade--;
   return 1;
}
