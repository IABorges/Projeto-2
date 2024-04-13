#include <stdio.h>
#include "tarefas.h"
int main(){
    funcao fs[] = {criar, deletar, listar,carregarUser,salvarUser,gravar, salvar, carregar,};

    Tarefa tarefas[TOTAL];
    int pos;
    ERROS erro = fs[7](tarefas, &pos);
    if(erro != OK)
        pos = 0;

    int opcao;
    do{
        printf("\nMenu principal\n");
        printf("1 - Criar tarefa\n");
        printf("2 - Deletar tarefa\n");
        printf("3 - Listar tarefas\n");
        printf("4 - Carregar Arquivo \n");
        printf("5 - Salvar Arquivo \n");
        printf("6 - gravar Arquivo.txt \n");
        printf("0 - Sair\n");
        printf("** SEMPRE SALVE O CODIGO ANTES DE SAIR**\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        opcao--;
        if(opcao > 5)
            printf("Opcao invalida\n");
            
        else if(opcao >= 0){ 
            erro = fs[opcao](tarefas, &pos);// aqui é onde é chamado o arquivo tarfeas.c com as funções
            //tratamento de erros
            if(erro!=0){
                if(erro == SEM_TAREFAS)
                    printf("Não ha terefas");
                else if(erro== MAX_TAREFA)
                    printf("MAximo de tarefas");
                else if(erro==NAO_ENCONTRADO)
                    printf("Não encontrado");
                else if(erro== SEM_TAREFAS)
                    printf("Sem tarefas");
                else if (erro == ABRIR)
                   printf("Abrir");
                else if (erro == ESCREVER)
                    printf( "ESCREVER");
                else if (erro == LER)
                    printf("LER");
                else if (erro == FECHAR)
                    printf("Fechar");
            }else{
                printf("Executado sem problemas, chefe");
            }
            
        }
        else
            printf("Sair...\n");

    } while(opcao >= 0);

    //fs[3](tarefas, &pos); ESTA LINHA FAZ SALVAMENTO AUTomatico
}
    
