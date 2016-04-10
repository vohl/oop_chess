#ifndef CHESS_H
#define CHESS_H

//----------
// includes
//----------
#include <iostring>
#include <vector>
#include <string>

using namespace std;

//-------
// enums
//-------
enum plynum {PLAYER_1, PLAYER_2};

//-----------
// gamepiece
//-----------
class GamePiece{
private:
	int _x;
	int _y;
	plynum _owner;

public:
	GamePiece(int x, int y, int owner);
};

//------
// king
//------
class King : public GamePiece{
private:
	string const _name = "king";
public:
	King(int x, int y, int owner) : GamePiece(x, y, owner);

	bool validMove(int x, int y);
};

//-------
// queen
//-------
class Queen : public GamePiece{
private:
	string const _name = "queen";
public:
	Queen(int x, int y, int owner) : GamePiece(x, y, owner);

	bool validMove(int x, int y);
};

//------
// rook
//------
class Rook : public GamePiece{
private:
	string const _name = "rook";
public:
	Rook(int x, int y, int owner) : GamePiece(x, y, owner);

	bool validMove(int x, int y);
};

//--------
// bishop
//--------
class Bishop : public GamePiece{
private:
	string const _name = "bishop";
public:
	Bishop(int x, int y, int owner) : GamePiece(x, y, owner);

	bool validMove(int x, int y);
};

//--------
// knight
//--------
class Knight : public GamePiece{
private:
	string const _name = "knight";
public:
	Knight(int x, int y, int owner) : GamePiece(x, y, owner);

	bool validMove(int x, int y);
};

//------
// pawn
//------
class Pawn : public GamePiece{
private:
	string const _name = "pawn";
public:
	Pawn(int x, int y, int owner) : GamePiece(x, y, owner);

	bool validMove(int x, int y);
};

//------------
// chessboard
//------------
class ChessBoard{
private:
	const int _width = 8;
	const int _height = 8;
	plynum _player_turn;
	vector<GamePiece *> _board;

public:
	ChessBoard();

	plynum whosTurn();

	void show();

	bool checkWinner();

	bool gameStep(string move);
};

#endif