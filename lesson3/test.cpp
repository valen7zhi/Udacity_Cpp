#include "test.h"

vector<State> ParseLine(string line)
{
  istringstream sline(line);
  int n;
  char c;
  vector<State> row;
  while (sline >> n >> c && c == ',')
  {
    if (n == 0)
    {
      row.push_back(State::kEmpty);
    }
    else
    {
      row.push_back(State::kObstacle);
    }
  }
  return row;
}

vector<vector<State>> ReadBoardFile(string path)
{
  ifstream myfile(path);
  vector<vector<State>> board{};
  if (myfile)
  {
    string line;
    while (getline(myfile, line))
    {
      vector<State> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}

// Calculate the manhattan distance
int Heuristic(int x1, int y1, int x2, int y2)
{
  return abs(x2 - x1) + abs(y2 - y1);
}

/** 
 * Implementation of A* search algorithm
 */
vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2])
{

  cout << "No path found!"
       << "\n";
  return std::vector<vector<State>>{};
}

string CellString(State cell)
{
  switch (cell)
  {
  case State::kObstacle:
    return "⛰️   ";
  default:
    return "0   ";
  }
}

void PrintBoard(const vector<vector<State>> board)
{
  for (unsigned int i = 0; i < board.size(); i++)
  {
    for (unsigned int j = 0; j < board[i].size(); j++)
    {
      cout << CellString(board[i][j]);
    }
    cout << "\n";
  }
}

void TestHeuristic()
{
  cout << "----------------------------------------------------------"
       << "\n";
  cout << "Heuristic Function Test: ";
  if (Heuristic(1, 2, 3, 4) != 4)
  {
    cout << "failed"
         << "\n";
    cout << "\n"
         << "Heuristic(1, 2, 3, 4) = " << Heuristic(1, 2, 3, 4) << "\n";
    cout << "Correct result: 4"
         << "\n";
    cout << "\n";
  }
  else if (Heuristic(2, -1, 4, -7) != 8)
  {
    cout << "TestHeuristic Failed"
         << "\n";
    cout << "\n"
         << "Heuristic(2, -1, 4, -7) = " << Heuristic(2, -1, 4, -7) << "\n";
    cout << "Correct result: 8"
         << "\n";
    cout << "\n";
  }
  else
  {
    cout << "passed"
         << "\n";
  }
  cout << "----------------------------------------------------------"
       << "\n";
}