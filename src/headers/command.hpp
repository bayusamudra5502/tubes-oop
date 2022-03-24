#pragma once
#include <Inventory.hpp>
#include <RecipeBook.hpp>
#include <iostream>
using namespace std;

#define MAX_INVENTORY_COL 9
#define MAX_CRAFT_COL 3

void doDiscard(Inventory&);
void doUse(Inventory&);
void doCraft(CraftingTable&, Inventory&, RecipeBook);
void doMultiCraft(CraftingTable&, Inventory&, RecipeBook);