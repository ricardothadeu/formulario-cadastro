struct cliente {
	char nome[50];
	char email[50];
	char cpf_cnpj[15];
	char telefone[15];
	char cep[10];
	char logradouro[40];
	int numero;
	char bairro[40];
	char cidade[50];
	char estado[2];
};

typedef struct elemento *Lista;

Lista *cria_lista();
void apaga_lista(Lista *li);
int incluir_cliente(Lista *li, struct cliente cl);
void imprimir_lista(Lista *li);
int imprimir_cliente(Lista *li, char *nome);
int remover_cliente(Lista *li, char *nome);
int preenche_dados(struct cliente *cl);