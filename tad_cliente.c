#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento {
	struct cliente cliente;
	struct elemento *prox;
};

typedef struct elemento Elem;

Lista *cria_lista()
{
	Lista *li = (Lista*)malloc(sizeof(Lista));

	if(li != NULL) // se a alocação da lista foi bem sucedida
		*li = NULL;

	return li;
}

int incluir_cliente(Lista *li, struct cliente cl)
{
	if(li == NULL)
		return 0;

	Elem *no = (Elem*)malloc(sizeof(Elem));

	if(no == NULL)
		return 0;  //erro na alocação de no

	no->cliente = cl;
	no->prox = NULL;

	if(*li == NULL)
		*li = no;  //se a lista estiver vazia, a inclusão é feita no inicio da lista
	else //caso contrário, percorremos a lista para incluir o cliente no final da lista
	{
		Elem *aux = *li;

		while(aux->prox != NULL)
			aux = aux->prox;

		aux->prox = no;
	}

	return 1;
}

int remover_cliente(Lista *li, char *nome)
{
	if(li == NULL)
		return 0;
	if(*li == NULL)
		return 0;

	Elem *anterior,
		 *no = *li;

	while(no != NULL && (strcmp(no->cliente.nome, nome) != 0))
	{
		anterior = no;
		no = no->prox;
	}

	if(no == NULL) //pessoa não encontrada
	{
		printf("Não existe essa pessoa na lista\n");
		return 0;
	}

	if(no == *li) //a lista só contem um elemento
		*li = no->prox;

	else
		anterior->prox = no->prox; //excluímos o cliente da lista;

	free(no);
	return 1;
}

void imprimir_lista(Lista *li)
{
	if(*li != NULL)
	{
		Elem *no = *li;

		while(no != NULL)
		{
			printf("%s\n", no->cliente.nome);
			printf("%s\n", no->cliente.email);
			printf("%s\n", no->cliente.cpf_cnpj);
			printf("%s\n", no->cliente.cep);
			printf("%s\n", no->cliente.logradouro);
			printf("%d\n", no->cliente.numero);
			printf("%s\n", no->cliente.bairro);
			printf("%s\n", no->cliente.cidade);
			printf("%s\n\n", no->cliente.estado);

			no = no->prox;
		}
	}
}

int imprimir_cliente(Lista *li, char *nome)
{
	if(*li != NULL)
	{
		Elem *no = *li;

		while(no != NULL)
		{
			if(strcmp(no->cliente.nome, nome) == 0)
			{
				printf("%s\n", no->cliente.nome);
				printf("%s\n", no->cliente.email);
				printf("%s\n", no->cliente.cpf_cnpj);
				printf("%s\n", no->cliente.cep);
				printf("%s\n", no->cliente.logradouro);
				printf("%d\n", no->cliente.numero);
				printf("%s\n", no->cliente.bairro);
				printf("%s\n", no->cliente.cidade);
				printf("%s\n\n", no->cliente.estado);


				return 1;
			}

			no = no->prox;
		}
	}
}

void apaga_lista(Lista *li)
{
	if(li != NULL)
	{
		Elem *no;

		while(*li != NULL)
		{
			no = *li;
			*li = (*li)->prox;
			free(no);
		}
	}

	free(li);
}

int preenche_dados(struct cliente *cl)
{
	printf("Digite os seus dados: \n");

	printf("Nome: ");
	scanf(" %[^\n]s", cl->nome);
	printf("E-mail: ");
	scanf(" %[^\n]s", cl->email);
	printf("CPF/CNPJ: ");
	scanf(" %[^\n]s", cl->cpf_cnpj);
	printf("Telefone: ");
	scanf(" %[^\n]s", cl->telefone);
	printf("CEP: ");
	scanf(" %[^\n]s", cl->cep);
	printf("Logradouro: ");
	scanf(" %[^\n]s", cl->logradouro);
	printf("Numero: ");
	scanf("%d", &cl->numero);
	printf("Bairro: ");
	scanf(" %[^\n]s", cl->bairro);
	printf("Cidade: ");
	scanf(" %[^\n]s", cl->cidade);
	printf("Estado: ");
	scanf(" %[^\n]s", cl->estado);
}