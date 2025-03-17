// MIT License

// Copyright (c) 2019 tomstewart89

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef BASIC_LINEAR_ALGEBRA_H
#define BASIC_LINEAR_ALGEBRA_H

#include <cmath>

template<int rows, int cols = 1, class MemT = float>
class Matrix 
{
public:
        MemT m[rows * cols];
        Matrix() {}
        
        // Element access
        MemT &operator()(int row, int col = 0) { return m[row * cols + col]; }
        const MemT &operator()(int row, int col = 0) const { return m[row * cols + col]; }
        
        void Fill(const MemT &val) {
            for(int i = 0; i < rows * cols; i++) m[i] = val;
        }
};

template<int rows, int cols = rows>
Matrix<rows,cols> Identity() {
    Matrix<rows,cols> ret;
    ret.Fill(0);
    for(int i = 0; i < rows; i++)
        ret(i,i) = 1;
    return ret;
}

template<int start, int end>
class Slice {
    public:
        static const int length = end - start;
};

template<class MatT>
class MatrixSlice {
    public:
        MatT &m;
        const int start_row, start_col;
        
        MatrixSlice(MatT &m, int start_row, int start_col): 
            m(m), start_row(start_row), start_col(start_col) {}

        template<class opMatT>
        MatrixSlice &operator=(const opMatT &op) {
            for(int i = 0; i < opMatT::rows; i++)
                for(int j = 0; j < opMatT::cols; j++)
                    m(i + start_row, j + start_col) = op(i,j);
    return *this;
}
};

template<int rows, int cols, class MemT>
MatrixSlice<Matrix<rows,cols,MemT> > Submatrix(Matrix<rows,cols,MemT> &m, 
    const Slice<0,rows> &row_range, const Slice<0,cols> &col_range) {
    return MatrixSlice<Matrix<rows,cols,MemT> >(m, 0, 0);
}

#endif