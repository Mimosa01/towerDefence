#pragma once 

#include <vector>
#include "../core/types.h"

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
    explicit MapAdapter(ThirdPartyMapGen gen, int w, int h);
    vector<vector<TileType>> get_map() const override { return internal_map_; }
    int width() const override { return w_; }
    int height() const override { return h_; }
}