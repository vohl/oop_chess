#include <iostring>
#include <vector>
#include <string>
#include <stdexcept>

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


