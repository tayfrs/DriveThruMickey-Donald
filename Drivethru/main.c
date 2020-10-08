#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


int main()
{
    setlocale(LC_ALL,"Portuguese");
    captura_produto();
	gravar_produto();
	Calcula_Qtd_Registro();
	ler_produto();
	consulta_todos_produtos();
    return 0;
}
