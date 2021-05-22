#include <stdio.h>
#include <malloc.h>
#include <ctype.h>

int main() {
	int sletter = 0, bletter = 0, count = 0, digit = 0, k = 0;
	while (1) {
		printf("enter password (max 20 symbols):\n");
		char* mass = (char*)malloc(20 * sizeof(char));
		for (int i = 0; i < 20; i++) {
			mass[i] = getch();
			if (mass[i] == '\b') {
				if (i != 0) {
					if (i < 20) {
						printf("\b \b");
						i -= 2;
						continue;
					}
					else break;
				}
			}
			if (mass[i] != '\b') {
				if (mass[i] == 13) break;
				printf("*");
				++count;
			}
			if (k == 0) {
				for (int p = 0; p < 4; ++p) {
					if ((mass[i] > 96) && (mass[i] < 123)) {
						++sletter;
						bletter = 0;
						digit = 0;
					}
					if ((mass[i] > 64) && (mass[i] < 91)) {
						++bletter;
						sletter = 0;
						digit = 0;
					}
					if (isdigit(mass[i])) {
						++digit;
						sletter = 0;
						bletter = 0;
					}
					if ((sletter == 4) || (bletter == 4) || (digit == 4)) {
						++k;
					}
					break;
				}
			}
		}
		if (k == 1) {
			printf("\nbad password :( try again!\n");
			count = 0;
			k = 0;
		}
		else if ((k == 0) && (count >= 15)) {
			printf("\nok! good password\n");
			count = 0;
		}
		free(mass);
	}
	return 0;
}