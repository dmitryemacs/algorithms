#include <stdio.h>

long fact(int);
long rfact(int);

int main(void) {
    int num;
    printf("Введите значение от 0 до 12 для вычисления факториала: ");
    while (scanf("%d", &num) == 1) {
        if(num < 0) printf("Отрицательные числа не подходят\n");
        else if (num > 12) {
            printf("Число должно быть меньше 13\n");
        } else {
            printf("цикл: факториал %d = %ld\n", num, fact(num));

            printf("рекурсия: факториал %d = %ld\n", num, rfact(num));
        }
    }
}

long fact(int n) {
    long ans;
    for (ans = 1; n > 1; n--) {
        ans *= n;
    }
    return ans;
}

long rfact(int n) {

    long ans;
    if(n > 0) {
        ans = n *rfact(n - 1);
    }
    else ans = 1;
    return ans;
}
