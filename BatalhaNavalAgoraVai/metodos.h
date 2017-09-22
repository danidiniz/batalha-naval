void inicializa_arma_de_guerra(armaDeGuerra *arma, char x, int y, orientacao ori);

int posicaoValida(tabuleiro tabu, armaDeGuerra arma);

void colocaArmaNoTabuleiro(tabuleiro *tabu, armaDeGuerra arma);

int atingiu(tabuleiro tabu, char linha, int coluna);

void imprimirTabuleiro(tabuleiro tabu);

tabuleiro atualizar_tabuleiro(tabuleiro *taboleiro, char linha, int coluna, int valor);

int verifica_se_tabuleiro_ainda_possui_armas(tabuleiro tabu);

int verifica_se_arma_existe(char *nome_da_arma);

int verifica_quantidade_da_arma(char *nome_da_arma);

orientacao retorna_orientacao(char *ori);

void diminuiQuantidadeDeArma(char *nome_da_arma);

void reseta_quantidade_de_arma();

int verifica_se_esta_dentro_do_tabuleiro(char c, int numero);

void transformar_linear_em_dimensional(int *i, int *j, int valor_linear);

void remover_vizinhos(int array[], int indice_linear, int *tamanho);

