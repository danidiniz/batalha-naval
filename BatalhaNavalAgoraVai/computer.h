
typedef struct jogadas_info{
    int acertou_submarinos;
    int acertou_hidro;
    int acertou_cruzador;
    int acertou_encouracado;
    int acertou_portavioes;
    int jogadas_disponiveis[m*n];
    int tamanho;
} jogadas_info;

jogadas_info jogadas_info_pc;

typedef struct jogada_atual{
    int qnt_pecas_ja_acertou;
    par acerto_inicial;
    par tentativa_atual;
    par pecas_que_acertou[5];
    orientacao direcao_da_jogada;
} jogada_atual;

jogada_atual jogada_atual_pc;

typedef struct pc_info{
    armaDeGuerra armas_pc_no_tabuleiro[13];
    int qnt_pontos;
} pc_info;

pc_info pc_info_t;

tabuleiro pcTab;
tabuleiro pcTabEscondido;

void setar_tabuleiro_pc();

tabuleiro sortear_posicoes_das_armas_do_pc(tabuleiro pcTabEscondido);

tabuleiro colocar_arma_pc_no_tabuleiro(tabuleiro tabu, char *arma_name, int indices_array[], int *tamanho);

void jogar_pc(tabuleiro *tabuleiro_visivel, tabuleiro *tabuleiro_escondido, jogadas_info *jog_info, jogada_atual *jog_atual);

void jogar_pc_burro(tabuleiro *tabuleiro_visivel, tabuleiro *tabuleiro_escondido, jogadas_info *jog_info, pc_info *pc);

void inicializa_jogadas_info(jogadas_info *jog);

void resetar_jogada_atual(jogada_atual *jog);
