/**
 * @file matrix.h
 * @brief Templated Matrix class for Assignment 3 of 5614 C++ programming
 * @author Xueni Fu
 * @version 1.0
 * @date 2023-03-24
 */

#ifndef MATRIX_H_FIYNRKOJ
#define MATRIX_H_FIYNRKOJ

#include <iostream>
#include <iomanip>
#include <fstream>
#include "hpc_concepts.h"
#include "logging.h"

namespace HPC
{
	
	/**
	 * @brief Class to hold a Matrix. 5614 Assignment 3
	 *  	Modified from https://isocpp.org/wiki/faq/operator-overloading#matrix-subscript-op
	 *  	Store the matrix data as a single C-style array
	 *  	Students need to write function definitions for all the included member functions (except the deleted constructor)
	 *
	 * @tparam T Number type template parameter
	 */
	template <Number T>
		class Matrix {
			public:
				Matrix() = delete; 								// Delete default constructor. Really only a comment.
				Matrix(std::size_t const rows, std::size_t const cols); 			// Overloaded Constructor
				Matrix(std::string const file); 						// Overloaded Constructor. Read data from file.
				T& operator() (std::size_t const row_num, std::size_t const col_num);        	// non-const version which can be used to modify objects
				T  operator() (std::size_t const row_num, std::size_t const col_num) const;  	// Const version to be called on const objects

				~Matrix();                              // Destructor
				Matrix(Matrix const& m);               	// Copy constructor
				Matrix& operator=(Matrix const& m);   	// Assignment operator
				Matrix(Matrix && in); 			// Move Constructor
				Matrix& operator=(Matrix&& in); 	// Move Assignment operator

				// Note: Need the template brackets here in declaration.
				friend std::ostream& operator<< <>(std::ostream& os, Matrix<T> const& in);

				std::size_t get_num_rows() const{ return rows;};
				std::size_t get_num_cols() const{ return cols;};

			private:
				std::size_t rows, cols;
				T* data;
		};


	/**
	 * @brief Basic overloaded constructor for Matrix<T> class
	 * 		Note that this will set the values in data to zero.
	 * 		Don't need to check for negative values as size_t will be unsigned.
	 *
	 * @tparam T 	Number type that the matrix contains
	 * @param[in] num_rows Number of rows in created matrix
	 * @param[in] num_cols Number of columns in created matrix.
	 */
	template <Number T>
		Matrix<T>::Matrix(std::size_t const num_rows, std::size_t const num_cols)
		: rows {num_rows}
		, cols {num_cols}
		, data {new T [rows * cols]{}}
		{
			std::cout << "Constructing " << rows << " x " << cols << " Matrix\n";
		}
	
	// Constructor which read in matrix data from a file
	template <Number T>
		Matrix<T>::Matrix(std::string const file){
			
			static_assert(Number<T>, "Exception: Invalid type");

			// read in matrix data from a file
			std::ifstream infile;
			infile.open(file);
			if (!infile) {
				throw "Error: Could not open file ";
			}

			infile >> rows >> cols;

			data = new T[rows * cols];

			for (std::size_t i = 0; i < rows; i++) {
				for (std::size_t j = 0; j < cols; j++) {
					infile >> data[i * cols + j];
				}
			}
			
			infile.close();

			std::cout << "Constructing " << rows << " x " << cols << " Matrix with data read from file" << file << "\n";
		}
		
	// Destructor
	template <Number T>
		Matrix<T>::~Matrix() {
			delete [] data;
			std::cout << "Calling destructor for " << rows << " x " << cols << " Matrix\n";
		}

	// Copy constructor
	template <Number T>
		Matrix<T>::Matrix(Matrix const& m){
			data = new T[m.rows * m.cols];
			std::copy(m.data, m.data + m.rows * m.cols, data);
		}
		
	// Copy assignment operator
	template <Number T>
		Matrix<T>& Matrix<T>::operator=(Matrix const& m) {
			if (this != &m) {
				if (rows * cols != m.rows * m.cols) {
					delete [] data;
					data = new T[m.rows * m.cols];
				}
				rows = m.rows;
				cols = m.cols;
			}
			return *this;
		}

	// Move constructor
	template <Number T>
		Matrix<T>::Matrix(Matrix&& in) {
			data = new T[in.rows * in.cols];
			std::copy(in.data, in.data + in.rows * in.cols, data);
			in.data = nullptr;
		}

	// Move assignment operator
	template <Number T>
		Matrix<T>& Matrix<T>::operator=(Matrix<T>&& in) {
			if (this != &in) {
				if (rows * cols != in.rows * in.cols) {
					delete[] data;
					data = new T[in.rows * in.cols];
				}
				rows = in.rows;
				cols = in.cols;
			}
			in.data = nullptr;
			return *this;
		}

	// Overloading operator() for Matrix
	template <Number T>
		T& Matrix<T>::operator() (std::size_t const row_num, std::size_t const col_num) {
			if (row_num >= rows || col_num >= cols) {
				throw std::out_of_range("Error: Index out of range");
			}
			return data[row_num * cols + col_num];
		}

	template <Number T>
		T  Matrix<T>::operator() (std::size_t const row_num, std::size_t const col_num) const {
			if (row_num >= rows || col_num >= cols) {
				throw std::out_of_range("Error: Index out of range");
			}
			return data[row_num * cols + col_num];
		}


	// Non-member functions
	// print the matrix data to screen
	template <Number T>
		std::ostream& operator<<(std::ostream& os, const Matrix<T>& in) {
			for (std::size_t i = 0; i < in.get_num_rows(); i++) {
				os << " |";
				for (std::size_t j = 0; j < in.cols; j++) {
					os << std::setw(4) << std::setprecision(2) << in(i, j) << " ";
				}
					os << "  | \n";
			}
			return os;
		}

	// add the two input matrices and return a Matrix of the sum
	template <Number T1, Number T2>
		auto operator+(HPC::Matrix<T1> const& M1, HPC::Matrix<T2> const& M2) {
			if (M1.get_num_rows() != M2.get_num_rows() || M1.get_num_cols() != M2.get_num_cols()) {
				throw "Error: Matrices have different dimensions\n";
			}
			Matrix<decltype(T1{} + T2{})> Mat(M1.get_num_rows(), M1.get_num_cols());
			for (std::size_t i = 0; i < Mat.get_num_rows(); i++) {
				for (std::size_t j = 0; j < Mat.get_num_cols(); j++) {
					Mat(i,j) = (decltype(T1{} + T2{}))M1(i, j) + (decltype(T1{} + T2{}))M2(i, j);
				}
			}
			return Mat;
		}

	// multiply two matrices
	template <Number T1, Number T2>
		auto operator*(HPC::Matrix<T1> const& M1, HPC::Matrix<T2> const& M2) {
			if (M1.get_num_cols() != M2.get_num_rows()) {
				throw "Error: The number of rows of M1 doesn't match the number of columns of M2\n";
			}
			Matrix<decltype(T1{} + T2{})> Mat(M1.get_num_rows(), M2.get_num_cols());
			for (std::size_t i = 0; i < Mat.get_num_rows(); i++) {
				for (std::size_t j = 0; j < Mat.get_num_cols(); j++) {
					for (std::size_t k = 0; k < M1.get_num_cols(); k++) {
						Mat(i,j) += (decltype(T1{} + T2{}))M1(i,k) * (decltype(T1{} + T2{}))M2(k,j);
					}
				}
			}
			return Mat;
		}

	// takes in a reference to a Matrix and sets its values to an identity matrix
		void identity(auto& in) {
			if (in.get_num_cols() != in.get_num_rows()) {
				throw "Error: The Matrix is not a square Matrix\n";
			}
			for (std::size_t i = 0; i < in.get_num_rows(); i++) {
				for (std::size_t j = 0; j < in.get_num_cols(); j++) {
					in(i,j) = 0;
				}
			}
			for (std::size_t i = 0; i < in.get_num_rows(); i++) {
				in(i,i) = 1;
				}
		}


} /*  HPC */ 
#endif /* end of include guard: MATRIX_H_FIYNRKOJ */

