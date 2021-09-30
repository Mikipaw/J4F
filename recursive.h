//
// Created by mikhalinho on 30.09.2021.
//

#ifndef J4F_MYSTR_H
#define J4F_MYSTR_H

//This function finds size of string with number N
int counter(int N) {
    int size = 0;
    for (int j = 0; j < N; ++j) {
        size = size * 2 + 1;
    }
    return size;
};

//Recursive print line N from b to e
int printN(int N, int b, int e) {
    int size  = counter(N);
    int hsize = (size + 1) / 2;

    if (e == 0 || N == 0 || b > size) return 0;
    if (b > hsize) return printN(N - 1, b - hsize, e - hsize);

    if (b == 1) {
        printf("%c", 'a' + N - 1);
        b++;
    }

    printN(N - 1, b - 1, e - 1);
    if (e > hsize) printN(N - 1, 1, e - hsize);

    return 0;
}

#endif //J4F_MYSTR_H
