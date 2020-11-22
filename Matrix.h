#pragma once

class Matrix
{
private:
	int** mas;
	int col{ 0 };
	int row{ 0 };
public:
	Matrix(int col, int row)
	{
		this->mas = new int* [row];
		for (int i(0); i < row; i++)
			this->mas[i] = new int[col];
		this->col = col;
		this->row = row;
	}

	Matrix(int* mas, int col, int row)
	{
		this->mas = new int* [row];
		for (int i(0); i < row; i++)
			this->mas[i] = new int[col];

		int size(0);
		for (int x(0); x < row; x++)
		{
			for (int y(0); y < col; y++)
			{
				this->mas[x][y] = mas[size];
				size++;
				
			}
		
		}

		this->col = col;
		this->row = row;
	}

	~Matrix()
	{
		for (int x(0); x < row; x++)
			delete[] mas[x];
	}

	void Set(int x, int y, int element)
	{
		this->mas[x][y] = element;
	}

	int GetCol()
	{
		return this->col;
	}

	int GetRow()
	{
		return this->row;
	}

	int GetSize()
	{
		return this->col * this->row;
	}

	int Get(int x, int y)
	{
		return this->mas[x][y];
	}

	void Print()
	{
		for (int x(0); x < row; x++)
		{
			for (int y(0); y < col; y++)
				std::cout << this->mas[x][y] << " ";
			std::cout << " " << std::endl;
		}
	}
};

