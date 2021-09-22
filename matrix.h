//
// Created by mikhalinho on 20.09.2021.
//

#ifndef J4F_MATRIX_H
#define J4F_MATRIX_H

#include <cstdio>
#include <cstdlib>

enum ERROR_LIST{
    ALL_OK,
    INVALID_INPUT,
    DIFFERENT_SIZES,
    ZERO_PTR,
};

class matrix {
public:
    matrix() = default;

    matrix(size_t rows, size_t columns):    row_size(rows),
                                            column_size(columns),
                                            data(new double [rows * columns + 1])
                                            {}

    void Print() const;

    int Hand_Assign();

    int Trans();

    double* SLAE (matrix* column) const;

    [[nodiscard]] double Determinant() const;

    [[nodiscard]] double at(size_t y, size_t x) const { return data[y * column_size + x]; }

    [[nodiscard]] size_t rows()     const { return row_size; }
    [[nodiscard]] size_t columns()  const { return column_size; }

    double* operator[](const int index) { return (double*)(data + index * column_size); }

    ~matrix() {
        free(data);
        row_size = 0;
        column_size = 0;
    }

private:
    matrix replace_column (matrix* column, size_t n_column) const;

private:
    size_t row_size     = 0;
    size_t column_size  = 0;
    double* data{};
};

matrix Mx_Sum (const matrix* mtrx1, const matrix* mtrx2);

matrix Mx_Multiply (const matrix* mtrx1, const matrix* mtrx2);


#endif //J4F_MATRIX_H
