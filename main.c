#include <stdio.h>
#include <errno.h>
#include <locale.h>
#include <stdlib.h>

void inputPerson(struct person* person, struct person* pMaxim, int n, int i, FILE* in);
void inputPersons(struct person** persons, struct person** pMaxim, int n, FILE* in);
void output(struct person* person, int n);
void outputPersons(struct person* persons, int n);
void personFree(struct person* persons, int n);

struct person {
	unsigned int age;
	char* name;
};

int main() {
	setlocale(LC_ALL, "Rus");
	int n;
	struct person* p;
	struct person* pMax;
	FILE* in;
	int err = (fopen_s(&in, "persons.txt", "r+"));
	if (err != 0) {
		printf("Can't open file %s", "persons.txt");
		printf(" Value of errno: %d\n ", errno);
		exit(-1);
	}
	else {
		fscanf_s(in, "%d", &n);
		printf("inputting persons...\n");
		inputPersons(&p, &pMax, n, in);
		outputPersons(p, n);
		printf("\nThe most dinosaur: %u %s\n", pMax->age, pMax->name);
		personFree(p, n);
		personFree(pMax, n);
	}
	fclose(in);
	system("pause");
	return 0;
}

void inputPerson(struct person* person, struct person* pMaxim, int n, int i, FILE* in) {
	fscanf_s(in, "%u ", &(person->age));

	person->name = (char*)malloc(sizeof(char));
	fgets(person->name, 20, in);
	if (i == 0) {
		pMaxim->age = person->age;
		pMaxim->name = person->name;
	}
	if ((person->age) > (pMaxim->age)) {
		pMaxim->age = person->age;
		pMaxim->name = person->name;
	}

}

void inputPersons(struct person** persons, struct person** pMaxim, int n, FILE* in) {
	*persons = (struct person*)malloc(n * sizeof(struct person));
	*pMaxim = (struct person*)malloc(n * sizeof(struct person));
	for (int i = 0; i < n; ++i) {
		inputPerson((*persons + i), *pMaxim, n, i, in);
	}
}

void output(struct person* person, int n) {

	printf("%u %s\n", person->age, person->name);
}

void outputPersons(struct person* persons, int n) {
	for (int i = 0; i < n; ++i) {
		output(&persons[i], n);
	}
}

void personFree(struct person* persons, int n) {
	free(persons);
}