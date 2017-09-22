#define m 15
#define n 15

typedef enum orientacao {NORTE, SUL, LESTE, OESTE, INVALIDO}orientacao;

typedef struct par{int i; int j;}par;
/* Uma celula da matriz */
typedef struct celula {int vazia;}celula;
/* Tabuleiro composto por celulas */
typedef struct tabuleiro {celula cel[m][n]; char *name;}tabuleiro;
/* Arma possui um array de celulas. Cada posicao representa uma celula no tabuleiro. */
typedef struct armaDeGuerra {orientacao ori; par pares[5]; par config; char *name;}armaDeGuerra;

int qntSubmarino;
int qntHidroAviao;
int qntCruzador;
int qntEncouracado;
int qntPortaAvioes;
