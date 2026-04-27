#include "towers/base_tower.h"
#include "towers/poison_decorator.h"
#include "towers/range_boost_decorator.h"
#include "towers/boss_debuff_decorator.h"
#include <iostream>
#include <cassert>
#include <memory>

void test_decorator_chaining() {
    std::cout << "[1/3] Testing Decorator Chaining...\n";
    auto base = std::make_shared<BaseTower>("FireTower", 20, 3, 100);
    
    assert(base->get_damage() == 20);
    assert(base->get_range() == 3);
    assert(base->describe() == "FireTower");

    auto poisoned = std::make_shared<PoisonDecorator>(base);
    assert(poisoned->get_damage() == 25); // 20 + 5
    assert(poisoned->get_range() == 3);
    assert(poisoned->describe() == "FireTower + Poison");

    auto boosted = std::make_shared<RangeBoostDecorator>(poisoned);
    assert(boosted->get_damage() == 25);
    assert(boosted->get_range() == 5);   // 3 + 2
    assert(boosted->describe() == "FireTower + Poison + RangeBoost");

    std::cout << "  ✅ Chaining PASSED\n\n";
}

void test_boss_debuff_dynamic() {
    std::cout << "[2/3] Testing Boss Debuff Dynamic Wrap...\n";
    auto base = std::make_shared<BaseTower>("ArcticTower", 10, 4, 80);
    
    // Симуляция реакции TowerManager на BossAppearedEvent
    auto boss_wrapped = std::make_shared<BossDebuffDecorator>(base);
    
    assert(boss_wrapped->get_damage() == 20); // 10 * 2
    assert(boss_wrapped->describe() == "ArcticTower [BOSS-DEBUFF]");
    assert(boss_wrapped->get_range() == 4);   // Радиус не меняется
    
    // Исходная башня остаётся неизменной (важно для undo и отладки)
    assert(base->get_damage() == 10);
    
    std::cout << "  ✅ Boss Debuff PASSED\n\n";
}

void test_attack_delegation() {
    std::cout << "[3/3] Testing Attack Delegation...\n";
    auto base = std::make_shared<BaseTower>("LaserTower", 50, 10, 200);
    auto deco = std::make_shared<PoisonDecorator>(base);
    
    // Вызов должен дойти до BaseTower::attack
    deco->attack({5, 2}); 
    std::cout << "  ✅ Delegation PASSED\n\n";
}

int main() {
    test_decorator_chaining();
    test_boss_debuff_dynamic();
    test_attack_delegation();
    std::cout << "🎉 ALL STAGE 2 TESTS PASSED.\n";
    return 0;
}

