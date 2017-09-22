typedef struct player_info{
    int qnt_pontos;
} player_info;

player_info player1;
player_info player2;

tabuleiro tab;
tabuleiro tab_escondido;

tabuleiro tab_player_2;
tabuleiro tab_player_2_escondido;

void setar_tabuleiro_player();

void jogar_player(tabuleiro *tabuleiro_visivel, tabuleiro *tabuleiro_escondido, player_info *player);
