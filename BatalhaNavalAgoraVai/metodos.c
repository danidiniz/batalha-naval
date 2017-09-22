#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"estrutura.h"
#include"metodos.h"

void inicializa_arma_de_guerra(armaDeGuerra *arma, char x, int y, orientacao ori)
{
    (*arma).config.i = x - 'A';
    (*arma).config.j = y;
//    printf("%s | Arma config: %d %d\n", arma.name, arma.config.i, arma.config.j);

    (*arma).pares[0].i = 0;
    (*arma).pares[0].j = 0;

    if(strcmp((*arma).name, "Submarino") == 0)
    {
        (*arma).pares[1].i = 0;
        (*arma).pares[1].j = 0;
        (*arma).pares[2].i = 0;
        (*arma).pares[2].j = 0;
        (*arma).pares[3].i = 0;
        (*arma).pares[3].j = 0;
        (*arma).pares[4].i = 0;
        (*arma).pares[4].j = 0;
    }
    else if(strcmp((*arma).name, "Hidroaviao") == 0)
    {
        if(ori == OESTE){
            (*arma).pares[1].i = -1;
            (*arma).pares[1].j = 1;
            (*arma).pares[2].i = 1;
            (*arma).pares[2].j = 1;
        } else if(ori == NORTE){
            (*arma).pares[1].i = -1;
            (*arma).pares[1].j = -1;
            (*arma).pares[2].i = -1;
            (*arma).pares[2].j = 1;
        } else if(ori == SUL){
            (*arma).pares[1].i = 1;
            (*arma).pares[1].j = -1;
            (*arma).pares[2].i = 1;
            (*arma).pares[2].j = 1;
        } else if(ori == LESTE){
            (*arma).pares[1].i = -1;
            (*arma).pares[1].j = -1;
            (*arma).pares[2].i = 1;
            (*arma).pares[2].j = -1;
        }
        /* Seto o resto da posições com 0 */
        (*arma).pares[3].i = 0;
        (*arma).pares[3].j = 0;
        (*arma).pares[4].i = 0;
        (*arma).pares[4].j = 0;
    }
    else if(strcmp((*arma).name, "Cruzador") == 0)
    {
        if(ori == OESTE){
            (*arma).pares[1].i = 0;
            (*arma).pares[1].j = 1;
        } else if(ori == NORTE){
            (*arma).pares[1].i = -1;
            (*arma).pares[1].j = 0;
        } else if(ori == SUL){
            (*arma).pares[1].i = 1;
            (*arma).pares[1].j = 0;
        } else if(ori == LESTE){
            (*arma).pares[1].i = 0;
            (*arma).pares[1].j = -1;
        }
        /* Seto o resto da posições com 0 */
        (*arma).pares[2].i = 0;
        (*arma).pares[2].j = 0;
        (*arma).pares[3].i = 0;
        (*arma).pares[3].j = 0;
        (*arma).pares[4].i = 0;
        (*arma).pares[4].j = 0;
    }
    else if(strcmp((*arma).name, "Encouracado") == 0)
    {
        if(ori == OESTE){
            (*arma).pares[1].i = 0;
            (*arma).pares[1].j = 1;
            (*arma).pares[2].i = 0;
            (*arma).pares[2].j = 2;
            (*arma).pares[3].i = 0;
            (*arma).pares[3].j = 3;
        } else if(ori == NORTE){
            (*arma).pares[1].i = -1;
            (*arma).pares[1].j = 0;
            (*arma).pares[2].i = -2;
            (*arma).pares[2].j = 0;
            (*arma).pares[3].i = -3;
            (*arma).pares[3].j = 0;
        } else if(ori == SUL){
            (*arma).pares[1].i = 1;
            (*arma).pares[1].j = 0;
            (*arma).pares[2].i = 2;
            (*arma).pares[2].j = 0;
            (*arma).pares[3].i = 3;
            (*arma).pares[3].j = 0;
        } else if(ori == LESTE){
            (*arma).pares[1].i = 0;
            (*arma).pares[1].j = -1;
            (*arma).pares[2].i = 0;
            (*arma).pares[2].j = -2;
            (*arma).pares[3].i = 0;
            (*arma).pares[3].j = -3;
        }
        /* Seto o resto da posições com 0 */
        (*arma).pares[4].i = 0;
        (*arma).pares[4].j = 0;
    }
    else if(strcmp((*arma).name, "Porta-avioes") == 0)
    {
        if(ori == OESTE){
            (*arma).pares[1].i = 0;
            (*arma).pares[1].j = 1;
            (*arma).pares[2].i = 0;
            (*arma).pares[2].j = 2;
            (*arma).pares[3].i = 0;
            (*arma).pares[3].j = 3;
            (*arma).pares[4].i = 0;
            (*arma).pares[4].j = 4;
        } else if(ori == NORTE){
            (*arma).pares[0].i = 0;
            (*arma).pares[0].j = 0;
            (*arma).pares[1].i = -1;
            (*arma).pares[1].j = 0;
            (*arma).pares[2].i = -2;
            (*arma).pares[2].j = 0;
            (*arma).pares[3].i = -3;
            (*arma).pares[3].j = 0;
            (*arma).pares[4].i = -4;
            (*arma).pares[4].j = 0;
        } else if(ori == SUL){
            (*arma).pares[0].i = 0;
            (*arma).pares[0].j = 0;
            (*arma).pares[1].i = 1;
            (*arma).pares[1].j = 0;
            (*arma).pares[2].i = 2;
            (*arma).pares[2].j = 0;
            (*arma).pares[3].i = 3;
            (*arma).pares[3].j = 0;
            (*arma).pares[4].i = 4;
            (*arma).pares[4].j = 0;
        } else if(ori == LESTE){
            (*arma).pares[0].i = 0;
            (*arma).pares[0].j = 0;
            (*arma).pares[1].i = 0;
            (*arma).pares[1].j = -1;
            (*arma).pares[2].i = 0;
            (*arma).pares[2].j = -2;
            (*arma).pares[3].i = 0;
            (*arma).pares[3].j = -3;
            (*arma).pares[4].i = 0;
            (*arma).pares[4].j = -4;
        }
    }
}

int posicaoValida(tabuleiro tabu, armaDeGuerra arma){
            int k;
            /* Checando se todas posicções estão vazias */
            for(k = 0; k < 5; k++){
                /* Checando se não está fora do tabuleiro */
                if(((arma.config.i + arma.pares[k].i) < 0) || ((arma.config.i + arma.pares[k].i) >= 15) ||
                  (( arma.config.j + arma.pares[k].j) < 0) || ((arma.config.j + arma.pares[k].j) >= 15)   ){
                    return -1;
                }
                /* Se nao estiver vazio */
                if(tabu.cel[arma.config.i + arma.pares[k].i][arma.config.j + arma.pares[k].j].vazia == 1){
                    return 1;
                }
                if(verifica_vizinhanca(tabu, arma.config.i + arma.pares[k].i, arma.config.j + arma.pares[k].j) == 1){
                    return 2;
                }
            }
            return 0;
}

int atingiu(tabuleiro tabu, char linha, int coluna){
    int i = linha - 'A';
    if( ((coluna >= 0) && (coluna < 15)) && ((i >= 0) && (i < 15)) ){
        if(tabu.cel[i][coluna].vazia == 1){
            return 1; /* Atingiu */
        } else if((tabu.cel[i][coluna].vazia == 5) || (tabu.cel[i][coluna].vazia == 9)){
            return 2; /* Ja jogou nesta posicao */
        } else {
            return 0; /* Posicao vazia */
        }
    } else{
        return -1; /* Posicao invalida */
    }
}

void imprimirTabuleiro(tabuleiro tabu){
    int i,j;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(tabu.cel[i][j].vazia == 1){
                printf("1 ");
            } else if(tabu.cel[i][j].vazia == 0){
                printf("0 ");
            } else {
                printf("%d ", tabu.cel[i][j].vazia);
            }
        }
        printf("\n");
    }
}

tabuleiro atualizar_tabuleiro(tabuleiro *taboleiro, char linha, int coluna, int valor){
    int i = linha - 'A';
    (*taboleiro).cel[i][coluna].vazia = valor;
}

int verifica_se_tabuleiro_ainda_possui_armas(tabuleiro tabu){
    int i,j;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(tabu.cel[i][j].vazia == 1){
                return 1;
            }
        }
    }
    return 0;
}

int verifica_se_arma_existe(char *nome_da_arma){
    if(strcmp(nome_da_arma, "Submarino") == 0){
        return 0;
    } else if(strcmp(nome_da_arma, "Hidroaviao") == 0){
        return 0;
    } else if(strcmp(nome_da_arma, "Cruzador") == 0){
        return 0;
    } else if(strcmp(nome_da_arma, "Encouracado") == 0){
        return 0;
    } else if(strcmp(nome_da_arma, "Porta-avioes") == 0){
        return 0;
    }
    return 1;
}

int verifica_quantidade_da_arma(char *nome_da_arma){
    if(strcmp(nome_da_arma, "Submarino") == 0){
        return qntSubmarino;
    } else if(strcmp(nome_da_arma, "Hidroaviao") == 0){
        return qntHidroAviao;
    } else if(strcmp(nome_da_arma, "Cruzador") == 0){
        return qntCruzador;
    } else if(strcmp(nome_da_arma, "Encouracado") == 0){
        return qntEncouracado;
    } else if(strcmp(nome_da_arma, "Porta-avioes") == 0){
        return qntPortaAvioes;
    }
    return -1;
}

orientacao retorna_orientacao(char *ori){
    if(strcmp(ori, "NORTE") == 0){
        return NORTE;
    } else if(strcmp(ori, "SUL") == 0){
        return SUL;
    } else if(strcmp(ori, "LESTE") == 0){
        return LESTE;
    } else if(strcmp(ori, "OESTE") == 0){
        return OESTE;
    } else {
        return INVALIDO;
    }
}

void diminuiQuantidadeDeArma(char *nome_da_arma){
    if(strcmp(nome_da_arma, "Submarino") == 0){
        qntSubmarino--;
    } else if(strcmp(nome_da_arma, "Hidroaviao") == 0){
        qntHidroAviao--;
    } else if(strcmp(nome_da_arma, "Cruzador") == 0){
        qntCruzador--;
    } else if(strcmp(nome_da_arma, "Encouracado") == 0){
        qntEncouracado--;
    } else if(strcmp(nome_da_arma, "Porta-avioes") == 0){
        qntPortaAvioes--;
    }
}

void reseta_quantidade_de_arma(){
    qntSubmarino = 4; qntHidroAviao = 3; qntCruzador = 3; qntEncouracado = 2; qntPortaAvioes = 1;
}

int verifica_se_esta_dentro_do_tabuleiro(char c, int numero){
    int i = c - 'A';
    int j = numero;
    if( (i < 0) || (i > 14) || (j < 0) || (j > 14)){
        return 1;
    } else{
        return 0;
    }
}

void colocaArmaNoTabuleiro(tabuleiro *tabu, armaDeGuerra arma){
    if(posicaoValida(*tabu, arma) == 0){
        (*tabu).cel[arma.config.i][arma.config.j].vazia = 1;
        /* Como nao inicei todas posicoes do struct pares das armas,
            preciso parar na hora em que o par for [0,0] */
            int k;
            for(k = 1; k < 5; k++){
                if((arma.pares[k].i != 0) || (arma.pares[k].j != 0)){
                    (*tabu).cel[(arma.config.i + arma.pares[k].i)][(arma.config.j + arma.pares[k].j)].vazia = 1;
            }
        }
    } else { printf("Posicao de configuracao invalida!\n"); }
}

void transformar_linear_em_dimensional(int *i, int *j, int valor_linear){
    int a = 0,b = 0,contador = 0;
    for(a = 0; a < m; a++){
        for(b = 0; b < n; b++){
            *i = a;
            *j = b;
            if(contador == valor_linear){
                return;
            }
            contador++;
        }
    }
}

int verifica_vizinhanca(tabuleiro tabu, int linha, int coluna){
    //printf("\nVerificando vizinhanca para [%d][%d]\n", linha, coluna);
    int i, j;
    for(i = linha-1; i <= linha+1; i++){
        for(j = coluna-1; j <= coluna+1; j++){
            if((i != linha) || (j != coluna)){
                //printf("Valor de i j: %d,%d | valor dentro: %d\n", i, j, tabu.cel[i][j].vazia);
                if(tabu.cel[i][j].vazia == 1){
                    //printf("Verificando vizinhanca para [%d][%d]\n", linha, coluna);
                    //printf("Valor de i j: %d,%d | valor dentro: %d\n", i, j, tabu.cel[i][j].vazia);
                    return 1;
                }
            }
        }
    }
    return 0;
}
