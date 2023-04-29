#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32 || _WIN64
	#include <Windows.h>
#else
	#include <unistd.h>
#endif

void limpar();
void esperar(int time);
void mostrar_lista(int tamanho, char **lista);
void apagar_item(int pos, int size, char **lista);
void add_item(int size, char **lista);
int eNumero(char *str);
char *tachar(char *str);

int main(void)
{
	int size, item_apagar, item_feito, escolha_menu;	
	//declaração da lista
	char **list;
	list = malloc(10 * sizeof(char*));
	
	for(int i = 0; i < 10; i++){
		list[i] = malloc(100 * sizeof(char));
	}
	/*	
	list[0] = "Comprar Arroz";
	list[1] = "Caminhar no parque";
	list[2] =  "Beber agua";
	*/
	size = 10;
	
	while (1)
	{
		while (1)
		{
			char aux[6];
			
			mostrar_lista(size, list);
			printf("Adicionar Item a Lista[0] \nRemover Item da Lista[1] \nMarcar como feito[2] \nSair do Programa [3]\n");
			
			fgets(aux, 6, stdin);
			if (aux[strlen(aux) - 1] == '\n')
			{
				aux[strlen(aux) - 1] = '\0';
			}

			if (eNumero(aux))
			{
				escolha_menu = atoi(aux);
				break;
			}
			limpar();
		}

		switch (escolha_menu)
		{
		case 0:
			limpar();
			mostrar_lista(size, list);
			printf("Digite algo para adicionar na lista: ");
			add_item(size, list);
			limpar();
			break;

		case 1:
			limpar();
			mostrar_lista(size, list);
			printf("Qual item deseja apagar?\n");
			scanf("%d", &item_apagar);
			apagar_item(item_apagar, size, list);
			limpar();
			getchar();
			break;

		case 2:
			limpar();
			mostrar_lista(size, list);
			printf("Qual item deseja marcar como feito?\n");
			scanf("%d", &item_feito);
			strcpy(list[item_feito], tachar(list[item_feito]));
			limpar();
			getchar();
			break;

		case 3:
			return 0;
			break;

		default:
			printf("\nOpção Invalida\n\n");
			esperar(1);
			limpar();
			break;
		}
	}

	return 0;
}

void limpar()
{
	#ifdef _WIN32 || _WIN64
		system("cls");
	#else
		system("clear");
	#endif
}

void esperar(int time)
{
	#ifdef _WIN32 || _WIN64
		Sleep(time);
	#else
		sleep(time);
	#endif
}

void mostrar_lista(int tamanho, char **lista)
{
	printf("\n");
	for (int i = 0; i < tamanho; i++)
	{
		if (lista[i][0] == '\0')
		{
			break;
		}
		printf("%d • %s\n", i, lista[i]);
	}
	printf("\n");
}

void apagar_item(int pos, int size, char **lista)
{
	//sobe os itens de posição, subtrai o índice em 1
	for (int i = 0; i < size; i++)
	{
		
		if (lista[pos + i][0] == '\0' && pos + i != pos)
		{
			break;
		}

		strcpy(lista[pos + i], lista[pos + i + 1]);
	}
}

void add_item(int size, char **lista)
{
	char aux[100];
	fgets(aux, 100, stdin);
	if (aux[strlen(aux) - 1] == '\n')
	{
		aux[strlen(aux) - 1] = '\0';
	}

	for (int i = 0; i < size; i++)
	{
		if (lista[i][0] == '\0')
		{
			strcpy(lista[i], aux);
			break;
		}
	}
}

int eNumero(char *str)
{
	char *stop = 0;
	strtoul(str, &stop, 10);
	return (stop - str == strlen(str));
}

char *tachar(char *str)
{
	//unicode de risco
	char *x = "\u0336";
	
	//verifica se a str já ta tachada
	for (int k = 1; k < strlen(x); k++)
	{
			if(str[k] == x[k - 1]) return str;		
	}
	
	//nova string riscada
	char *new_str = malloc((sizeof str) * (sizeof x) * 2);

	//laço que escreve a nova string
	for (int i = 0; i < strlen(str); i++)
	{
		//coloca caractere por caractere da string original no último índice ocupado + 1
		new_str[strlen(new_str)] = str[i];

		for (int j = 0; j < strlen(x); j++)
		{
			//injeta o símbolo de — char por char na nova str, sempre no último índice disponível
			new_str[strlen(new_str)] = x[j];
		}
	}

	return new_str;
}
