#include "functions.hpp"

#include <iostream>

void PrintBoard(const std::vector<std::vector<char>>& board) {
  for (unsigned int i = 0; i < kBoardSize; ++i) {
    for (unsigned int j = 0; j < kBoardSize; ++j) {
      std::cout << board[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

void InitializeBoard(std::vector<std::vector<char>>& board) {
  board.clear();
  for (unsigned int i = 0; i < kBoardSize; ++i) {
    board.push_back(std::vector<char>(kBoardSize, ' '));
  }
}

bool MakeMove(std::vector<std::vector<char>>& board,
              int row,
              int col,
              char player) {
  if (row < 0 || row >= kBoardSize || col < 0 || col >= kBoardSize) {
    std::cerr << "Error: Move out of bounds!\n";
    return false;
  }
  if (board[row][col] != ' ') {
    std::cerr << "Error: Cell already occupied!\n";
    return false;
  }
  board[row][col] = player;
  return true;
}

char CheckWinner(const std::vector<std::vector<char>>& board) {
  for (unsigned int i = 0; i < kBoardSize; ++i) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] &&
        board[i][0] != ' ') {
      return board[i][0];
    }
  }

  for (unsigned int i = 0; i < kBoardSize; ++i) {
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] &&
        board[0][i] != ' ') {
      return board[0][i];
    }
  }

  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] &&
      board[2][2] != ' ') {
    return board[0][0];
  }

  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] &&
      board[0][2] != ' ') {
    return board[0][2];
  }
  return ' ';
}

bool IsBoardFull(const std::vector<std::vector<char>>& board) {
  for (unsigned int i = 0; i < kBoardSize; ++i) {
    for (unsigned int j = 0; j < kBoardSize; ++j) {
      if (board[i][j] == ' ') {
        return false;
      }
    }
  }
  return true;
}

void SwitchPlayer(char& player) { player = (player == 'X') ? 'O' : 'X'; }