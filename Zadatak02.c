/*
** ПРОЈЕКАТ : ::: Принципи програмирања :::
**            Основе програмирања у програмском језику Ц
** ДАТОТЕКА : Vezbe06 > Zadatak02 > Zadatak02.c
** ОПИС     : Написати програм за рад са низовима целих бројева. Имплементирати следеће функције:
**				а) додавање елемента на почетак низа
**				б) промена вредности елемента на одређеној позицији у низу
**				в) избацивање елемента са почетка низа
**				г) проверити да ли одређени број постоји у низу
**				д) вратити индекс елемента са одређеном вредношћу, ако та вредност постоји у низу (ако не постоји, вратити -1)
** ДАТУМ    : 02.02.2025.
** ЛОКАЦИЈА : Београд
** АУТОРИ   : Саша Д. Лазаревић, Татјана Стојановић, Кристина Јовановић
** ПРОМЕНЕ  :
**   <dd.mm.gggg.> - <опис промене> (<програмер>)
**	 05.02.2025. - измењено заглавље програма (КЈ)
**
** Copyright (C) ФОН-ЛСИ/FON-LSI, 2025.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void ispisi_niz(int niz[], int broj_elemenata) {
	printf("Niz: ");
	for (int i = 0;i < broj_elemenata;i++) {
		printf("%d ", niz[i]);
	}
	printf("\n\n");
}

void dodaj_na_pocetak(int niz[], int* broj_elemenata, int broj) {
	// пошто желимо да додамо елемент на почетак, морамо прво све елементе да померимо за једно место удесно
	// како бисмо "ослободили" прво место за нови елемент који треба да убацимо
	for (int i = *broj_elemenata - 1;i >= 0;i--) {
		niz[i + 1] = niz[i];
	}
	niz[0] = broj;
	(*broj_elemenata)++; // *broj_elemenata = *broj_elemenata + 1;
}

void izmeni_element(int niz[], int broj_elemenata, int indeks, int novi_broj) {
	if (indeks >= broj_elemenata) {
		printf("Uneli ste nepostojeci indeks!\n");
	}
	else {
		niz[indeks] = novi_broj;
	}
}

int izbaci_sa_pocetka(int niz[], int* broj_elemenata) {

	if (*broj_elemenata == 0) {
		printf("Niz je prazan!\n");
		//return -1;	// некада нам је у реду да -1 буде ознака да је дошло до неке грешке, међутим у овом случају
						// -1 може да буде елемент низа који се избацује 
		return INT_MIN;	// зато ћемо искористити INT_MIN из stdlib.h библиотеке као ознаку да не постоји елемент у низу који можемо да избацимо
	}

	int izbaceni_element = niz[0];
	// пошто избацујемо први елемент, све остале елементе ћемо померити за једно место улево
	for (int i = 0;i < *broj_elemenata - 1;i++) {
		niz[i] = niz[i + 1];
	}
	(*broj_elemenata)--;
	return izbaceni_element;
}

int postoji_u_nizu(int niz[], int n, int trazeni_broj) {
	for (int i = 0;i < n;i++) {
		if (niz[i] == trazeni_broj)
			return 1;	// нашли смо елемент који је једнак траженом броју, значи тражени број постоји и враћамо 1
	}
	return 0;	// прошли смо кроз цео низ и нисмо нашли тражени број, дакле не постоји и враћамо 0
}

int vrati_indeks_trazenog_elementa(int niz[], int n, int trazeni_broj) {
	// с обзиром на то да већ имамо имплементирану функцију postoji_u_nizu, можемо искористити њу да одмах проверимо
	// да ли тражени број уопште постоји, па ако постоји, тражићемо његов индекс
	/*if (postoji_u_nizu(niz, n, trazeni_broj) == 0)
		return -1;
	*/
	/* // или можемо записати на овај начин:
	if (!postoji_u_nizu(niz, n, trazeni_broj))
		return -1;\
	*/

	// ако позивамо функцију postoji_u_nizu унутар ове функције, значи да ћемо два пута пролазити кроз
	// елементе низа, зато је са аспекта ефикасности боље написати функцију без позива функције postoji_u_nizu

	// можемо формулисати функцију и тако да има само једну излазну тачку односно једну return наредбу
	// на почетку ћемо поставити вредност променљиве indeks на -1 што означава да тражени елемент није пронађен (још увек)
	int indeks = -1;

	for (int i = 0;i < n;i++) {
		if (niz[i] == trazeni_broj) {
			indeks = i;	// уколико пронађемо елемент низа са траженом вредношћу, indeks ћемо поставити на тренутно i
			break;		// break наредбом излазимо из циклуса, јер уколико смо већ пронашли тражени елемент, нема потребе да даље итерирамо кроз низ
		}
	}
	return indeks;		// на крају враћамо вредност променљиве indeks - уколико тражени елемент није пронађен она ће идаље имати иницијалну вредност -1,
	// а уколико је пронађен имаће вредност те позиције на којој се тражени елемент налази
}

int main() {

	int niz[10] = { 4,5,7,3,8 };
	int n = 5; // број елемената низа

	ispisi_niz(niz, n);
	dodaj_na_pocetak(niz, &n, 10);
	ispisi_niz(niz, n);
	izmeni_element(niz, n, 2, 12);
	ispisi_niz(niz, n);

	int izbaceni = izbaci_sa_pocetka(niz, &n);
	ispisi_niz(niz, n);
	printf("Izbaceni element je: %d\n", izbaceni);

	printf("%d postoji u nizu? %d\n", 10, postoji_u_nizu(niz, n, 10));
	printf("%d postoji u nizu? %d\n", 3, postoji_u_nizu(niz, n, 3));

	printf("Indeks elementa %d je: %d\n", 4, vrati_indeks_trazenog_elementa(niz, n, 4));
	printf("Indeks elementa %d je: %d\n", 3, vrati_indeks_trazenog_elementa(niz, n, 3));
	printf("Indeks elementa %d je: %d\n", 10, vrati_indeks_trazenog_elementa(niz, n, 10));

	return 0;
}