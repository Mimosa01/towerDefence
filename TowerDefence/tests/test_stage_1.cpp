#include "../src/core/event_bus.h"
#include "../src/core/event.h"
#include "../src/adapters/map_adapter.h"
#include <iostream>
#include <cassert>

void test_event_bus() {
    std::cout << "[1/2] Testing EventBus...\n";
    EventBus bus;
    bool received = false;
    int received_cost = 0;

    bus.subscribe<TowerPlacedEvent>([&](const TowerPlacedEvent& e) {
        received = true;
        received_cost = e.cost;
        std::cout << "  -> Handler called: TowerPlaced at (" 
                  << e.position.x << "," << e.position.y << "), cost=" << e.cost << "\n";
    });

    bus.publish(TowerPlacedEvent{{2, 4}, "FireTower", 150});
    assert(received && "Handler was not called");
    assert(received_cost == 150 && "Payload data mismatch");
    std::cout << "  ✅ EventBus PASSED\n\n";
}

void test_map_adapter() {
    std::cout << "[2/2] Testing MapAdapter...\n";
    ThirdPartyMapGen gen;
    MapAdapter adapter(gen, 5, 4);

    assert(adapter.width() == 5 && adapter.height() == 4);
    auto map = adapter.get_map();
    assert(map.size() == 4);

    // Проверка конвертации по логике мока
    assert(map[0][0] == TileType::Spawn);
    assert(map[3][4] == TileType::Base);
    assert(map[1][3] == TileType::Wall);
    assert(map[2][1] == TileType::Empty);

    std::cout << "  ✅ MapAdapter PASSED\n\n";
}

int main() {
    test_event_bus();
    test_map_adapter();
    std::cout << "🎉 ALL STAGE 1 TESTS PASSED.\n";
    return 0;
}

