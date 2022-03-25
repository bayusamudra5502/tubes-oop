#pragma once
#include <Inventory.hpp>
#include <RecipeBook.hpp>
#include <iostream>
#include <exception/WrongCommandException.hpp>
using namespace std;

#define MAX_INVENTORY_COL 9
#define MAX_CRAFT_COL 3

void doDiscard(Inventory&);
void doUse(Inventory&);
void doCraft(CraftingTable&, Inventory&, RecipeBook);
void doMultiMove(CraftingTable&, Inventory&);
void doMultiCraft(CraftingTable&, Inventory&, RecipeBook);
void doExport(Inventory inventory);
void doShow(Inventory inventory, CraftingTable craftingTable);
void doGive(Inventory& inventory, Map<string, Item*> items);
void doMove(Inventory& inventory, CraftingTable& craftingTable);
void help();