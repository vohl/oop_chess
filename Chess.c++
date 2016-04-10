#include <iostring>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstdlib>

using namespace std;

GamePiece::GamePiece(int x, int y, int owner) : _x(x), _y(y){
	switch (owner){
		case 1:
			_owner = PLAYER_1;
			break;
		case 2:
			_owner = PLAYER_2;
			break;
		default:
			throw invalid_argument("invalid_argument for owner");
	}
}

bool King::validMove(int x, int y, GamePiece * object){
	if (_x == x && _y == y){
		return false;
	}
	else if(object != nullptr){
		if(object->_owner == this->_owner){
			return false;
		}
	}
	else if (x >= _x-1 && x <= _x+1 && y <= _y+1 && y >=_y-1){
		return true;
	}
	return false;
}

bool Queen::validMove(int x, int y){
	if (_x == x && _y == y){
		return false;
	}
	else if(object != nullptr){
		if(object->_owner == this->_owner){
			return false;
		}
	}
	else if (_x == x){
		return true;
	}
	else if (_y == y){
		return true;
	}
	else if (abs(_x-x) == abs(_y-y)){
		return true;
	}
	return false;
}

bool Rook::validMove(int x, int y){
	if (_x == x && _y == y){
		return false;
	}
	else if(object != nullptr){
		if(object->_owner == this->_owner){
			return false;
		}
	}
	else if(_x == x){
		return true;
	}
	else if(_y == y){
		return true;
	}
	return false;
}

bool Bishop::validMove(int x, int y){
	if (_x == x && _y == y){
		return false;
	}
	else if(object != nullptr){
		if(object->_owner == this->_owner){
			return false;
		}
	}
	else if(abs(_x-x) == abs(_y-y)){
		return true;
	}
	return false;
}

bool Knight::validMove(int x, int y){
	if (_x == x && _y == y){
		return false;
	}
	else if(object != nullptr){
		if(object->_owner == this->_owner){
			return false;
		}
	}
	else if (abs(_x-x) == 3 && abs(_y-y) == 2){
		return true;
	}
	else if (abs(_x-x) == 2 && abs(_y-y) == 3){
		return true;
	}
	return false;
}

bool Pawn::validMove(int x, int y){
	if (_x == x && _y == y){
		return false;
	}
	else if(object != nullptr){
		if(object->_owner == this->_owner){
			return false;
		}
		else if(this->_owner == PLAYER_1 && _y+1 == y && (_x+1 == x || _x-1 == x)){
			return true;
		}
		else if(this->_owner == PLAYER_2 && _y-1 == y && (_x+1 == x || _x-1 == x)){
			return true;
		}
	}
	else if(this->_has_moved){
		else if(this->_owner == PLAYER_1 && _y+1 == y && _x == x){
			return true;
		}
		else if(this->_owner == PLAYER_2 && _y-1 == y && _x == x){
			return true;
		}
	}
	else{
		else if(this->_owner == PLAYER_1 && _y+2 == y && _x == x){
			return true;
		}
		else if(this->_owner == PLAYER_2 && _y-2 == y && _x == x){
			return true;
		}
	}
	return false;
}

ChessBoard::ChessBoard() : _player_turn(PLAYER_1){
	//index starts at 1 for position just to make the game of chess sound better
	//for example if i get the command "a1 to b2"
	//that's going to be the piece at x=1 and y=1
	//but inside the vector board that will be the piece at indies 2
	_board.push_back(Rook(1, 1, PLAYER_1));
	_board.push_back(Knight(2, 1, PLAYER_1));
	_board.push_back(Bishop(3, 1, PLAYER_1));
	_board.push_back(Queen(4, 1, PLAYER_1));
	_board.push_back(King(5, 1, PLAYER_1));
	_board.push_back(Bishop(6, 1, PLAYER_1));
	_board.push_back(Knight(7, 1, PLAYER_1));
	_board.push_back(Rook(8, 1, PLAYER_1));
	for(int i=1; i <= 8; ++i){
		_board.push_back(Pawn(i ,2 ,PLAYER_1));
	}
	for(int i=1; i <= 32; ++i){
		_board.push_back(nullptr);
	}
	for(int i=1; i <= 8; ++i){
		_board.push_back(Pawn(i ,7 ,PLAYER_2));
	}
	_board.push_back(Rook(1, 8, PLAYER_2));
	_board.push_back(Knight(2, 8, PLAYER_2));
	_board.push_back(Bishop(3, 8, PLAYER_2));
	_board.push_back(Queen(4, 8, PLAYER_2));
	_board.push_back(King(5, 8, PLAYER_2));
	_board.push_back(Bishop(6, 8, PLAYER_2));
	_board.push_back(Knight(7, 8, PLAYER_2));
	_board.push_back(Rook(8, 8, PLAYER_2));
}

playnum ChessBoard::whosTurn(){
	return _player_turn;
}

bool ChessBoard::gameStep(string cmd){
	//This is psuedocode to account for time constraints
	//expecting the cmd to be formatted in such a style
	//b4 to e6
	//the char represent the x position of the board a-h
	//where a is x=1 and h is h=8
	//the second number is y, 1-8
	//and the first pair is the location you are moving from
	//second pair is the location you are mocing too
	if(firstpair.x < 1 or > 1) throw error
	if(firstpair.y < 1 or > 1) throw error
	if(secondpair.x < 1 or > 1) throw error
	if(secondpair.y < 1 or > 1) throw error
	//we have a valed command for the board if the piece at
	//the first pair is == to who's turn it is
	if(_board.at((firstpair.x-1) + (firstpair.y-1)*_width) != nullptr)
		and if(_board.at((firstpair.x-1) + (firstpair.y-1)*_width) == whosTurn() && (_board.at((firstpair.x-1) + (firstpair.y-1)*_width)).validMove(secondpair.x, secondpair.y, &(_board.at(secondpairs location))))
				update the _board as follows

}
