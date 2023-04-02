/*le matrix_operations.cc
 * @brief function to perform Gauss-Jordan elimination
 * @author Xueni Fu
 * @version 1.0
 * @date 2023-03-21
 */

#include "matrix_operations.h"

template <Number T, Number U>
HPC::Matrix<double> gaussjordan(HPC::Matrix<T> const& A, HPC::Matrix<U> const& B) {
	// Throw error if input is not right
	if (A.get_num_rows() != A.get_num_cols()) {
		throw "Matrix A is not a square Matrix\n";
	}

    	if (A.get_num_cols() != B.get_num_rows()) {
        	throw "A and B are not compatible for Gauss-Jordan elimination\n";
    	}	
	// Create copies into double
        //HPC::Matrix<double> a(A);
        //HPC::Matrix<double> b(B);
	HPC::Matrix<double> a(A.get_num_rows(), A.get_num_cols());
	for (std::size_t i = 0; i < a.get_num_rows(); i++) {
    		for (std::size_t j = 0; j < a.get_num_cols(); j++) {
        		a(i, j) = static_cast<double>(A(i, j));
    		}	
	}

	
	HPC::Matrix<double> b(B.get_num_rows(), B.get_num_cols());
	for (std::size_t i = 0; i < b.get_num_rows(); i++) {
    		for (std::size_t j = 0; j < b.get_num_cols(); j++) {
        		b(i, j) = static_cast<double>(B(i, j));
    		}	
	}

	std::size_t n = A.get_num_rows();


    for (std::size_t j = 0; j < n; j++) {
        for (std::size_t i = 0; i < n; i++) {
            if (i != j) {
                // Calculate the multiplier for row i to eliminate A(i,j)
                double multiplier = a(i, j) / a(j, j);

                // Eliminate A(i,j) by subtracting row j multiplied by the multiplier
                for (std::size_t k = 0; k < n; k++) {
                    a(i, k) -= multiplier * a(j, k);
                }

                // Eliminate B(i,j) by subtracting row j multiplied by the multiplier
                for (std::size_t k = 0; k < b.get_num_cols(); k++) {
                    b(i, k) -= multiplier * b(j, k);
                }
            }
        }
    }


    // Normalize the diagonal of A to 1
    for (std::size_t i = 0; i < n; i++) {
        double divisor = a(i, i);
        for (std::size_t j = 0; j < n; j++) {
            a(i, j) /= divisor;
        }
        for (std::size_t j = 0; j < b.get_num_cols(); j++) {
            b(i, j) /= divisor;
        }
    }

    // Return the row-reduced version of B
    return b;
}

template HPC::Matrix<double> gaussjordan<double, double>(HPC::Matrix<double> const&, HPC::Matrix<double> const&);
template HPC::Matrix<double> gaussjordan<int, int>(HPC::Matrix<int> const&, HPC::Matrix<int> const&);
template HPC::Matrix<double> gaussjordan<int, double>(HPC::Matrix<int> const&, HPC::Matrix<double> const&);
template HPC::Matrix<double> gaussjordan<double, int>(HPC::Matrix<double> const&, HPC::Matrix<int> const&);
