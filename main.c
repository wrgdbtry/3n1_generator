#include <stdio.h>
#include <math.h>

void writeCollatzSequence(FILE *file, int n) {
    while (n != 1) {
        fprintf(file, "%d -> ", n);
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
    }
    fprintf(file, "1\n");
}

int main() {
    int x;
    printf("Введите степень x (для 10^x): ");
    scanf("%d", &x);

    int limit = (int)pow(10, x);
    FILE *file = fopen("collatz_sequence.txt", "w");
    
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return 1;
    }

    for (int i = 1; i <= limit; i++) {
        fprintf(file, "Collatz sequence for %d: ", i);
        writeCollatzSequence(file, i);
    }

    fclose(file);
    return 0;
}
