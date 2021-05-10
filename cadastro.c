//author: Ricardo Matos
//github: @ricardothadeu

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
	struct cliente cl;
	Lista *li = cria_lista();
	int opcao;

	while(opcao != 5) 
	{
		printf("\nOlá! Digite a opção desejada:\n");
		printf("1 - Cadastrar um cliente:\n");
		printf("2 - Pesquisar um cliente:\n");
		printf("3 - Excluir um cliente:\n");
		printf("4 - Listar todos os clientes:\n");
		printf("5 - Sair\n\n");

		scanf("%d", &opcao);
	
		switch(opcao) 
		{
			case 1:
			{	
				system("clear");
				preenche_dados(&cl);
				incluir_cliente(li, cl);
		
				break;
			}

			case 2:
			{
				system("clear");
				char nome[50];
				printf("Digite o nome do cliente:\n");
				scanf(" %[^\n]s", nome);
				imprimir_cliente(li, nome);
		
				break;
			}

			case 3:
			{
				system("clear");
				char nome[50];
				printf("Digite o nome do cliente:\n");
				scanf(" %[^\n]s", nome);
				if(remover_cliente(li, nome))
					printf("Cadastro removido!\n");


				break;
			}
			case 4:
			{
				system("clear");
				imprimir_lista(li);
				break;
			}
		}
	}
	apaga_lista(li);
}