#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <search.h>
#include <string.h>


int main(int argc, char *argv[]) {
    int first, second, n, i, j, flag, flag2 = 0, help, s, help_2;
    size_t len;
    char in[1000];
    mknod("r", S_IFIFO | 0666, 0);
    mknod("w", S_IFIFO | 0666, 0);
    pid_t pid = fork();
    if (pid < 0) {
        exit(1);
    } else if (pid == 0) {
        help = open(argv[1], O_RDONLY);
        if (help < 0) {
            printf("Fail to open\n");
            exit(-1);
        }
        first = open("r", O_WRONLY);
        if(first < 0){
            exit(-1);
        }
        s = read(help, in, 1000);
        if (s == -1) {
            printf("Fail to resd\n");
            exit(-1);
        }
        s = write(first, in, s);
        close(first);
        exit(0);
    } else {
        first = open("r", O_RDONLY);
        s = read(first, in, 1000);
        close(first);
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
    if (flag) {
        char out[1000];
        pid_t pid = fork();
        if (pid < 0) {
            exit(1);
        } else if (pid == 0) {
            help = open(argv[2], O_WRONLY);
            if (help < 0) {
                printf("Fail to open\n");
                exit(-1);
            }
            second = open("w", O_RDONLY);
            if(second < 0){
                exit(-1);
            }
            s = read(second, out, 1000);
            int reas_f = write(help, out, strlen(res));
            if (reas_f == -1) {
                printf("Fail to write\n");
                exit(-1);
            }
            close(second);
        } else {
            second = open("w", O_WRONLY);
            s = write(second, res, s);
            close(second);
        }
    }
    return 0;
}
