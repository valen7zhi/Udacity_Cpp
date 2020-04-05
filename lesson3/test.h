#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

enum class State
{
    kEmpty,
    kObstacle
};

vector<State> ParseLine(string line);

void TestHeuristic();

vector<vector<State>> ReadBoardFile(string path);

int Heuristic(int x1, int y1, int x2, int y2);

vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]);

string CellString(State cell);

void PrintBoard(const vector<vector<State>> board);