#include <stdio.h>
#define SIZE 10 // usando define para evitar repetir o numero 10
#define ship_size 3 // definindo o tamanho do navio

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

    int x_nv1 = 7 , y_nv1 = 3;  //posição inicial do navio 1 (horizontal)
    int x_nv2 = 7 , y_nv2 = 7; //posição inicial do navio 2 (vertical)
    int x_nv3 = 0 , y_nv3 = 0; //posição inicial do navio 3 (diagonal principal)
    int x_nv4 = 0, y_nv4 = 9; //posição inicial do navio 4 (diagonal secundária)
    
    for(int i = 0; i < ship_size; i++) //vamos posicionar e marcar o navio horizontal
    {
        matriz_tabuleiro[x_nv1] [ y_nv1 + i] = 3;
    }

    for(int i = 0; i < ship_size; i++)
    {
        matriz_tabuleiro[x_nv2 + i][y_nv2] = 3;
    }

    for(int i = 0; i < ship_size; i++)
    {
        matriz_tabuleiro [x_nv3 + i][y_nv3 + i] = 3; //somando em ambos os índices, garante que seja na diagonal
    }
    
    for(int i = 0; i < ship_size; i++)
    {
        matriz_tabuleiro[x_nv4 + i] [y_nv4 - i] = 3; //diminuindo em ambos os índices, garante que seja na diagonal secundária
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
