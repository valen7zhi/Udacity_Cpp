#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "test.h"

using namespace std;

int main()
{
  int init[2]{0, 0};
  int goal[2]{4, 5};
  auto board = ReadBoardFile("1.board");
  auto solution = Search(board, init, goal);
  PrintBoard(solution);
  // Tests
  TestHeuristic();
}