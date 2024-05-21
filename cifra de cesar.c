/*  O código se refere a criptografia Cifra de César, na qual tem que digitar uma mensagem
    e ela será criptografada de acordo com as rotações que o usuário ira escolher, e por fim,
    tem a opção da mensagem ser descriptografada, utilizando as mesmas rotações que o usuário
    digitou para criptografar  */

#include <stdio.h>
#include <string.h>

int main()
{

    int opcao, i, rot = 27;
    char msg [100];

    while(1)
    {
        do
        {

            printf("--------------------------------------\n");
            printf ("\ALGORITMO CIFRA DE CESAR \n");
            printf ("\n1- Criptografar\n");
            printf ("2- Descriptografar\n");
            printf ("3- Sair \n");
            printf ("\nEscolha o que voce deseja fazer: ");

            scanf("%d", &opcao);

        }
        while (opcao != 1 && opcao != 2 && opcao != 3); /* estrutura de validação de dados */

        if (opcao == 3)
        {
            printf("\nOBRIGADO POR USAR ESSE PROGRAMA!\n");
            return 0; /* caso a opção escolhida tenha sido o numero 3, o programa será encerrado */
        }

        printf("\nDigite uma mensagem: "); /* entrar com a mensagem Criptografada ou Descriptografada */
        fflush(stdin);
        scanf ("%[^\n]", msg);
        system("cls");


        do
        {

            printf("Digite o numero de rotacoes: "); /* numero de rotacoes para a criptografia funcionar */
            fflush(stdin);
            scanf ("%d", &rot);

        }
        while (rot < 0 || rot > 26); /* estrutura de validação de dados */

        switch (opcao)
        {

        case 1: /* CRIPTOGRAFAR MENSAGEM */
            for (i=0; i<= strlen(msg); i++) /* estrutura de repetição(for) para ler a string letra por letra com o comando strlen */
            {

                if(msg[i] >= 'a' && msg[i] <= 'z') /* verifica se na mensagem inclui letras minusculas */
                {

                    if(msg[i] + rot > 'z') /* verifica se a mensagem mais as rotações ira ultrapassar o final do alfabeto sendo assim a letra "z" */
                    {

                        msg[i] = msg[i] - 26 + rot; /* anda com o caracter para tras + rotacao, para nao ultaprassar o limite do caracter que seria Z  */

                    }
                    else
                    {
                        msg[i] = msg[i] + rot;
                    }
                }
                else if(msg[i] >= 'A' && msg[i] <= 'Z') /* verifica se na mensagem inclui letras maiusculas */
                {

                    if(msg[i] + rot > 'Z') /* verifica se a mensagem mais as rotações ira ultrapassar o final do alfabeto sendo assim a letra "Z" */
                    {

                        msg[i] = msg[i] - 26 + rot; /* anda com o caracter para tras + rotacao, para nao ultaprassar o limite do caracter que seria Z  */

                    }
                    else
                    {
                        msg[i] = msg[i] + rot; /* aqui ocorre a criptografia, somando o caracter + a rotacao */
                    }
                }
            }

            printf ("Mensagem criptografada: %s\n", msg); /* Exibe a mensagem criptografada */
            break;

        case 2: /* DESCRIPTOGRAFAR MENSAGEM */
            for (i=0; i<= strlen(msg); i++) /* estrutura de repetição(for) para ler a string letra por letra com o comando strlen */
            {

                if(msg[i] >= 'a' && msg[i] <= 'z') /* verifica se na mensagem inclui letras minusculas */
                {

                    if(msg[i] - rot < 'a') /* verifica se a mensagem menos a rotação ira ultrapassar a letra "a" */
                    {

                        msg[i] = msg[i] + 26 - rot;  /* anda com o caracter para frente menos a rotacao, para nao ultaprassar o limite do caracter que seria A  */

                    }
                    else
                    {
                        msg[i] = msg[i] - rot;
                    }

                }
                else if(msg[i] >= 'A' && msg[i] <= 'Z') /* verifica se na mensagem inclui letras maiusculas */
                {

                    if(msg[i] - rot < 'A') /* verifica se a mensagem menos a rotação ira ultrapassar a letra "a" */
                    {

                        msg[i] = msg[i] + 26 - rot; /* anda com o caracter para frente menos a rotacao, para nao ultaprassar o limite do caracter que seria A*/

                    }
                    else
                    {

                        msg[i] = msg[i] - rot; /* aqui ocorre a descriptografia, subtraindo o caracter menos a rotacao */
                    }
                }
            }
            printf("Mensagem descriptografada: %s\n", msg); /* Exibe a mensagem descriptografada */
            break;

        }
    }
}
