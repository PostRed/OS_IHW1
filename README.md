# Коломникова Анастасия БПИ216 Вариант 3
## Разработать программу,находящую в заданной ASCII-строке первую слева направо последовательность N символов, каждый элемент которой определяется по условию «меньше предшествующего» (N вводится как отдельный параметр).

Тестировать я буду на этих файлах:
[test1](https://github.com/PostRed/OS_IHW1/blob/main/test1.txt), [test2](https://github.com/PostRed/OS_IHW1/blob/main/test2.txt), [test3](https://github.com/PostRed/OS_IHW1/blob/main/test3.txt), [test4](https://github.com/PostRed/OS_IHW1/blob/main/test4.txt), [test5](https://github.com/PostRed/OS_IHW1/blob/main/test5.txt).

:white_check_mark:  Программа на 4 балла:

Сам код лежит [здесь](https://github.com/PostRed/OS_IHW1/blob/main/first.c)

Сначала идет чтение файла,затем заимодействие между тремя дочерними процессами с использованием неименованных каналов и основная логика программы, затем происходит чтение файла для записи и запись в него. (В коде есть комментарии)

Результаты тестирования для работы на 4: [для 1-го теста](https://github.com/PostRed/OS_IHW1/blob/main/out1.txt), [для 2-го теста](https://github.com/PostRed/OS_IHW1/blob/main/out2.txt), [для 3-го теста](https://github.com/PostRed/OS_IHW1/blob/main/out3.txt), [для 4-го теста](https://github.com/PostRed/OS_IHW1/blob/main/out4.txt), [для 5-го теста](https://github.com/PostRed/OS_IHW1/blob/main/out5.txt).

:white_check_mark:  Программа на 5 баллов:

Сам код лежит [здесь](https://github.com/PostRed/OS_IHW1/blob/main/second.c)

Сначала идет чтение файла, затем взаимодействие между тремя дочерними процессами с использованием именованных каналов и основная логика программы, затем происходит чтение файла для записи и запись в него. (В коде есть комментарии)

Результаты тестирования для работы на 4: [для 1-го теста](https://github.com/PostRed/OS_IHW1/blob/main/out_2_1.txt), [для 2-го теста](https://github.com/PostRed/OS_IHW1/blob/main/out_2_2.txt), [для 3-го теста](https://github.com/PostRed/OS_IHW1/blob/main/out_2_3.txt), [для 4-го теста](https://github.com/PostRed/OS_IHW1/blob/main/out_2_4.txt), [для 5-го теста](https://github.com/PostRed/OS_IHW1/blob/main/out_2_5.txt).
