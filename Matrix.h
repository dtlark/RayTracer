#pragma once

#include "Tuple.h"
#include "Point.h"
#include "Vector.h"

#include <algorithm>
#include <ostream>
#include <vector>
#include <cmath>

using namespace std;

class Matrix {

	int row = 0;
	int col = 0;
	vector<vector<double>> matrixData;

public:

	Matrix() {

		matrixData = { {1, 0, 0, 0},
					  {0, 1, 0, 0},
					  {0, 0, 1, 0},
					  {0, 0, 0, 1} };



	}

	Matrix(vector<vector<double>> data) {

		row = data.size();
		col = data[0].size();

		for (int i = 0; i < data.size(); i++) {
			matrixData.push_back(data[i]);
		}
	}

	Matrix(int _row, int _col) {

		row = _row;
		col = _col;
		for (int i = 0; i < row; i++) {
			vector<double> temp;
			for (int j = 0; j < col; j++) {
				temp.push_back(0);
			}
			matrixData.push_back(temp);
		}
	}

	bool operator==(Matrix const& other) const {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (matrixData[i][j] != other.matrixData[i][j]) {
					return false;
				}
			}
		}
		return true;
	}

	void operator=(Matrix const& other) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				matrixData[i][j] = other.matrixData[i][j];
			}
		}
	}

	Matrix operator*(Matrix const& other) const { //matrix * matrix //

		Matrix temp(row, other.col);

		if (col != other.row) {
			cout << "Column of first matrix should be equal to row of second matrix" << endl;
		}
		else {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < other.col; j++) {
					for (int k = 0; k < col; k++) {
						temp.matrixData[i][j] += matrixData[i][k] * other.matrixData[k][j];
					}
				}
			}

		}
		return temp;
	}

	Point operator*(Point const& other) const {  //matrix * tuple is tuple

		vector<double> temp = other.getAll();
		vector<double> final;

		if (row != 4) {
			cout << "Column of first matrix should be equal to row of second matrix" << endl;
		}
		else {
			for (int i = 0; i < row; i++) {
				double num = 0;
				for (int j = 0; j < col; j++) {
					num += matrixData[i][j] * temp[j];
				}
				final.push_back(num);
			}
		}
		return Point(final[0],
					 final[1],
					 final[2]);
	}

	Vector operator*(Vector const& other) const {  //matrix * tuple is tuple

		vector<double> temp = other.getAll();
		vector<double> final;

		if (row != 4) {
			cout << "Column of first matrix should be equal to row of second matrix" << endl;
		}
		else {
			for (int i = 0; i < row; i++) {
				double num = 0;
				for (int j = 0; j < col; j++) {
					num += matrixData[i][j] * temp[j];
				}
				final.push_back(num);
			}
		}
		return Vector(final[0],
			final[1],
			final[2]);
	}


	void Print() {
		cout << "  Matrix <" << row << ", " << col << ">" << endl;
		for (int i = 0; i < row; i++) {
			cout << " | ";
			for (int j = 0; j < col; j++) {
				cout << matrixData[i][j] << " | ";
				//cout << "(" << i << "," << j << ")" << " | ";
			}
			cout << endl;
		}
	}

	int getRow() const {
		return row;
	}
	int getCol() const {
		return col;
	}
	Matrix getMatrix() {
		return matrixData;
	};



	//transpose matrix
	Matrix transpose() {
		Matrix temp(row, col);

		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				temp.matrixData[j][i] = matrixData[i][j];
			}
		}
		return temp;
	}

	Matrix submatrix(int x, int y) { // use on a Matrix 4
		
		Matrix sub = Matrix({{0, 0, 0},
							 {0, 0, 0},
							 {0, 0, 0}});
		int i = 0;

		for (int r = 0; r < row; r++) {
			
			int j = 0;
			if (r == x) {
				continue;
			}

			for (int c = 0; c < col; c++) {
				
				if (c == y) {
					continue;
				}

				sub.matrixData[i][j] = this->matrixData[r][c];
				j++;
			}
			i++;
		}

		return sub;
	}


	/* Recursive function for finding determinant of matrix.
	   n is current dimension of A[][]. */
	double determinant(vector<vector<double>> A, int n) {
		double D = 0; // Initialize result 

		//  Base case : if matrix contains single element 
		if (n == 1) {
			return A[0][0];
		}


		int sign = 1;  // To store sign multiplier 
		vector<vector<double>> temp = nullVec; // To store cofactors 

		 // Iterate for each element of first row 
		for (int f = 0; f < n; f++) {
			// Getting Cofactor of A[0][f] 
			getCofactor(A, temp, 0, f, n);
			D += sign * A[0][f] * determinant(temp, n - 1);
			// terms are to be added with alternate sign 
			sign = -sign;
		}

		//cout << "D:" << D << endl;
		return D;
	}

	vector<vector<double>> nullVec = { {0, 0, 0, 0},
									   {0, 0, 0, 0},
									   {0, 0, 0, 0},
									   {0, 0, 0, 0} };

	void getCofactor(vector<vector<double>> A, vector<vector<double>>& temp, int p, int q, int n) {
		int i = 0, j = 0;

		// Looping for each element of the matrix 
		for (int row = 0; row < n; row++) {

			for (int col = 0; col < n; col++)
			{
				//cout << "IN COFACTOR2" << endl;
				//  Copying into temporary matrix only those element 
				//  which are not in given row and column 

				if (row != p && col != q) {
					temp[i][j] = A[row][col];
					j++;

					// Row is filled, so increase row index and 
					// reset col index 
					if (j == n - 1) {
						j = 0;
						i++;
					}
				}
			}
		}
	}

	

	// Function to get adjoint of A[N][N] in adj[N][N]. 
	void adjoint(vector<vector<double>> A, vector<vector<double>>& adj) {
		// temp is used to store cofactors of A[][] 
		int sign = 1;
		vector<vector<double>> temp = nullVec;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				// Get cofactor of A[i][j] 
				getCofactor(A, temp, i, j, 4);

				// sign of adj[j][i] positive if sum of row 
				// and column indexes is even. 
				sign = ((i + j) % 2 == 0) ? 1 : -1;

				// Interchanging rows and columns to get the 
				// transpose of the cofactor matrix 
				adj[j][i] = (sign) * (determinant(temp, 4 - 1));
			}
		}
	}

	// Function to calculate and store inverse, returns false if 
	// matrix is singular 
	Matrix inverse() {
		vector<vector<double>> inverse = nullVec;

		vector<vector<double>> identity = { {1, 0, 0, 0},
			{ 0, 1, 0, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 0, 1 } };


		if (matrixData == identity) {
			return identity;
		}


		// Find determinant of A[][] 
		double det = determinant(matrixData, 4);
		if (det == 0) {
			cout << "Singular matrix, can't find its inverse" << endl;
			//return false;
		}

		// Find adjoint 

		vector<vector<double>> adj = nullVec;
		adjoint(matrixData, adj);

		// Find Inverse using formula "inverse(A) = adj(A)/det(A)" 
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				inverse[i][j] = adj[i][j] / double(det);
			}
		}

		return Matrix(inverse);
	}


	//////////////////////////////////////////////////////////////////////////////////////

	//Translation
	Matrix translationMatrix(double x, double y, double z) {
		vector<vector<double>> transMat = { {1, 0, 0, x},
										  {0, 1, 0, y},
										  {0, 0, 1, z},
										  {0, 0, 0, 1} };
		Matrix temp = Matrix(transMat);
		return temp;
	}
	//TODO: Multiply inverse of a translation matrix
	//TODO?: Translation does not affect vectors
	void translate(double x, double y, double z) {
		
		Matrix temp = translationMatrix(x, y, z);
		Matrix temp2 = matrixData;
		matrixData = (temp * temp2).matrixData;
	
	}

	
	//Scaling
	Matrix scalingMatrix(double x, double y, double z) {

		vector<vector<double>> scaleMat = {{x, 0, 0, 0},
										  {0, y, 0, 0},
										  {0, 0, z, 0},
										  {0, 0, 0, 1}};
		Matrix temp = Matrix(scaleMat);
		return temp;
	}
	//TODO: Multiply translation matrix * point
	//TODO: Multiply scaling * vector
	void scale(double x, double y, double z) {
	
		Matrix temp = scalingMatrix(x, y, z);
		Matrix temp2 = matrixData;
		matrixData = (temp * temp2).matrixData;
	}


	//TODO: Rotation Points


	Matrix rotationMatrix(double x, double y, double z) {
	
		Matrix X = Matrix().rotationXMatrix(x);
		Matrix Y = Matrix().rotationYMatrix(y);
		Matrix Z = Matrix().rotationZMatrix(z);
		return X * Y * Z;
	}
	void rotate(double x, double y, double z) {

		Matrix temp = rotationMatrix(x, y, z);
		Matrix temp2 = matrixData;
		matrixData = (temp * temp2).matrixData;
	}



	//RotationX
	Matrix rotationXMatrix(double radians) {
		double const c = std::cos(radians);
		double const s = std::sin(radians);
		vector<vector<double>> temp = {{1, 0, 0, 0},
									  {0,  c , -s , 0},
									  {0,  s ,  c , 0},
									  {0, 0, 0, 1}};
		return temp;
	}
	void rotateX(double radians) {

		Matrix temp = rotationXMatrix(radians);
		Matrix temp2 = matrixData;
		matrixData = (temp * temp2).matrixData;
	}

	//RotationY
	Matrix rotationYMatrix(double radians) {
		double const c = std::cos(radians);
		double const s = std::sin(radians);
		vector<vector<double>> temp = {{c, 0, s, 0},
									  {0, 1, 0, 0},
									  {-s, 0,  c, 0},
									  {0, 0, 0, 1}};
		return temp;
	}
	void rotateY(double radians) {

		Matrix temp = rotationYMatrix(radians);
		Matrix temp2 = matrixData;
		matrixData = (temp * temp2).matrixData;
	}

	//RotationZ
	Matrix rotationZMatrix(double radians) {
		double const c = std::cos(radians);
		double const s = std::sin(radians);
		vector<vector<double>> temp = {{c, -s, 0, 0},
									  {s,  c, 0, 0},
									  {0, 0, 1, 0},
									  {0, 0, 0, 1}};
		return temp;
	}
	void rotateZ(double radians) {

		Matrix temp = rotationZMatrix(radians);
		Matrix temp2 = matrixData;
		matrixData = (temp * temp2).matrixData;
	}

	//Shearing
	Matrix shearingMatrix(double xy, double xz, double yx, double yz, double zx, double zy) {
		vector<vector<double>> temp = {{1, xy, xz, 0},
									  {yx, 1,  yz, 0},
									  {zx, zy, 1, 0},
									  {0, 0, 0, 1} };
		return temp;
	}
	void shear(double xy, double xz, double yx, double yz, double zx, double zy) {

		Matrix temp = shearingMatrix(xy, xz, yx, yz, zx, zy);
		Matrix temp2 = matrixData;
		matrixData = (temp * temp2).matrixData;
	}

	//TODO: Chaining it Together




















};












