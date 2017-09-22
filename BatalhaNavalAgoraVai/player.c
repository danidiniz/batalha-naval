#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"estrutura.h"
#include"player.h"
#include"computer.h"
#include"metodos.h"

void setar_tabuleiro_player(tabuleiro *tab){
    while((qntSubmarino + qntHidroAviao + qntCruzador + qntEncouracado + qntPortaAvioes) > 12){
        printf("%s, voce pode colocar no seu tabuleiro:\n", (*tab).name);
        printf("Nome da arma: Submarino    | Quantidade: %d\n", qntSubmarino);
        printf("Nome da arma: Hidroaviao   | Quantidade: %d\n", qntHidroAviao);
        printf("Nome da arma: Cruzador     | Quantidade: %d\n", qntCruzador);
        printf("Nome da arma: Encouracado  | Quantidade: %d\n", qntEncouracado);
        printf("Nome da arma: Porta-avioes | Quantidade: %d\n\n", qntPortaAvioes);
        char arma_name[15];
        do{
            printf("Digite o nome de uma arma que deseja colocar no tabuleiro: ");
            scanf("%s", &arma_name);
            if(verifica_se_arma_existe(arma_name) == 1){
                printf("Arma nao encontrada. Digite novamente.\n");
            }
        } while (verifica_se_arma_existe(arma_name) == 1);

        printf("\n");

        if(verifica_quantidade_da_arma(arma_name) > 0){
            orientacao ori;
            do{
                if(strcmp(arma_name, "Submarino") == 0){
                    ori = OESTE;
                } else{
                    char orie[10];
                    printf("Orientacao da arma (NORTE, SUL, LESTE OU OESTE): ");
                    scanf("%s", &orie);
                    ori = retorna_orientacao(orie);
                    if(ori == INVALIDO) printf("Orientacao invalida. Digite novamente.\n");
                    else printf("\n");
                }
            } while (ori == INVALIDO);

            armaDeGuerra nova_arma;
            int pos_valida = 0;
            do{
                printf("Posicao da arma\n");
                char c;
                printf("Letra (linha): ");
                getchar();
                scanf("%c", &c);
                int numero;
                printf("Numero (coluna): ");
                scanf("%d", &numero);
                nova_arma.name = arma_name;
                inicializa_arma_de_guerra(&nova_arma, c, numero, ori);
                pos_valida = posicaoValida(*tab, nova_arma);
                if(pos_valida == 2){
                    printf("Ha uma arma na vizinhanca. Tente outra posicao.\n\n");
                } else if(pos_valida == 1){
                    printf("Posicao ja possui uma arma. Digite novamente.\n\n");
                } else if(pos_valida == -1){
                    printf("Posicao invalida. Digite novamente.\n\n");
                }
            } while (pos_valida != 0);
            colocaArmaNoTabuleiro(tab, nova_arma);

            printf("\n");
            diminuiQuantidadeDeArma(nova_arma.name);
            printf("Colocou o %s no tabuleiro.\n", nova_arma.name);

            printf("Tabuleiro do(a) %s:\n", (*tab).name);
            imprimirTabuleiro(*tab);
            printf("\n");
        } else{
            printf("Voce ja colocou o numero maximo de %s\n\n", arma_name);
        }
    }
}


void jogar_player(tabuleiro *tabuleiro_visivel, tabuleiro *tabuleiro_escondido, player_info *player){
    printf("Escolha uma posicao que deseja atirar no tabuleiro do(a) %s\n", (*tabuleiro_visivel).name);
    imprimirTabuleiro(*tabuleiro_visivel);
    char c;
    int numero;
    do{
        printf("Letra (linha): ");
        getchar();
        scanf("%c", &c);
        printf("Numero (coluna): ");
        scanf("%d", &numero);
        if(verifica_se_esta_dentro_do_tabuleiro(c, numero) == 1){
            printf("Posicao invalida. Digite novamente.\n");
        } else if(atingiu(*tabuleiro_escondido, c, numero) == 2){
            printf("Voce ja jogou nesta posicao. Escolha outra.\n");
        }
    } while((verifica_se_esta_dentro_do_tabuleiro(c, numero) == 1) || (atingiu(*tabuleiro_escondido, c, numero) == 2));

    if(atingiu(*tabuleiro_escondido, c, numero) == 1){
        printf("Voce atingiu o inimigo!!!\n");
        atualizar_tabuleiro(tabuleiro_visivel, c, numero, 5);
        atualizar_tabuleiro(tabuleiro_escondido, c, numero, 5);
        (*player).qnt_pontos++;
    } else {
        printf("Voce nao acertou.\n");
        atualizar_tabuleiro(tabuleiro_visivel, c, numero, 9);
        atualizar_tabuleiro(tabuleiro_escondido, c, numero, 9);
    }
    printf("\n");
}
