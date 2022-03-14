#ifndef __LIST_H__
#define __LIST_H__

void create_fs(Directory **sp)
{
	//creem directorul "/"
	Directory *nou = malloc(sizeof(*nou));

	nou->name = malloc(sizeof(*(nou->name))*(strlen("/")+1));
	strcpy(nou->name, "/");
	*sp = nou;
}

void delete_fs(Directory **sp)
{
	//eliberam memoria directorului "/"
	free((*sp)->name);
	free((*sp)->directoryy);
	free((*sp)->filee);
	free((*sp)->parentDir);
	free(*sp);
}

void touch(Directory **sp, File *nou)
{
	if ((*sp)->filee != NULL) {
		//lista nu este vida inseram in lista
		f_list *fila_noua = malloc(sizeof(*fila_noua));

		fila_noua->file = malloc(sizeof(*(fila_noua->file)));
		fila_noua->file = nou;
		f_list *it = (*sp)->filee;

		//verificam daca fisierul trebuie pus la inceputul listei
		//sau undeva in lista
		if (strcmp(nou->name, (*sp)->filee->file->name) >= 0) {
			//cautam locul in lista al fisierului
			for ( ; it->next; it = it->next)
				if (strcmp(nou->name, it->next->file->name) < 0)
					break;
			//inseram fisierul
			fila_noua->next = it->next;
			it->next = fila_noua; }
		else {
			//la inceputul listei
			fila_noua->next = it;
			(*sp)->filee = fila_noua;
		}
	} else {
		//la inceputul listei daca lista este vida
		(*sp)->filee = malloc(sizeof((*sp)->filee));
		(*sp)->filee->file = malloc(sizeof(((*sp)->filee->file)));
		(*sp)->filee->file = nou;
	}
}

void mkdir(Directory **sp, Directory *nou)
{
	if ((*sp)->directoryy != NULL) {
		//lista nu este vida inseram in lista
		d_list *director_nou = malloc(sizeof(*director_nou));

		director_nou->dir = malloc(sizeof(*(director_nou->dir)));
		d_list *it = (*sp)->directoryy;

		//verificam daca directorul trebuie pus la inceputul listei
		//sau undeva in lista
		director_nou->dir = nou;
		if (strcmp(nou->name, (*sp)->directoryy->dir->name) >= 0) {
			for ( ; it->next; it = it->next)
				if (strcmp(nou->name, it->next->dir->name) < 0)
					break;
			//inseram fisierul
			director_nou->next = it->next;
			it->next = director_nou; }
		else {
			//la inceput
			director_nou->next = it;
			(*sp)->directoryy = director_nou;
		}
	} else {
		//la inceputul listei daca lista este vida
		(*sp)->directoryy = malloc(sizeof(*((*sp)->directoryy)));
		(*sp)->directoryy->dir = malloc(sizeof(Directory));
		(*sp)->directoryy->dir = nou;
	}
}


void ls(Directory *sp)
{
	//parcurgem listele de fisire respectiv directoare
	for (f_list *it = sp->filee; it; it = it->next)
		printf("%s ", it->file->name);
	for (d_list *iti = sp->directoryy; iti; iti = iti->next)
		printf("%s ", iti->dir->name);
	printf("\n");
}

void pwd(Directory *sp)
{
	//vector de pointeri pentru numele directoarelor
	Directory *iti = sp;
	char **merge;
	int i = 0;

	merge = malloc(sizeof(*merge)*10);
	//verificam numele directorului in care ne aflam
	if (strcmp(iti->name, "/") == 0) {
		merge[i] = iti->name;
		i++;
	}
	//parcurgem directoarele pana la "/"
	for (Directory *it = sp; it; it = it->parentDir) {
		if (strcmp(it->name, "/") != 0) {
			merge[i] = it->name;
			i++;
		}
	}
	//afisam calea
	for (int c = i-1; c >= 0; c--) {
		if (strcmp(merge[c], "/") == 0)
			printf("%s", merge[c]);
		else
			printf("/%s", merge[c]);
	}
	printf("\n");
	free(merge);
}

void cd(Directory **sp, char *nume)
{
	char asta2[2] = "..";
	Directory *aici = *sp;

	//daca nume e .. mergem inapoi
	if (strcmp(nume, asta2) == 0)
		*sp = (*sp)->parentDir;
	else {
		// cautam directorul in lista de directoare
		(*sp) = aici;
		//parcurgem lista de directoare
		for (d_list *it = (*sp)->directoryy; it; it = it->next)
			if (strcmp(nume, it->dir->name) == 0) {
				(*sp) = it->dir;
				break;
		}
	}
	if (*sp == aici)
		printf("Cannot move to '%s': No such directory!\n", nume);
}

void tree(Directory *sp, int nr)
{
	//spatierea
	for (int i = 0; i < nr; i++)
		printf(" ");
	printf("%s\n", sp->name);
	//afisam fisierele
	for (f_list *it = sp->filee; it; it = it->next) {
		for (int i = 0; i < nr+4; i++)
			printf(" ");
		printf("%s\n", it->file->name);
	}
	d_list *iti = sp->directoryy;

	//parcurgem directoarele si reapelam functia modificand spatiul
	while (iti != NULL) {
		nr = nr+4;
		tree(iti->dir, nr);
		nr = nr-4;
		iti = iti->next;
	}
}

void rmdir(Directory **sp, char *numele)
{
	// doi poiteri pentru parcurgerea listei de directoare
	d_list *it = (*sp)->directoryy, *prev;

	//directorul e primul in lista
	if (it != NULL && strcmp(it->dir->name, numele) == 0) {

		(*sp)->directoryy = it->next;
		//eliberam memoria
		free(it->dir->name);
		free(it->dir->directoryy);
		free(it->dir->filee);
		free(it->dir);
		free(it);
		return;
	}
	//cautam directorul copiiand elementele parcurse in pointerul prev
	it = (*sp)->directoryy;
	while (it != NULL) {
		if (strcmp(it->dir->name, numele) != 0) {
			prev = it;
			it = it->next; }
		else {
			break;
		}
	}

	if (it == NULL) {
		printf("Cannot remove '%s': No such directory!\n", numele);
		return;
	}
	//punem elementele de dupa directorul de sters in prev
	prev->next = it->next;
	//eliberam memoria
	free(it->dir->name);
	free(it->dir->directoryy);
	free(it->dir->filee);
	free(it->dir);
	free(it);
}


void rm(Directory **sp, char *numele)
{
	// doi poiteri pentru parcurgerea listei de fisire
	f_list *it = (*sp)->filee, *prev;

	//fisierul e primul in lista
	if (it != NULL && strcmp(it->file->name, numele) == 0) {

		(*sp)->filee = it->next;
		//eliberam memoria
		free(it->file->name);
		free(it->file->data);
		free(it->file);
		free(it);
		return;
	}
	//cautam fisierul copiiand elementele parcurse in pointerul prev
	while (it != NULL) {
		if (strcmp(it->file->name, numele) != 0) {
			prev = it;
			it = it->next; }
		else {
			break;
		}
	}
	if (it == NULL) {
		printf("Cannot remove '%s': No such file!\n", numele);
		return;
	}
	//punem elementele de dupa fisierul de sters in prev
	prev->next = it->next;
	//eliberam memoria
	free(it->file->name);
	free(it->file->data);
	free(it->file);
	free(it);
}



#endif
