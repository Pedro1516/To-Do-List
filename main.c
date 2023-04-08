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
void mostrar_lista(int tamanho, char lista[10][30]);
void apagar_item(int pos, int size, char lista[10][30]);
void add_item(int size, char lista[10][30]);

int main(void)
{
	int size, i, item_apagar, escolha_menu;
	char p[10][30] = {"Bye Bye", "Hello World", "Teste"};
	size = sizeof(p) / sizeof(p[0]);
	i = 1;

	while (i)
	{
		printf("Adicionar Item a Lista[0] \nRemover Item da Lista[1] \nVer Lista[2] \nSair do Programa [3]\n");
		scanf("%d", &escolha_menu);

		switch (escolha_menu)
		{
		case 0:
			limpar();
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
			break;

		case 2:
			limpar();
			mostrar_lista(size, p);
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

void mostrar_lista(int tamanho, char lista[10][30])
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

void apagar_item(int pos, int size, char lista[10][30])
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

void add_item(int size, char lista[10][30])
{
	char aux[30];
	getchar();
	fgets(aux, 30, stdin);
	if (aux[strlen(aux) - 1] == '\n')
	{
		aux[strlen(aux) - 1] = '\0';
	}
	//scanf("%s", aux);
	for (int i = 0; i < size; i++)
	{
		if (lista[i][0] == '\0')
		{
			strcpy(lista[i], aux);
			break;
		}
	}
}
