/*
** ПРОЈЕКАТ : ::: Принципи програмирања :::
**            Основе програмирања у програмском језику Ц
** ДАТОТЕКА : Vezbe05 > Zadatak05 > Zadatak05.c
** ОПИС     : Написати функцију која враћа највећу цифру унетог броја.
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

int najveca_cifra(int broj) {
	int max = broj % 10;
	broj = broj / 10;

	while (1) {
		int cifra_jedinica = broj % 10;
		
		if (cifra_jedinica > max)
			max = cifra_jedinica;

		broj = broj / 10;
		if (broj == 0)		// услов за излазак из бесконачне петље
			break;
	}

	return max;
}

int main() {

	int broj = 4523;
	printf("Najveca cifra u broju %d je %d.\n", broj, najveca_cifra(broj));

	return 0;
}