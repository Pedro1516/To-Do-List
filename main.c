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
void mostrar_lista(int tamanho, char lista[10][50]);
void apagar_item(int pos, int size, char lista[10][50]);
void add_item(int size, char lista[10][50]);
int eNumero(char *str);
char *tachar(char *str);

int main(void)
{
	int size, i, j, item_apagar, item_feito,  escolha_menu;
	char p[10][50] = {"Comprar Arroz", "Caminhar no parque", "Beber agua"};
	size = sizeof(p) / sizeof(p[0]);
	i = 1;
	j = 1;

	while (i)
	{
		while (j)
		{
			mostrar_lista(size, p);
			printf("Adicionar Item a Lista[0] \nRemover Item da Lista[1] \nMarcar como feito[2] \nSair do Programa [3]\n");
			char aux[6];	
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
		
		//printf("%d\n", atoi(escolha_menu));

		//scanf("%d", &escolha_menu);

		switch (escolha_menu)
		{
		case 0:
			limpar();
			mostrar_lista(size, p);
			printf("Digite algo para adicionar na lista: ");
			add_item(size, p);
			limpar();
			break;

		case 1:
			limpar();
			mostrar_lista(size, p);
			printf("Qual item deseja apagar?\n");
			scanf("%d", &item_apagar);
			apagar_item(item_apagar, size, p);
			limpar();
			getchar();
			break;

		case 2:
			limpar();
			mostrar_lista(size, p);
			printf("Qual item deseja marcar como feito?\n");
			scanf("%d", &item_feito);
			strcpy(p[item_feito], tachar(p[item_feito]));
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

void mostrar_lista(int tamanho, char lista[10][50])
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

void apagar_item(int pos, int size, char lista[10][50])
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

void add_item(int size, char lista[10][50])
{
	char aux[50];
	fgets(aux, 50, stdin);
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
	//nova string riscada
	char *new_str = malloc((sizeof str) * (sizeof x) *2);

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
