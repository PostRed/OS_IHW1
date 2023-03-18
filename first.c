#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <search.h>


int main(int argc, char *argv[]) {
    int first[2], second[2], n, i, j, flag, flag2 = 0;
    size_t len, s;
    pipe(first);
    pipe(second);
    char in[1000];
    // Чтение
    pid_t pid = fork();
    if (pid == -1) {
        exit(1);
    } else if (pid == 0) {
        first[0] = open(argv[1], O_RDONLY);
        printf("%d\n", first[0]);
        if (first[0] < 0) {
            printf("Fail to open\n");
            exit(-1);
        }
        s = read(first[0], in, 1000);
        if (s == -1) {
            printf("Fail to read\n");
            exit(-1);
        }
        s = write(first[1], in, s);
        close(first[0]);
        close(first[1]);
        exit(0);
    } else {
        s = read(first[0], in, 1000);
        close(first[0]);
        close(first[1]);
    }
    // Логика приложения
    char str[1000];
    n = in[0] - '0';
    for (i = 1; i < strlen(in); i++) {
        str[i] = in[i];
    }
    len = strlen(str);
    char res[1000];
    for (i = 0; i <= len - n; i++) {
        flag = 1;
        // Смотрим подстроки
        for (j = i + 1; j < i + n; j++) {
            if (str[j] >= str[j - 1]) {
                // Если подстрока заданной длины не подходит под условие - опускаем флаг
                flag = 0;
                break;
            }
        }
        if (flag) {
            for (j = i; j < i + n; j++) {
                res[j - i] = str[j];
                flag2 = 1;
            }
            break;
        }
    }
    if (!flag2) {
        printf("No such sequence found.\n");
    }
    // Запись
    if (flag) {
        char out[1000];
        pid=fork();
        if (pid < 0) {
            exit(1);
        } else if (pid == 0) {
            second[1] = open(argv[2], O_WRONLY);
            printf("%d\n", second[1]);
            if (second[1]< 0) {
                printf("Fail to open\n");
                exit(-1);
            }
            s = read(second[0], out, 1000);
            int res_f = write(second[1], out, strlen(res));
            if (res_f == -1) {
                printf("Fail to read\n");
                exit(-1);
            }
            close(second[0]);
            close(second[1]);
        } else {
            write(second[1], res, s);
            close(second[0]);
            close(second[1]);
        }
    }
    return 0;
}
