#pragma once

#include <vector>

using namespace std;

// 0 - пусто, 1 - стена, 2 - спавн, 3 - база
class ThirdPartyMapGen {
  public:
    vector<vector<int>> build_grid(int width, int height) const {
      vector<vector<int>> grid(height, vector<int>(width, 0));

      if (width > 0 && height > 0) {
        grid[0][0] = 2;
        grid[height-1][width-1] = 3;
        for (int i = 2; i < width; ++i) {
          grid[1][i] = 1;
        }
      }
      return grid;
    }
};