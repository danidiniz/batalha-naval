#include <stdio.h>
#include <stdlib.h>
#include"estrutura.h"
#include"player.h"
#include"computer.h"

int main()
{
    player1.qnt_pontos = 0;
    player2.qnt_pontos = 0;
    pc_info_t.qnt_pontos = 0;

    reseta_quantidade_de_arma();

    time_t t;
    srand((unsigned)time(&t));

    printf("--------------Bem vindo ao Batalha Naval no mar negro--------------\n");
    printf("LEGENDA:\n");
    printf("0 -> Posicao vazia.\n");
    printf("1 -> Posicao contem uma arma.\n");
    printf("5 -> Atirou nessa posicao E acertou uma arma inimiga.\n");
    printf("9 -> Atirou nessa posicao e NAO acertou uma arma inimiga.\n\n");

    int escolha;
    printf("Opcoes:\n1-Player vs PC\n2-Player vs Player\nEscolha contra quem deseja jogar: ");
    do{
        scanf("%d", &escolha);
        if(escolha == 1){
            printf("\n\n");
            pcTab.name = "PC";
            setar_tabuleiro_pc(pcTabEscondido);

            printf("Nome do player 1: ");
            char name1[15];
            scanf("%s", &name1);
            tab.name = name1;
            tab_escondido.name = name1;
            reseta_quantidade_de_arma();
            setar_tabuleiro_player(&tab_escondido);
            printf("Tabuleiro do(a) %s completo!\n\n", tab.name);
            reseta_quantidade_de_arma();
        } else if(escolha == 2){
            printf("\n\n");
            printf("Nome do player 1: ");
            char name1[15];
            scanf("%s", &name1);
            tab.name = name1;
            tab_escondido.name = name1;

            printf("\nNome do player 2: ");
            char name2[15];
            scanf("%s", &name2);
            tab_player_2.name = name2;
            tab_player_2_escondido.name = name2;
            printf("\n");

            reseta_quantidade_de_arma();
            setar_tabuleiro_player(&tab_escondido);
            printf("Tabuleiro do(a) %s completo!\n\n", tab.name);
            reseta_quantidade_de_arma();
            setar_tabuleiro_player(&tab_player_2_escondido);
            printf("Tabuleiro do(a) %s completo!\n\n", tab_player_2.name);
            reseta_quantidade_de_arma();
        } else{
            printf("Opcao invalida.\nEscolha novamente: ");
        }
    }while(escolha != 1 && escolha != 2);

    printf("Modos de jogo:\n1-Numero maximo de rodadas\n2-To the death!\nEscolha um modo de jogo: ");
    int modo_de_jogo;
    do{
        scanf("%d", &modo_de_jogo);
        if(modo_de_jogo != 1 && modo_de_jogo != 2){
            printf("Opcao invalida.\nEscolha novamente: ");
        }
    } while(modo_de_jogo != 1 && modo_de_jogo != 2);

    int numero_de_rodadas;
    if(modo_de_jogo == 1){
        printf("Escolha o numero maximo de rodadas: ");
        do{
            scanf("%d", &numero_de_rodadas);
            if((numero_de_rodadas < 1) || (numero_de_rodadas > (m*n))){
                printf("Numero invalido.\nEscolha entre 1 e %d: ", m*n);
            }
        } while((numero_de_rodadas < 1) || (numero_de_rodadas > (m*n)));
    } else{
        printf("Prepare-se para jogar ate cansar...");
    }

    printf("\nHora de jogar!!!\n\n");

    int contador_de_rodadas = 0;

    if(escolha == 1){

        inicializa_jogadas_info(&jogadas_info_pc);

        do{
            printf("------Rodada %d------\n", contador_de_rodadas+1);

            printf("Vez do(a) %s atirar!\n", tab.name);
            jogar_player(&pcTab, &pcTabEscondido, &player1);
            if(verifica_se_tabuleiro_ainda_possui_armas(pcTabEscondido) == 0){
                printf("Parabens! Voce destruiu todas armas do PC e GANHOU!\n");
            } else{
                printf("Vez do PC atirar!\n");
                //jogar_pc(&tab, &tab_escondido, &jogadas_info_pc, &jogada_atual_pc);
                jogar_pc_burro(&tab, &tab_escondido, &jogadas_info_pc, &pc_info_t);
                printf("Tabuleiro do(a) %s apos a jogada do PC:\n", tab.name);
                imprimirTabuleiro(tab);
                printf("\n");

                if(verifica_se_tabuleiro_ainda_possui_armas(pcTabEscondido) == 0){
                    printf("O PC destruiu todas as suas armas!!! VOCE PERDEU LOSER ¬¬\n");
                }
            }
            contador_de_rodadas++;
            printf("\n\n");
        } while(verifica_se_tabuleiro_ainda_possui_armas(pcTabEscondido) == 1 && verifica_se_tabuleiro_ainda_possui_armas(tab_escondido) == 1 && contador_de_rodadas < numero_de_rodadas);
        if((contador_de_rodadas == numero_de_rodadas) && (modo_de_jogo == 1)){
            printf("\n------Chegou ao numero maximo de rodadas------\n");
            printf("Pontuacao:\n");
            printf("%s: %d\n", tab.name, player1.qnt_pontos);
            printf("PC: %d\n", pc_info_t.qnt_pontos);
            if(player1.qnt_pontos > pc_info_t.qnt_pontos) printf("Parabens %s!!! Voce ganhou.\n", tab.name);
            else if(player1.qnt_pontos < pc_info_t.qnt_pontos) printf("Que vergonha %s... Voce perdeu para o PC.\n", tab.name);
            else printf("Empate!!!\n");
        }
    } else{
        do{
            printf("------Rodada %d------\n", contador_de_rodadas+1);

            printf("Vez do(a) %s atirar!\n", tab.name);
            jogar_player(&tab_player_2, &tab_player_2_escondido, &player1);
            if(verifica_se_tabuleiro_ainda_possui_armas(tab_player_2_escondido) == 0){
                printf("Parabens %s! Voce destruiu todas armas do(a) %s e GANHOU!\n", tab_escondido.name, tab_player_2_escondido.name);
            } else{
                printf("Vez do(a) %s atirar!\n", tab_player_2_escondido.name);
                jogar_player(&tab, &tab_escondido, &player2);
                if(verifica_se_tabuleiro_ainda_possui_armas(tab_escondido) == 0){
                    printf("Parabens %s! Voce destruiu todas armas do(a) %s e GANHOU!\n", tab_player_2_escondido.name, tab_escondido.name);
                }
            }
            contador_de_rodadas++;
            printf("\n\n");
        } while(verifica_se_tabuleiro_ainda_possui_armas(tab_escondido) == 1 && verifica_se_tabuleiro_ainda_possui_armas(tab_player_2_escondido) == 1 && contador_de_rodadas < numero_de_rodadas);
        if((contador_de_rodadas == numero_de_rodadas) && (modo_de_jogo == 1)){
            printf("\n------Chegou ao numero maximo de rodadas------\n");
            printf("Pontuacao:\n");
            printf("%s: %d\n", tab.name, player1.qnt_pontos);
            printf("%s: %d\n", tab_player_2.name, player2.qnt_pontos);
            if(player1.qnt_pontos > player2.qnt_pontos) printf("Parabens %s!!! Voce ganhou.\n", tab.name);
            else if(player1.qnt_pontos < player2.qnt_pontos) printf("Parabens %s!!! Voce ganhou.\n", tab_player_2.name);
            else printf("Empate!!!\n");
        }
    }

    printf("\nFim de jogo.\n");

    return 0;
}
