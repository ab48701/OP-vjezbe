#include <iostream>
#include <iomanip>


using namespace std;

typedef struct Point {
public:
	double x, y;


	Point(double x1, double y1) :x(x1), y(y1) {};

}Point;



class Board 
{
	char** frame;
	int row, col;
public:
	Board() = default;//default constructor

	Board(int row1, int col1) {// constructor  with arguments
		row = row1; col = col1;
		frame = new char* [row];
		for (int i = 0; i < row; i++)
			frame[i] = new char[col];
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
			{
				if (i == 0 || i == row - 1 || j == 0 || j == col - 1)
					frame[i][j] = 'o';
				else
					frame[i][j] = ' ';
			}
	};

	Board(Board& B) {//copy constructor
		col = B.col; row = B.row;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				frame[i][j] = B.frame[i][j];
	}

	Board(Board&& B) { //move constructor
		col = B.col; row = B.row;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				frame[i][j] = B.frame[i][j];
		B.frame = nullptr;
		B.col = 0;
		B.row = 0;
	}
	~Board(); // deconstructor

	void draw_char(Point P, char ch);
	void draw_up_line(Point P, Point P1, char ch);
	void draw_line(Point P, Point P1, char ch);
	void display();
};





Board::~Board() {//deconstructor
	for (int i = 0; i < row; i++)
		delete[] frame[i];
	delete[] frame;

}

void Board::draw_char(Point p, char ch)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (j == p.x && i == p.y)
				frame[i][j] = ch;
}

void Board::draw_line(Point p1, Point p2, char ch)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (max(p1.x, p2.x) >= j && min(p1.x, p2.x) <= j && i == max(p1.y, p2.y))
				frame[i][j] = ch;
}

void Board::draw_up_line(Point p1, Point p2, char ch)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (i == j && j >= min(p1.x, p2.x) && i <= max(p1.y, p2.y))
				frame[i][j] = ch;
}

void Board::display()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << frame[i][j];
		cout << endl;
	}
}

int main()
{
	Point p1(2, 8), p2(16, 8), p3(2, 2), p4(8, 8);
	Board b(10, 20);
	b.draw_line(p1, p2, 'x');
	b.draw_up_line(p3, p4, 'x');
	b.display();
}