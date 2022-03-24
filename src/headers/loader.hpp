#pragma once

#include <Item.hpp>
#include <Map.hpp>
#include <NonToolItem.hpp>
#include <ToolItem.hpp>
#include <fstream>
#include <sstream>
using namespace std;

void loadItem(Map<string, Item *> &items);
void loadRecipe(Map<string, Item *> items, RecipeBook &recipes);
