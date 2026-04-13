/*
** ПРОЈЕКАТ : ::: Принципи програмирања :::
**            Основе програмирања у програмском језику Ц
** ДАТОТЕКА : Vezbe05 > Zadatak04 > Zadatak04.c
** ОПИС     : Написати функцију која број прослеђен као параметар повећава за 2, али тако да промена буде видљива
**			  и ван те функције.
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

void povecaj_za_dva(int broj) {
	broj = broj + 2;
	printf("Unutar funkcije broj=%d\n", broj);
}

void povecaj_za_dva_pok(int* broj) {
	*broj += 2;
	printf("Unutar funkcije broj=%d\n", *broj);
}

int main() {

	int broj = 5;

	povecaj_za_dva(broj);
	printf("Van funkcije broj=%d\n", broj);
	// видимо да се вредност променљиве broj променила само унутар функције, али не и ван ње

	povecaj_za_dva_pok(&broj);
	printf("Van funkcije broj=%d\n", broj);
	// видимо да се вредност променљиве broj променила и унутар и ван функције

	return 0;
}