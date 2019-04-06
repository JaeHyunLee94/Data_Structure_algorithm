#pragma once
class matrix
{
private:
	int width;
	int height;
	int* mat_ptr[];
	

public:
	matrix();
	~matrix();
	int elementAt(int i, int j);
	void replaceElement(int i, int j, int num);
	int width();
	int height();
	void transpose();
	matrix& Add(matrix& A);
	matrix& Subtract(matrix& A);
	matrix& Mult(matrix& A);
	matrix clone();

	
};

