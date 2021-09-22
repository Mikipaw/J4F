//
// Created by mikhalinho on 20.09.2021.
//

#include <cmath>
#include "matrix.h"

void matrix::Print() const {
    for (int y = 0; y < row_size; ++y) {
        for (int x = 0; x < column_size; ++x) printf("%.2lf\t", this->at(y, x));
        printf("\n");
    }
}

int matrix::Hand_Assign() {
    double a = 0;

    if (data == nullptr) return ZERO_PTR;

    for (int y = 0; y < row_size; ++y) {
        for (int x = 0; x < column_size; ++x) {
            if (!scanf("%lf", &data[y * column_size + x]))
                return INVALID_INPUT;
        }
    }

    printf("Your matrix:\n");
    this->Print();

    return ALL_OK;
}


matrix Mx_Sum (const matrix* mtrx1, const matrix* mtrx2) {
    matrix result;
    if (mtrx1->rows() != mtrx2->rows() || mtrx1->columns() != mtrx2->columns()) {
        fprintf(stderr, "Matrices have different sizes!\n");
        return result;
    }

    result = matrix(mtrx1->rows(), mtrx1->columns());
    for (int y = 0; y < mtrx1->columns(); ++y) {
        for (int x = 0; x < mtrx2->rows(); ++x) {
            result[y][x] = mtrx1->at(y, x) + mtrx2->at(y, x);
        }
    }

    return result;
}

matrix Mx_Multiply (const matrix* mtrx1, const matrix* mtrx2) {
    matrix result;

    if (mtrx1 == nullptr || mtrx2 == nullptr) {
        fprintf(stderr, "Invalid input.\n Zero pointer.\n");
        return result;
    }

    if (mtrx1->columns() != mtrx2->rows()) {
        fprintf(stderr, "Matrix 1 columns must be equal matrix 2 rows!\n");
        return result;
    }

    double sum = 0;
    result = matrix(mtrx1->rows(), mtrx2->columns());

    for (int y = 0; y < mtrx1->rows(); ++y) {
        for (int x = 0; x < mtrx2->columns(); ++x) {
            sum = 0;
            for (int i = 0; i < mtrx1->columns(); ++i)
                sum += mtrx1->at(y, i) * mtrx2->at(i, x);
        }
    }

    return result;
}

int matrix::Trans() {
    if (data == nullptr) return ZERO_PTR;

    matrix result (column_size, row_size);

    for (int y = 0; y < row_size; ++y) {
        for (int x = 0; x < column_size; ++x)
            result[y][x] = *this[x][y];
    }

    *this = result;

    return ALL_OK;
}

double matrix::Determinant() const {
    if (data == nullptr) return ZERO_PTR;
    if (row_size != column_size) return INVALID_INPUT; //matrix has to be a square matrix.

    double sum      = 0;
    double mult     = 1;
    double addition = 0;
    for (int i = 0; i < row_size; ++i) {
        for (int k = 0; k < row_size; --k) {
            mult *= this->at(k, (k + i) % (int)row_size);
        }
        sum += mult;
        mult = 1;
    }

    for (int i = 0; i < row_size; ++i) {
        for (int k = (int)row_size - 1; k >= 0; --k) {
            mult *= this->at(k, (k - i) % (int)row_size);
        }
        sum -= mult;
        mult = 1;
    }

    return sum;
}

matrix matrix::replace_column (matrix* column, size_t n_column) const {
    matrix result;

    if (column->columns() > 1) {
        fprintf(stderr, "Column has to have 1 column");
        return result;
    }

    if (column->rows() != this->row_size) {
        fprintf(stderr, "Column has to have number of rows equal to number of matrix rows\n");
        return result;
    }

    result = *this;
    for (int i = 0; i < row_size; ++i)
        result[i][n_column] = column->at(i, 0);

    return result;
}

double* matrix::SLAE (matrix* column) const {
    if (row_size != column_size) {
        fprintf(stderr, "Matrix has to be square!\n");
        return nullptr;
    }

    if (column->rows() != row_size) {
        fprintf(stderr, "Invalid column!\n");
        return nullptr;
    }

    if (row_size < 2) {
        fprintf(stderr, "Invalid size of matrix. It must be 2x2 at least\n");
        return nullptr;
    }

    double* result = (double*)calloc(row_size, sizeof(double));
    double det = Determinant();
    if (det == 0) {
        for (int i = 0; i < row_size; ++i) {
            if (column[i][0] != 0) {
                result[0] = 0;
                for (int j = 1; j < row_size; ++j) result[j] = NAN;
                return result;
            }
        }
        result[0] = -8;
        for (int j = 1; j < row_size; ++j) result[j] = NAN;
        return result;
    }

    matrix replaced_column (row_size, column_size);
    double det_i = 0;

    for (int i = 0; i < row_size; ++i) {
        replaced_column = this->replace_column(column, i);
        det_i = replaced_column.Determinant();

        result[i] = det_i/det;
    }

    return result;
}

void matrix::uPrT_PrinT() const {
    size_t y = -column_size + 1, x = -row_size + 1;
    //printf("%u \t %u \t %u \n", x, y, 0-y);

    while (y != 1) {
        while (x != 1) {
            printf("%lf \t",
                   0[(double*)((char*)data
                        + ((row_size - 1 - (int)((size_t)(0 - y)))
                            * column_size + column_size - 1 - (int)((size_t)(0 - x)))
                            * sizeof(double))]);
            ++x;
        }
        printf("\n");
        ++y;
        x = -row_size + 1;
    }

}