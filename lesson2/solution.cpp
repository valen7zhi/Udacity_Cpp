#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

vector<int> ParseLine(string line)
{
  istringstream sline(line);
  int n;
  char c;
  vector<int> row;
  while (sline >> n >> c && c == ',')
  {
    row.push_back(n);
  }
  return row;
}

vector<vector<int>> ReadBoardFile(string path)
{
  ifstream myfile(path);
  vector<vector<int>> board{};
  if (myfile)
  {
    string line;
    while (getline(myfile, line))
    {
      vector<int> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}

void PrintBoard(const vector<vector<int>> board)
{

  for (auto i : board)
  {
    for (auto j : i)
    {
      cout << i[j];
    }
    cout << "\n";
  }
}

int main()
{
  auto board = ReadBoardFile("1.board");
  PrintBoard(board);
}