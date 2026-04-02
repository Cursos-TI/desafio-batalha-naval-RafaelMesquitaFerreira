#include <stdio.h>
#define SIZE 10 // usando define para evitar repetir o numero 10
#define linha_grande 5 //define o tamanho da linha grande
#define linha_pequena 3 //define o tamanho da linha pequena
 

int matriz_tabuleiro [10][10]; //definindo a matriz do tamanho do tabuleiro

void posicionamento() //função para o posicionamento
{

    for(int i = 0; i < SIZE; i++) //loop para formar todas as linhas do tabuleiro
    {
      for(int j = 0; j < SIZE; j++)//loop para formar todas as colunas do tabuleiro
      {
        matriz_tabuleiro[i][j] = 0; //preenchendo com "água"
      }
    }

    //coordenadas da cruz
    int x1_cruz = 2, y1_cruz = 0; //posição inicial da linha horizontal da cruz
    int x2_cruz = 0, y2_cruz = 2; //posição inicial da linha vertical da cruz

    //coordenadas do cone
    int x1_cone = 2, y1_cone = 7; //posição inicial da linha vertical do cone
    int x2_cone = 4, y2_cone = 5; //posição inicial da linha horizontal do cone
    int x3_cone = 4, y3_cone = 5; //posição inicial da diagonal esquerda do cone
    int x4_cone = 4, y4_cone = 9; //posição inicial da diagonal direita do cone

    //coordenadas do octaedro
    int x1_octa = 7, y1_octa = 1; //posição inicial da linha horizontal do octaedro
    int x2_octa = 5, y2_octa = 3; //posição inicial da linha vertical do octaedro
    int x3_octa = 7, y3_octa = 1; //posição inicial da diagonal superior esquerda do octaedro
    int x4_octa = 7, y4_octa = 5; //posição inicial da diagonal superior direita do octaedro
    int x5_octa = 7, y5_octa = 1; //posição inicial da diagonal inferior esquerda do octaedro
    int x6_octa = 7, y6_octa = 5; //posição inicial da diagonal inferior direita do octaedro


    //posicionar a cruz
    for(int i = 0; i < linha_grande; i++) //vamos posicionar e marcar a cruz
    {
        matriz_tabuleiro[x1_cruz] [ y1_cruz + i] = 3;
        matriz_tabuleiro[x2_cruz + i] [y2_cruz] = 3;
    }
    
    //posicionar a linha horizontal do cone
    for(int i = 0; i < linha_grande; i++)
    {
        matriz_tabuleiro[x2_cone ][y2_cone + i] = 1;
    }

    //posicionar as diagonais do cone e a linha vertical
    for(int i = 0; i < linha_pequena; i++)
    {
        matriz_tabuleiro[x3_cone - i][y3_cone + i] = 1;
        matriz_tabuleiro[x4_cone - i][y4_cone - i] = 1;
        matriz_tabuleiro[x1_cone + i][y1_cone] = 1;
    } 

    //posicionar as diagonais do octaedro
    for(int i = 0; i < linha_pequena; i++)
    {
        matriz_tabuleiro[x3_octa - i][y3_octa + i] = 4;
        matriz_tabuleiro[x4_octa - i][y4_octa - i] = 4;
        matriz_tabuleiro[x5_octa + i][y5_octa + i] = 4;
        matriz_tabuleiro[x6_octa + i][y6_octa - i] = 4;
    } 

    //posicionar as linhas vertical e horizontal
    for(int i = 0; i < linha_grande; i++)
    {
        matriz_tabuleiro[x1_octa][y1_octa + i] = 4;
        matriz_tabuleiro[x2_octa + i][y2_octa] = 4;
    }

}

void apresentar()

{
    printf("_-_A B C D E F G H I J\n");
    for(int i = 0; i < SIZE; i++)
    {
        
        switch (i)
        {
        case 0:
            printf("%d_-",i + 1);
            break;

        case 1:
            printf("%d_-",i + 1);
            break;

        case 2:
            printf("%d_-",i + 1);
            break;
        case 3:
            printf("%d_-",i + 1);
            break;
        case 4:
            printf("%d_-",i + 1);
            break; 
        
        case 5:
            printf("%d_-",i + 1);
            break;

        case 6:
            printf("%d_-",i + 1);
            break;

        case 7:
            printf("%d_-",i + 1);
            break;

        case 8:
            printf("%d_-",i + 1);
            break;
        
        default:
            printf("%d-",i + 1);
            break;
        }
        for(int j = 0; j < SIZE; j++)
        {
            printf("%d ", matriz_tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    posicionamento();
    apresentar();

}
