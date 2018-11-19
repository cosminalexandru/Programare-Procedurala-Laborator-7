#include <stdio.h>

enum {
    EXERCITIUL1 = 1,
    EXERCITIUL2,
    EXERCITIUL3,
    EXERCITIUL4,
    EXERCITIUL5,
    EXERCITIUL6,
    EXERCITIUL7,
    EXERCITIUL8,
    EXERCITIUL9,
    EXERCITIUL10,
};

enum {
    MINIM,
    MAXIM
};

void nextPrimeNumber(int n) {
    int i, j;
    for (i = n + 1;; i++) {
        for (j = 2; j < i; j++) {
            if (i % j == 0)
                break;
        }
        if (j == i) {
            printf("The next prime number is:%d", i);
            break;
        }
    }
}

int sumaDivizori(int x) {
    int sum = 0;
    for (int d = 1; d < x; d++) {
        if (x % d == 0) {
            sum += d;
        }
    }
    return sum;
}

void numar_de_tip_munte(int n) {
    int initialNumber = n;
    int lastDigit = n % 10;
    int helperDigit;
    int ok1 = 0, ok2 = 0;
    n /= 10;
    helperDigit = n % 10;
    while (helperDigit > lastDigit && n) {
        n /= 10;
        lastDigit = helperDigit;
        helperDigit = n % 10;
        ok1 = 1;
    }
    while (helperDigit < lastDigit && n) {
        n /= 10;
        lastDigit = helperDigit;
        helperDigit = n % 10;
        ok2 = 1;
    }
    if (n == 0 && ok1 == 1 && ok2 == 1)
        printf("%d ", initialNumber);
}

int splitNumber(int n) {
    int p = 1;
    int oddPosition = 0, evenPosition = 0;

    while (n) {
        oddPosition = (n % 10) * p + oddPosition;
        n = n / 10;
        if (n != 0) {
            evenPosition = (n % 10) * p + evenPosition;
            n = n / 10;
        }
        p *= 10;
    }
    printf("Odd position number:%d \n", oddPosition);
    printf("Even position number:%d ", evenPosition);
}

void deleteDigit(int n, int digit) {
    int p = 1;
    int newNumber = 0;
    while (n) {
        if (n % 10 != digit) {
            newNumber = (n % 10) * p + newNumber;
            p *= 10;
        }
        n /= 10;
    }
    printf("New number is: %d", newNumber);
}

void shiftVector(int v[], int n, int position) {
    int aux;
    for (int i = 0; i < position; i++) {
        aux = v[n - 1];
        for (int j = n - 1; j >= 1; j--) {
            v[j] = v[j - 1];
        }
        v[0] = aux;
    }
}

int linie(int a[20][20], int i, int j, int n) {
    int minim = a[i][0], maxim = a[i][0];
    for (int k = 1; k < n; k++) {
        if (a[i][k] < minim)
            minim = a[i][k];
        if (a[i][k] > maxim)
            maxim = a[i][k];
    }
    if (a[i][j] == minim)
        return MINIM;
    if (a[i][j] == maxim)
        return MAXIM;
}

int coloana(int a[20][20], int i, int j, int m) {
    int minim = a[0][j], maxim = a[0][j];
    for (int k = 1; k < m; k++) {
        if (a[k][j] < minim)
            minim = a[k][j];
        if (a[k][j] > maxim)
            maxim = a[k][j];
    }
    if (a[i][j] == minim)
        return MINIM;
    if (a[i][j] == maxim)
        return MAXIM;
}

void cifraMinMax(int n, int *cifraMinima, int *cifraMaxima) {
    *cifraMinima = 9, *cifraMaxima = 0;
    while (n) {
        if (n % 10 < *cifraMinima)
            *cifraMinima = n % 10;
        if (n % 10 > *cifraMaxima)
            *cifraMaxima = n % 10;
        n /= 10;
    }
}

int main() {
    printf("Introduceti numarul exercitiului(1-10):");
    int exNumber;
    scanf("%d", &exNumber);
    switch (exNumber) {
        case EXERCITIUL1: {
            int n;
            printf("Introduceti n =");
            scanf("%d", &n);
            nextPrimeNumber(n);
            break;
        }
        case EXERCITIUL2: {
            int n;
            printf("Introduceti n =");
            scanf("%d", &n);
            for (int firstFriendNumber = 1; firstFriendNumber <= n; firstFriendNumber++) {
                int secondFriendNumber = sumaDivizori(firstFriendNumber);
                if (secondFriendNumber < n && firstFriendNumber <= secondFriendNumber &&
                    sumaDivizori(secondFriendNumber) == firstFriendNumber) {
                    printf("(%d,%d)\n", firstFriendNumber, secondFriendNumber);
                }
            }
            break;
        }
        case EXERCITIUL3: {
            int a, b;
            printf("Introduceti a si b(a<b)");
            scanf("%d %d", &a, &b);
            for (int i = a; i <= b; i++)
                numar_de_tip_munte(i);
            break;
        }
        case EXERCITIUL4: {
            printf("Introduceti n=");
            int n;
            scanf("%d", &n);
            splitNumber(n);
            break;
        }
        case EXERCITIUL5: {
            printf("Introduceti numarul si cifra:");
            int n, digit;
            scanf("%d %d", &n, &digit);
            deleteDigit(n, digit);
            break;
        }
        case EXERCITIUL6: {
            int v[10][10] = {{1, 2, 3, 4, 5, 6, 7},
                             {1, 2, 3, 4, 5, 6, 7},
                             {1, 2, 3, 4, 5, 6, 7},
                             {1, 2, 3, 4, 5, 6, 7},
                             {1, 2, 3, 4, 5, 6, 7},
                             {1, 2, 3, 4, 5, 6, 7},
                             {1, 2, 3, 4, 5, 6, 7}};
            int n = 7, pos = 3;

            for (int i = 0; i < 7; i++) {
                shiftVector(*(v + i), n, i);
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    printf("%d ", v[i][j]);
                }
                printf("\n");
            }
            break;
        }
        case EXERCITIUL7: {
            int a[20][20] = {{1,  10, 11, 13},
                             {13, 1,  12, 22},
                             {44, 4,  10, 33},
                             {1,  2,  3,  44}};
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++)
                    if ((linie(a, i, j, 4) == MINIM && coloana(a, i, j, 4) == MAXIM) ||
                        (linie(a, i, j, 4) == MAXIM && coloana(a, i, j, 4) == MINIM))
                        printf("elementul de pe linie %d  coloana %d : %d este punct sa\n", i, j, a[i][j]);
            }
            break;
        }
        case EXERCITIUL8: {
            int n, cifraMinima, cifraMaxima;
            printf("Introduceti numarul:");
            scanf("%d", &n);
            for (int i = 1; i <= n; i++) {
                cifraMinMax(i, &cifraMinima, &cifraMaxima);
                if (cifraMaxima == cifraMinima)
                    printf("%d ", i);
            }

            break;
        }
        case EXERCITIUL9: {
            break;
        }
        case EXERCITIUL10: {
            break;
        }
        default: {

        }
    }
}