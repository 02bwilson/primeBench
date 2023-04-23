#include <iostream>
#include <time.h>

short version = 0x01;

int test_prime(int n) {
    uint_fast64_t i, flag = 0;
    if (n == 0 || n == 1)
        flag = 1;

    for (i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        return 0x1;
    else
        return 0x0;

}

int main() {
    printf("Thank you for using primeBench! v%x\n", version);

    uint_fast64_t seconds = 0;
    uint_fast64_t count = 0;
    uint_fast64_t cur_time = 0;
    uint_fast64_t prev_time = 0;

    uint_fast64_t i = 0;

    while (true) {
        i++;
        cur_time = (int) time(NULL);
        test_prime(i);
        count++;

        if (cur_time != prev_time) {
            seconds++;
            prev_time = cur_time;
            printf("[%ds] CALCULATING PRIMES RATE :: %d :: %d\n", seconds, count / seconds, i);
        }
    }
}
