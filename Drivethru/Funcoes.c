/* Bibliotecas */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int Calcula_Qtd_Registro (int numero_registros);

/* Tipos de dados pr�-definidos */
typedef   struct
{   /* campos da estrutura */
    int    	Codprod;
    char   	Nomeprod[50];
    float	Custoprod;
}registro;

/* Vari�veis globais */
registro      reg; /* Vari�vel reg que � do tipo registro*/
FILE * Arq;
int   numero_registros;


/* ========Fu��o capturar produto========= */
void  captura_produto (void)
{
	system ("cls");
	/* gerar o c�digo autonum�rico */
	reg.Codprod = Calcula_Qtd_Registro(numero_registros) + 1;
	printf ("\nCodigo do produto: ");
	printf ("%i", reg.Codprod);

	printf ("\nDigite o nome do produto: ");
	fflush (stdin); 	gets(reg.Nomeprod); /* scanf  ("%s", &reg.Nomeprod); */
	printf ("\nDigite o valor do produto R$: ");
	fflush (stdin);     scanf  ("%f", &reg.Custoprod);
}

/* ========Fu��o gravar produto========= */
void gravar_produto (void)
{
    int result;
    FILE  *  A; /* A vari�vel 'A' se refere ao arquivo que vai ser manipuldo [PRODUTOS.DAT]*/
    A  =  fopen ("PRODUTOS.DAT" , "a"); /* Abre o arquivo para adicionar dados ["a"] */
    if ( A == NULL ) /* NULL ----> 00000000 00000000 */
    {
    	printf("ERRO AO ABRIR O ARQUIVO PRODUTOS.DAT!");
    	getch();
    	exit(0);
	}
	/* Grava o registro em PRODUTOS.DAT */
	result = fwrite ( &reg,  sizeof(reg), 1, A);
	printf("Elementos gravados: %d", result);
	/* Fecha o arquivo */
	fclose (A);
}

/* ========Fu��o calcular qtd registros========= */
int Calcula_Qtd_Registro (int numero_registros)
{
	Arq = fopen ("PRODUTOS.DAT", "r");
	if ( Arq == NULL) /* O arquivo n�o existe */
	   numero_registros = 0;
	else
	{   /* Calcula o tamanho do arquivo */
		if ( fseek (Arq, 0, SEEK_END) ) /* Aqui fseek tenta se posicionar no final do arquivo...*/
		{
           printf("\nERRO ao calcular o tamanho de arquivo!\n");
           getch();
           numero_registros = -1;
        }
        else
		{   /*...para que ftell 'conte' quantos bytes o arquivo tem */
		    /* Dividindo-se o total de bytes do arquivo pelo tamanho de cada registro */
		    /* tem-se o n�mero de registros do arquivo. */
		    numero_registros =  ftell(Arq) / sizeof (registro);
  	    }
  	    /* Fecha o arquivo */
  	    fclose (Arq);
	}
    /* Para teste: avisa quantos bytes o arquivo tem */
    /* printf ("\nO arquivo PRODUTOS.DAT tem [%i] registros.", numero_registros);*/

    /* 'devolve' a quantidade de registros para o programa 'chamador'*/
	return (numero_registros);
}

void ler_produto (void)
{
    FILE  *  A; /* A vari�vel 'A' se refere ao arquivo que vai ser manipuldo [PRODUTOS.DAT]*/
    A  =  fopen ("PRODUTOS.DAT" , "r"); /* Abre o arquivo para ler dados ["r"] */
    if ( A == NULL ) /* NULL ----> 00000000 00000000 */
    {
    	printf("ERRO AO ABRIR O ARQUIVO PRODUTOS.DAT!");
    	getch();
    	exit(0);
	}
	/* Ler o registro em PRODUTOS.DAT */
	fread ( &reg,  sizeof(reg), 1, A );
	/* Fecha o arquivo */
	fclose (A);
}

void consulta_todos_produtos (void)
{
    FILE  *  A; /* A vari�vel 'A' se refere ao arquivo que vai ser manipuldo [PRODUTOS.DAT]*/
    A  =  fopen ("PRODUTOS.DAT" , "r"); /* Abre o arquivo para ler dados ["r"] */
    if ( A == NULL ) /* NULL ----> 00000000 00000000 */
    {
    	printf("ERRO AO ABRIR O ARQUIVO PRODUTOS.DAT!");
    	getch();
    	exit(0); /* finaliza a execu��o do programa */
	}
	system ("cls");
    /* Monta o cabe�alho de exibi��o em tela */
	printf ("\n================================================");
	printf ("\n               CADASTRO DE PRODUTOS             ");
	printf ("\n================================================");
    printf ("\n   CODPROD      NOME               VALOR (R$)   ");
	printf ("\n================================================");

    while ( !feof(A) )
    {
       /* L� um produto*/
       fread ( &reg,  sizeof(reg), 1, A );
       /* Para n�o mostrar o �ltimo 2 vezes: testa se j� leu o EOF (end of file) */
       if ( !feof(A) )
	   {  /* Exibe o registro lido na tela */
	       printf ("\n   %i\t\t%-20s\t%.2f" , reg.Codprod, reg.Nomeprod, reg.Custoprod ) ;
       }
    }
	/* Monta o rodap� de exibi��o em tela */
	printf ("\n================================================");
    getch();
}
