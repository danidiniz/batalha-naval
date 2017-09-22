#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"estrutura.h"
#include"computer.h"
#include"metodos.h"

void inicializa_jogadas_info(jogadas_info *jog){
    (*jog).acertou_submarinos = 0;
    (*jog).acertou_hidro = 0;
    (*jog).acertou_cruzador = 0;
    (*jog).acertou_encouracado = 0;
    (*jog).acertou_portavioes = 0;

    int i;
    for(i = 0; i < m*n; i++){
        (*jog).jogadas_disponiveis[i] = i;
    }

    (*jog).tamanho = m*n;
}

void resetar_jogada_atual(jogada_atual *jog){
    (*jog).qnt_pecas_ja_acertou = 0;
    (*jog).acerto_inicial.i = -1;
    (*jog).acerto_inicial.j = -1;
    (*jog).tentativa_atual.i = -1;
    (*jog).tentativa_atual.j = -1;
    int i;
    for(i = 0; i < 5; i++){
        (*jog).pecas_que_acertou[i].i = -1;
        (*jog).pecas_que_acertou[i].j = -1;
    }
}



void jogar_pc(tabuleiro *tabuleiro_visivel, tabuleiro *tabuleiro_escondido, jogadas_info *jog_info, jogada_atual *jog_atual){
    if((*jog_atual).qnt_pecas_ja_acertou == 0){
        int i, j;
        int indice_linear_random = rand()%((*jog_info).tamanho);
        transformar_linear_em_dimensional(&i, &j, indice_linear_random);
        if(atingiu(*tabuleiro_escondido, i+'A', j) == 1){
            (*jog_atual).qnt_pecas_ja_acertou++;
            (*jog_atual).acerto_inicial.i = i;
            (*jog_atual).acerto_inicial.j = j;
            (*jog_atual).pecas_que_acertou[0].i = i;
            (*jog_atual).pecas_que_acertou[0].j = j;
        }
    }
}

void jogar_pc_burro(tabuleiro *tabuleiro_visivel, tabuleiro *tabuleiro_escondido, jogadas_info *jog_info, pc_info *pc){
    /* Apesar deu estar sorteando sem reposicao, fiz esse while como precaucao */
    int i, j;
    do{
        int indice_linear_random = rand()%((*jog_info).tamanho);
        transformar_linear_em_dimensional(&i, &j, indice_linear_random);
    } while(atingiu(*tabuleiro_visivel, i+'A', j) != 0);

    /* Remove e diminui tamanho em 1 para sortear sem reposicao */
    int aux = (*jog_info).jogadas_disponiveis[i*m + j];
    (*jog_info).jogadas_disponiveis[i*m + j] = (*jog_info).jogadas_disponiveis[(*jog_info).tamanho-1];
    (*jog_info).jogadas_disponiveis[(*jog_info).tamanho-1] = aux;
    (*jog_info).tamanho--;

    if(atingiu(*tabuleiro_escondido, i+'A', j) == 1){
        printf("O PC atirou na posicao [%c][%d] e atingiu uma de suas armas!!!\n", 'A'+i, j);
        atualizar_tabuleiro(tabuleiro_visivel, i+'A', j, 5);
        atualizar_tabuleiro(tabuleiro_escondido, i+'A', j, 5);
        (*pc).qnt_pontos++;
    } else {
        printf("O PC atirou na posicao [%c][%d] e nao acertou! Sorte sua...\n", 'A'+i, j);
        atualizar_tabuleiro(tabuleiro_visivel, i+'A', j, 9);
        atualizar_tabuleiro(tabuleiro_escondido, i+'A', j, 9);
    }
}

void setar_tabuleiro_pc(){
    /* Sorteando posicoes das armas do PC */
    pcTabEscondido = sortear_posicoes_das_armas_do_pc(pcTabEscondido);

    printf("\nTabuleiro do computador (o que eh mostrado para o player):\n");
    imprimirTabuleiro(pcTab);

    printf("\n");

    /* Deletar depois */
    printf("Tabuleiro escondido do PC (esse eh o tabuleiro que possui as posicoes das armas do PC e que nao sera mostrado pro player, obvio)\n");
    imprimirTabuleiro(pcTabEscondido);

    printf("\n\n");
}

tabuleiro colocar_arma_pc_no_tabuleiro(tabuleiro tabu, char *arma_name, int indices_array[], int *tamanho){
    armaDeGuerra nova_arma;

    int indice_linear_random;
    int i, j;
    int pos_valida = 0;
    do{
        //[i*m + j] [][] to []
        //i = rand()%m;
        //j = rand()%n;
        indice_linear_random = rand()%(*tamanho);

        //printf("Valor linear sorteado: %d\n", indice_linear_random);
        transformar_linear_em_dimensional(&i, &j, indice_linear_random);
        //printf("Valor bi dimensional: [%d][%d]\n", i, j);


        /* Para cada posicao sorteada, vou testar TODAS ORIENTACOES */
        int indices_orientacao[4] = {0,1,2,3};
        int tamanho_orientacao = 4;
        int indice_random_orientacao; /* Variavel que randomizar uma orientacao */
        do{
            indice_random_orientacao = rand()%tamanho_orientacao;
            orientacao ori = indices_orientacao[indice_random_orientacao];

//            printf("Linha %c (%d) | Coluna %d | Orientacao %d\n", 'A'+i, i, j, ori);

            nova_arma.name = arma_name;
            inicializa_arma_de_guerra(&nova_arma, 'A'+i, j, ori);

            pos_valida = posicaoValida(tabu, nova_arma);

            /*
            if(pos_valida == -1){
                printf("Posicao invalida. Tentando NOVA ORIENTACAO.\n");
            } else if(pos_valida == 1){
                printf("Posicao ja possui uma arma. Tentando NOVA ORIENTACAO.\n");
            } else if(pos_valida == 2){
                printf("Ha uma arma na vizinhanca. Tentando NOVA ORIENTACAO.\n");
            }
            if((pos_valida != 0) && tamanho_orientacao-1 == 0){
                printf("Nao foi possivel colocar %s no tabuleiro.\n", nova_arma.name);
                printf("Nenhuma orientacao serviu para essa posicao. Sorteando outra posicao.\n\n");
            }
            */

            /* Como a orientacao nao serviu, passo ela pro final do array e sorteio uma nova orientacao */
            int aux = indices_orientacao[indice_random_orientacao];
            indices_orientacao[indice_random_orientacao] = indices_orientacao[tamanho_orientacao-1];
            indices_orientacao[tamanho_orientacao-1] = aux;
            tamanho_orientacao--;
        } while ((pos_valida != 0) && tamanho_orientacao > 0);
    } while (pos_valida != 0);

    colocaArmaNoTabuleiro(&tabu, nova_arma);

    int aux = indices_array[i*m + j];
    indices_array[i*m + j] = indices_array[(*tamanho)-1];
    indices_array[(*tamanho)-1] = aux;
    (*tamanho)--;
    diminuiQuantidadeDeArma(nova_arma.name);

    /* Salva a arma no array de armas do pc */
    /*
    int k;
    for(k = 0; k < 13; k++){
        if(pc_info_t.armas_pc_no_tabuleiro[k]. == NULL){
            pc_info_t.armas_pc_no_tabuleiro[k] = nova_arma;
        }
    } */

    printf("Linha %c (%d) | Coluna %d | Orientacao %d\n", nova_arma.config.i+'A', nova_arma.config.i, nova_arma.config.j, nova_arma.ori);
    printf("Colocou o %s no tabuleiro do PC.\n\n", nova_arma.name);
    return tabu;
}

tabuleiro sortear_posicoes_das_armas_do_pc(tabuleiro pcTabEscondido){
    //printf("Sorteando posicoes das armas do PC\n");

    int tamanho = m*n;
    int indices_linear[tamanho];
    int k;
    // inicializando o array de indices
    for(k = 0; k < tamanho; k++) indices_linear[k] = k;

    while((qntSubmarino + qntHidroAviao + qntCruzador + qntEncouracado + qntPortaAvioes) > 0){
        if(qntSubmarino > 0){
            //printf("Arma: Submarino\n");
            pcTabEscondido = colocar_arma_pc_no_tabuleiro (pcTabEscondido, "Submarino", indices_linear, &tamanho);
        } else if(qntHidroAviao > 0){
            //printf("Arma: Hidroaviao\n");
            pcTabEscondido = colocar_arma_pc_no_tabuleiro(pcTabEscondido, "Hidroaviao", indices_linear, &tamanho);
        } else if(qntCruzador > 0){
           // printf("Arma: Cruzador\n");
            pcTabEscondido = colocar_arma_pc_no_tabuleiro(pcTabEscondido, "Cruzador", indices_linear, &tamanho);
        } else if(qntEncouracado > 0){
            //printf("Arma: Encouracado\n");
            pcTabEscondido = colocar_arma_pc_no_tabuleiro(pcTabEscondido, "Encouracado", indices_linear, &tamanho);
        } else if(qntPortaAvioes > 0){
            //printf("Arma: Porta-avioes\n");
            pcTabEscondido = colocar_arma_pc_no_tabuleiro(pcTabEscondido, "Porta-avioes", indices_linear, &tamanho);
        }
    }
    reseta_quantidade_de_arma();
    return pcTabEscondido;
}
