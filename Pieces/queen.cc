#include "queen.h"
#include <cmath>
using namespace std;

bool Queen::IsLegal(Pos newPos, vector <vector<Piece*>>* pieces) {  //Assuming newPos is either empty or enemy
  int arow = abs(newPos.row - Pos.row);
  int acol = abs(newPos.col - Pos.col);
  if (arow == acol) {
    if(Pos.row < newPos.row) {    
      if(Pos.col < newPos.col) {   //moving right-bottom
        for(int i = Pos.row + 1, int y = Pos.col + 1; (i < newPos.row) && (y < newPos.col); ++i, ++y) {
          if(pieces[i][y] != nullptr) {
            return false;
          }
        }
        return true;
      } else if(Pos.col > newPos.col) {   //moving left-bottom
        for(int i = Pos.row + 1, int y = Pos.col - 1; (i < newPos.row) && (y > newPos.col); ++i, --y) {
          if(pieces[i][y] != nullptr) {
            return false;
          }
        }
        return true;
      }
    } else if(Pos.row > newPos.row) {
      if(Pos.col < newPos.col) {   //moving right-top
        for(int i = Pos.row - 1, int y = Pos.col + 1; (i > newPos.row) && (y < newPos.col); --i, ++y) {
          if(pieces[i][y] != nullptr) {
            return false;
          }
        }
        return true;
      } else if(Pos.col > newPos.col) {   //moving left-top
        for(int i = Pos.row - 1, int y = Pos.col - 1; (i > newPos.row) && (y > newPos.col); --i, --y) {
          if(pieces[i][y] != nullptr) {
            return false;
          }
        }
        return true;
      }
    }
  } else if(Pos.row == newPos.row) {    //moving horizontally
    if(Pos.col < newPos.col) {   //to right
      for(int i = Pos.col + 1; i < newPos.col; ++i) {
        if(pieces[Pos.row][i] != nullptr) {
          return false;
        }
      }
      return true;
    } else if(Pos.col > newPos.col) {  //to left
      for(int i = Pos.col - 1; i > newPos.col; --i) {
        if(pieces[Pos.row][i] != nullptr) {
          return false;
        }
      }
      return true;
    }
  } else if(Pos.col == newPos.col) { //moving vertically
    if(Pos.row < newPos.row) {   //to down
      for(int i = Pos.row + 1; i < newPos.row; ++i) {
        if(pieces[i][Pos.col] != nullptr) {
          return false;
        }
      }
      return true;
    } else if(Pos.row > newPos.row) {   //to up
      for(int i = Pos.row - 1; i > newPos.row; --i) {
        if(pieces[i][Pos.col] != nullptr) {
          return false;
        }
      }
      return true;
    }
  } else {
    return false;
  }
}

vector<Pos> Bishop::getPossibleMoves(vector <vector<Piece*>>* pieces) { //We need to check destination cell if it's empty or enemy
    vector<Pos> vec = nullptr;

    for(int i = Pos.col + 1; i <= 7; ++i) { //check right
    if(((pieces[Pos.row][i] == nullptr) || (pieces[Pos.row][i].getColor() != color)) &&  //destionation cell condition
       (IsLegal({Pos.row, i}, vector <vector<Piece*>>* pieces) == true)) {
      vec.push_back = {i,Pos.col};
    } else {
      break;
    }
  }

  for(int i = Pos.col - 1; i >= 0; --i) { //check left
    if(((pieces[Pos.row][i] == nullptr) || (pieces[Pos.row][i].getColor != color)) &&  //destionation cell condition
       (IsLegal({Pos.row, i}, vector <vector<Piece*>>* pieces) == true)) {
      vec.push_back = {i,Pos.col};
    } else {
      break;
    }
  }

  for(int i = Pos.row + 1; i <= 7; ++i) { //check bottom
    if(((pieces[i][Pos.col] == nullptr) || (pieces[i][Pos.col].getColor != color)) &&  //destionation cell condition
       (IsLegal({i, Pos.col}, vector <vector<Piece*>>* pieces) == true)) {
      vec.push_back = {i, Pos.col};
    } else {
      break;
    }
  }

  for(int i = Pos.row - 1; i >= 0; --i) { //check top
    if(((pieces[i][Pos.col] == nullptr) || (pieces[i][Pos.col].getColor != color)) &&  //destionation cell condition
       (IsLegal({i, Pos.col}, vector <vector<Piece*>>* pieces) == true)) {
      vec.push_back = {i, Pos.col};
    } else {
      break;
    }
  }

  for(int i = Pos.row + 1, int y = Pos.col + 1; (i <= 7) && (y <= 7); ++i, ++y) { //check right-bottom
    if(((pieces[i][y] == nullptr) || (pieces[i][y].color != color)) &&  //destionation cell condition
       (IsLegal({i, y}, vector <vector<Piece*>>* pieces) == true)) {
      vec.push_back = {i,y};
    } else {
      break;
    }
  }
  
  for(int i = Pos.row + 1, int y = Pos.col - 1; (i <= 7) && (y >= 0); ++i, --y) { //check left-bottom
    if(((pieces[i][y] == nullptr) || (pieces[i][y].getColor != color)) &&  //destionation cell condition
       (IsLegal({i, y}, vector <vector<Piece*>>* pieces) == true)) {
      vec.push_back = {i,y};
    } else {
      break;
    }
  }
  
  for(int i = Pos.row - 1, int y = Pos.col + 1; (i >= 0) && (y <= 7); --i, ++y) { //check right-top
    if(((pieces[i][y] == nullptr) || (pieces[i][y].getColor != color)) &&  //destionation cell condition
       (IsLegal({i, y}, vector <vector<Piece*>>* pieces) == true)) {
      vec.push_back = {i,y};
    } else {
      break;
    }
  }
  
  for(int i = Pos.row - 1, int y = Pos.col - 1; (i >= 0) && (y >= 0); --i, --y) { //check left-top
    if(((pieces[i][y] == nullptr) || (pieces[i][y].getColor != color)) &&  //destionation cell condition
       (IsLegal({i, y}, vector <vector<Piece*>>* pieces) == true)) {
      vec.push_back = {i,y};
    } else {
      break;
    }
  }

  return vec;
}

Queen:Queen(Color c, Pos Pos, bool hasMoved = false, bool enPassant = false): Piece(c , Pos) {}
