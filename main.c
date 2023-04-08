#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    int n2,t = 0;
    int sequencia2[100];
    int matrizRI[2][99];
    int matrizR[2][99];
    int p,op;
    int div,matrizS[2][50];
    int k = 0;
    int determinante,matriz[2][2];
    int inversa [2][2];
    int i,j,n;
    char letra;
    char Frase[100];
    int sequencia[100];
    char tabela2[] = {'A', ' ', 'B', ' ', 'C', ' ', 'D', ' ', 'E', ' ',
                      'F', ' ', 'G', ' ', 'H', ' ', 'I', ' ', 'J', ' ',
                      'K', ' ', 'L', ' ', 'M', ' ', 'N', ' ', 'O', ' ',
                      'P', ' ', 'Q', ' ', 'R', ' ', 'S', ' ', 'T', ' ',
                      'U', ' ', 'V', ' ', 'W', ' ', 'X', ' ', 'Y', ' ',
                      'Z', ' ', '.', ' ', ',', ' ', '#', ' '
                     };

    srand(time(NULL));

    printf("1. Gerar A e sua inversa\n2. Ler mensagem e codificar\n3. Imprimir mensagem codificada\n4. Decodificar e imprimir mensagem decodificada\n");

    /* //Começo da leitura da frase e transformar ela em Uma sequencia de numeros
     printf("\n");
     printf("Digite uma frase Para ser codificada e decodificada: ");
     //scanf("%s%*c",Frase); // ler uma linha de texto do usuário
     fgets(Frase, 100, stdin); // ler uma linha de texto do usuário*/

    do
    {

        printf("\n");
        printf("Escolha a opcao desejada:\n");
        scanf("%d%*c",&op);

        switch(op)
        {

        case 1:
            //Começo da criaçao da matriz
            // verificando se o det da matriz eh diferente de 0
            do
            {
                // preenche a matriz com números aleatórios
                for (int i = 0; i < 2; i++)
                {
                    for (int j = 0; j < 2; j++)
                    {
                        matriz[i][j] = rand () % 10;
                    }
                }

                determinante = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];

            }
            while ( determinante != 1 && determinante != -1);

            // calcula a matriz adjunta
            inversa[0][0] = matriz[1][1]/determinante;
            inversa[0][1] = -matriz[0][1]/determinante;
            inversa[1][0] = -matriz[1][0]/determinante;
            inversa[1][1] = matriz[0][0]/determinante;


            // exibe a matriz
            printf("\nMatriz:\n");
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    printf("%d ", matriz[i][j]);
                }
                printf("\n");
            }

            // exibe a matriz inversa
            printf("\nMatriz inversa:\n");
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    printf("%d ", inversa[i][j]);
                }
                printf("\n");
            }
            printf("\n");
//Fim da criaçao da matriz
            break;

        case 2:

            //Começo da leitura da frase e transformar ela em Uma sequencia de numeros

            printf("Digite uma frase a ser codificada: ");
            //scanf("%s%*c",Frase); // ler uma linha de texto do usuário
            fgets(Frase, 100, stdin); // ler uma linha de texto do usuário

            n = strlen(Frase)-1;
            for (i = 0; i < n; i++)
            {
                if (Frase[i] == ' ')
                {
                    printf(" "); // imprime um espaço em branco para separar as palavras
                    sequencia[i] = 29; // armazena 29 para espaços em branco
                }
                else
                {
                    letra = Frase[i];
                    for (j = 0; j < 29; j++)
                    {
                        if (toupper(letra) == 'A' + j)   // converte letra maiúscula para número (de 01 a 10)
                        {
                            sequencia[i] = j+1;
                            break;
                        }
                        else if (toupper(letra) == 'K' + j - 10)  // converte letra maiúscula para número (de 11 a 20)
                        {
                            sequencia[i] = j+11;
                            break;
                        }
                        else if (toupper(letra) == 'U' + j - 20)  // converte letra maiúscula para número (de 21 a 29)
                        {
                            sequencia[i] = j+21;
                            break;
                        }
                        else if (Frase[i] == '.')
                        {
                            sequencia[i] = 27; // converte ponto para número 27
                            break;
                        }
                        else if (Frase[i] == ',')
                        {
                            sequencia[i] = 28; // converte vírgula para número 28
                            break;
                        }
                        else if (Frase[i] == '#')
                        {
                            sequencia[i] = 29; // converte cerquilha para número 29
                            break;
                        }
                    }
                }
            }
            printf("\n");
            printf("Sua mensagem foi codificada!:\n");

//Fim da leitura da frase e transformar ela em Uma sequencia de numeros

            break;

        case 3:
//Começo imprimir mensagem codificada
            printf("\n");
            printf("Sua mensagem codificada eh:\n");
            // Imprime a sequência de números armazenada no vetor
            for (i = 0; i < n; i++)
            {
                printf(" %d", sequencia[i]);
            }
            printf("\n");

            /* // checando se os numeros viraram realmente numero
             int result = sequencia[5] * 3;
             printf("%d", result);*/

            //Transformar a sequencia de numeros em uma matriz

            int div,matrizS[2][50];
            int k = 0;

            if ( n % 2 == 0)
            {
                div = n / 2;
            }
            else
            {
                div = n / 2 + 1;
            }

            printf("\nA matriz da sequencia gerada eh:\n");
            for ( int i = 0; i < 2; i++)
            {
                for ( int j = 0; j < div; j++)
                {
                    if (sequencia[k] != 0)
                    {
                        matrizS[i][j] = sequencia[k];
                    }
                    else
                    {
                        matrizS[i][j] = 29;
                    }
                    printf(" %d", matrizS[i][j]);
                    k++;
                }
                printf("\n");
            }

            //Começo das operaçoes da matriz com a matriz sequencia

            int matrizR[2][99];
            int p;



            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < div; j++)
                {
                    matrizR[i][j] = 0;
                    for (p = 0; p < 2; p++)
                    {
                        matrizR[i][j] = matrizR[i][j] + matriz[i][p] * matrizS[p][j];
                    }
                }
            }

            printf("\n");
            printf("O Resultado da multiplicaçao da matriz gerada pela matriz sequencia eh:\n");
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < div; j++)
                {
                    printf(" %d", matrizR[i][j]);
                }
                printf("\n");
            }
//Fim das operaçoes da matriz com a matriz sequencia
            printf("\n");
//Começo das operaçoes da matriz inversa da matriz gerada com a matriz sequencia
            int matrizRI[2][99];

            for (i = 0; i < 2; i++)
            {
                for(j = 0; j < div; j++)
                {
                    matrizRI[i][j] = 0;
                    for (p = 0; p < 2; p++)
                    {
                        matrizRI[i][j] = matrizRI[i][j] + inversa[i][p] * matrizR[p][j];
                    }
                }
            }

            printf("O Resultado da multiplicaçao da matriz inversa gerada pela matriz sequencia eh:\n");
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < div; j++)
                {
                    printf(" %d", matrizRI[i][j]);
                }
                printf("\n");
            }
//Fim das operaçoes da matriz inversa da matriz gerada com a matriz sequencia
            break;

        case 4:

            printf("\n");
            n2 = n;
            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < div; j++)
                {
                    sequencia2[t] = matrizRI[i][j];
                    t++;
                }
            }

            printf("\nO numero a ser decodificado eh:\n");
            for (i = 0; i < n2; i++)
            {
                printf(" %d", sequencia2[i]);
            }
            printf("\n");

            printf("O seu numero decodificad0 eh:\n");
            for (int i = 0; i < n2; i++)
            {
                for (int j = 0; j < 58; j += 2)
                {
                    if (sequencia2[i] == j/2 + 1)
                    {
                        printf(" %c", tabela2[j]);
                        break;
                    }
                }
            }

            break;

        default:

            printf("Opcao invalida!");

            break;

        }

    }
    while ( op <= 4);

    return 0;
}
