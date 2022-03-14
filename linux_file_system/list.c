#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "list.h"


int main(void)
{
	struct Directory *fs = NULL;
char comanda[30], nume[100], nu_conteaza[2], continut[100];
	int s;

	do {
		s = 99;
		scanf("%s", comanda);
		if (strcmp(comanda, "create") == 0)
			s = 0;
		if (strcmp(comanda, "delete") == 0)
			s = 1;
		if (strcmp(comanda, "touch") == 0)
			s = 2;
		if (strcmp(comanda, "mkdir") == 0)
			s = 3;
		if (strcmp(comanda, "ls") == 0)
			s = 4;
		if (strcmp(comanda, "pwd") == 0)
			s = 5;
		if (strcmp(comanda, "cd") == 0)
			s = 6;
		if (strcmp(comanda, "tree") == 0)
			s = 7;
		if (strcmp(comanda, "rmdir") == 0)
			s = 8;
		if (strcmp(comanda, "rm") == 0)
			s = 9;

		switch (s) {

			case 0: {
				scanf("%s", nu_conteaza);
				create_fs(&fs);
				s = 99;
				break;
			}

			case 1: {
				scanf("%s", nu_conteaza);
				delete_fs(&fs);
				break;
			}

			case 2: {
				scanf("%s", nume);
				scanf("%s", continut);
				//creem fisierul nou
				File *nou = malloc(sizeof(*nou));
				int a = strlen(nume)+1, b = strlen(continut)+1;

				nou->name = malloc(sizeof(*(nou->name))*a);
				strcpy(nou->name, nume);
				nou->size = strlen(continut);
				nou->data = malloc(sizeof(*nou->data)*b);
				strcpy(nou->data, continut);
				nou->dir = fs;
				touch(&fs, nou);

				s = 99;
				break;
			}

			case 3: {
				scanf("%s", nume);
				//creem directorul nou
				Directory *nou = malloc(sizeof(*nou));
				int a = strlen(nume)+1;

				nou->name = malloc(sizeof(*(nou->name))*a);
				strcpy(nou->name, nume);
				nou->parentDir = fs;
				mkdir(&fs, nou);

				s = 99;
				break;
			}

			case 4: {
				ls(fs);
				s = 99;
				break;
			}

			case 5: {
				pwd(fs);
				s = 99;
				break;
			}

			case 6: {
				scanf("%s", nume);
				cd(&fs, nume);
				s = 99;
				break;
			}

			case 7: {
				tree(fs, 0);
				s = 99;
				break;
			}
			case 8: {
				scanf("%s", nume);
				rmdir(&fs, nume);
				s = 99;
				break;
			}
			case 9: {
				scanf("%s", nume);
				rm(&fs, nume);
				s = 99;
				break;
			}
		}
	} while (s != 1);
	getchar();
}
