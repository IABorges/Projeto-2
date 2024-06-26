#include <stdio.h>
#include <string.h>
#include "tarefas.h"

ERROS criar(Tarefa tarefas[], int *pos) {
  if (*pos >= TOTAL)
    return MAX_TAREFA;


int prioridade;
    do{
        printf("Entre com a prioridade de 1 a 10: ");
        scanf("%d",&prioridade);
        clearBuffer();

        if(prioridade < 1 && prioridade > 10) {
            printf("Erro numero que digitou foi menor que 1 ou maior que 10.\n");
        }
    } while (prioridade < 1 && prioridade > 10);


  printf("Entre com a categoria: ");
  fgets(tarefas[*pos].categoria, 100, stdin);
  tarefas[*pos].categoria[strcspn(tarefas[*pos].categoria, "\n")] = 0;
  printf("Entre com a descricao: ");
  fgets(tarefas[*pos].descricao, 300, stdin);
  tarefas[*pos].descricao[strcspn(tarefas[*pos].descricao, "\n")] = 0;

  *pos = *pos + 1;

  return OK;
}


ERROS deletar(Tarefa tarefas[], int *pos){
    // teste se existem tarefas
    if(*pos == 0)
        return SEM_TAREFAS;

    // verifica se a tarefa escolhida existe
    int pos_deletar;
    printf("Entre com a posicao da tarefa a ser deletada: ");
    scanf("%d", &pos_deletar);
    pos_deletar--; // garantir posicao certa no array
    if(pos_deletar >= *pos || pos_deletar < 0)
        return NAO_ENCONTRADO;

    for(int i = pos_deletar; i < *pos; i++){
        tarefas[i].prioridade = tarefas[i+1].prioridade;
        strcpy(tarefas[i].categoria, tarefas[i+1].categoria);
        strcpy(tarefas[i].descricao,  tarefas[i+1].descricao);
    }

    *pos = *pos - 1;

    return OK;
}

ERROS listar(Tarefa tarefas[], int *pos) {
    char categoria[100]; 
    char resposta[30]; 
    int existe = 0;
    printf("Digite a categoria das tarefas:\t ");
    scanf("%s", categoria);

    if (*pos == 0) {
        //printf("Não tem tarefas para listar\n");
        return SEM_TAREFAS;
    }

    for (int sequencia = 0 ; sequencia <= 0; sequencia++) { 
        for (int indice = 0; indice < *pos; indice++) {
            if (strcmp(tarefas[indice].categoria, categoria) == 0) {
                existe = 1;
                    printf("________________________________________________________\n");
                    printf("Categoria: %s \tDescricao: %s \tPrioridade: %d\t \n  ", tarefas[indice].categoria, tarefas[indice].descricao, tarefas[indice].prioridade);  
                }
            }
        }
    

    if (existe == 0) {
        printf("___________________________________________\n");
        printf("Essa categoria não existe\n");
        return NAO_ENCONTRADO;
    }

    return OK;
}

ERROS salvar(Tarefa tarefas[], int *pos){
    FILE *f = fopen("tarefas.bin", "wb");
    if(f == NULL)
        return ABRIR;

    int qtd = fwrite(tarefas, TOTAL, sizeof(Tarefa), f);
    if(qtd == 0)
        return ESCREVER;

    qtd = fwrite(pos, 1, sizeof(int), f);
    if(qtd == 0)
        return ESCREVER;

    if(fclose(f))
        return FECHAR;

    return OK;
}

ERROS carregar(Tarefa tarefas[], int *pos){
    FILE *f = fopen("tarefas.bin", "rb");
    if(f == NULL)
        return ABRIR;

    int qtd = fread(tarefas, TOTAL, sizeof(Tarefa), f);
    if(qtd == 0)
        return LER;

    qtd = fread(pos, 1, sizeof(int), f);
    if(qtd == 0)
        return LER;

    if(fclose(f))
        return FECHAR;

    return OK;

}

ERROS carregarUser(Tarefa tarefas[], int *pos){
    char arquivo[30] ;
    printf("Digite o nome do arquivo que deseja carregar: ");
    scanf("%s",arquivo);
    //printf("parabens voce sabe digitar: %s",arquivo);
    
    FILE *f = fopen(arquivo, "rb");
    if(f == NULL)
        return ABRIR;

    int qtd = fread(tarefas, TOTAL, sizeof(Tarefa), f);
    if(qtd == 0)
        return LER;

    qtd = fread(pos, 1, sizeof(int), f);
    if(qtd == 0)
        return LER;

    if(fclose(f))
        return FECHAR;

    return OK;

}

ERROS salvarUser(Tarefa tarefas[], int *pos){
    char arquivo[30] ;
    printf("Digite o nome do arquivo que deseja Salvar: ");
    scanf("%s",arquivo);

    FILE *f = fopen(arquivo, "wb");
    if(f == NULL)
        return ABRIR;

    int qtd = fwrite(tarefas, TOTAL, sizeof(Tarefa), f);
    if(qtd == 0)
        return ESCREVER;

    qtd = fwrite(pos, 1, sizeof(int), f);
    if(qtd == 0)
        return ESCREVER;

    if(fclose(f))
        return FECHAR;

    return OK;
}

ERROS gravar(Tarefa tarefas[], int *pos){
    if (*pos == 0)
        return SEM_TAREFAS;
FILE *fi = fopen("arquivo.txt","w");

if (fi==0){
    return SEM_TAREFAS;
}
    for (int i = 0; i< *pos; i++){
        fprintf(fi,"Pos: %d\t" , i++);
        fprintf(fi,"Prioridade: %d\t" , tarefas[i].prioridade);
        fprintf(fi,"Categoria: %s\t" , tarefas[i].categoria);
        fprintf(fi,"Descricao: %s\n" , tarefas[i].descricao);
    }

    if(fclose(fi))
        return FECHAR;


    return OK;

}


void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
