#pragma once 

#include <vector>
#include "../core/types.h"
#include "third_party_map_gen_mock.h"

using namespace std;

class IMapProvider {
  public:
    virtual ~IMapProvider() = default;
    virtual vector<vector<TileType>> get_map() const = 0;
    virtual int width() const = 0;
    virtual int height() const = 0;
};

class MapAdapter : public IMapProvider {
  private:
    int w_;
    int h_;
    vector<vector<TileType>> internal_map_;

  public:
    explicit MapAdapter(ThirdPartyMapGen gen, int w, int h) : w_(w), h_(h) {
      const auto raw_grid = gen.build_grid(w_, h_);
      internal_map_.assign(h_, vector<TileType>(w_, TileType::Empty));

      for (int y = 0; y < h_; ++y) {
        for (int x = 0; x < w_; ++x) {
          switch (raw_grid[y][x]) {
            case 1:
              internal_map_[y][x] = TileType::Wall;
              break;
            case 2:
              internal_map_[y][x] = TileType::Spawn;
              break;
            case 3:
              internal_map_[y][x] = TileType::Base;
              break;
            default:
              internal_map_[y][x] = TileType::Empty;
              break;
          }
        }
      }
    }
    vector<vector<TileType>> get_map() const override { return internal_map_; }
    int width() const override { return w_; }
    int height() const override { return h_; }
};