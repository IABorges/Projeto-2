#define TOTAL 100
#define tamanho_descricao 300
#define tamanho_categoria 100

typedef struct {
    int prioridade;
    char descricao[tamanho_descricao ];
    char categoria[tamanho_categoria];
} Tarefa;

typedef enum {OK, MAX_TAREFA, SEM_TAREFAS, NAO_ENCONTRADO, ABRIR, FECHAR, ESCREVER, LER} ERROS;

typedef ERROS (*funcao)(Tarefa[], int*);

ERROS criar(Tarefa tarefas[], int *pos);
ERROS deletar(Tarefa tarefas[], int *pos);
ERROS listar(Tarefa tarefas[], int *pos);
ERROS salvar(Tarefa tarefas[], int *pos);
ERROS carregar(Tarefa tarefas[], int *pos);
ERROS carregarUser(Tarefa tarefas[], int *pos);
ERROS salvarUser(Tarefa tarefas[], int *pos);
ERROS gravar(Tarefa tarefas[], int *pos);

void clearBuffer();
