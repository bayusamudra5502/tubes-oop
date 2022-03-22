#include <CraftingTable.hpp>
#include <Recipe.hpp>

bool operator==(const CraftingTable& ct, const Recipe& r) { return true; }

bool operator==(const Recipe& r, const CraftingTable& ct) { return true; }