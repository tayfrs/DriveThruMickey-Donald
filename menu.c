#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#define MAXLETRAS 10

typedef struct {
    char nome[MAXLETRAS];
    float preco[1];
}Dados;

Dados lista[3] ={

        {{"Hamburgue"}, {10.0} },
        {{"x-Salada"},   {9.0} },
        {{"x-Bacon"   }, { 8.5} }
};
/*Função do cardápio*/
void cardapio(void) {

    printf("\t\t\tCARDÁPIO\n\n\n");
    int i,j;
    printf("\t\t%*s %8s\n", -MAXLETRAS, "   Produtos", "    Preço\n");
    for (i=0;i<3;i++) {
        printf("\t\t  %*s", -MAXLETRAS, lista[i].nome);
            for (j=0;j<1;j++) {
                printf("%8.1f", lista[i].preco[j]);
            }
        printf("\n");
   }
}
int main (){
    setlocale(LC_ALL, "Portuguese");
    char resposta;
    system ("cls");
    inicio:
        printf("\n\t*********************************************\n");
        printf("\t   Bem vindo ao Drive Thru Michey e Donald");
        printf("\n\t*********************************************\n\n");
        printf("\n\tDigite S para visualizar o nosso cardápio:\n");
    fflush(stdin);
    scanf("%c", &resposta);
    system ("cls");
        if(resposta == 'S' || resposta == 's'){
            cardapio();
        } else {
            system ("cls");
            printf("Resposta inválida. Tente novamente!\n\n\n"); //Ajustar aqui ainda

            goto inicio;
        }

    getchar();
    return 0;
}
