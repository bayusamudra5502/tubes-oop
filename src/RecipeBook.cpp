#include <RecipeBook.hpp>
#include <exception/NoRecipe.hpp>

RecipeBook::RecipeBook() {}

RecipeBook::RecipeBook(const RecipeBook& r) {
  for (auto i : r.db) {
    this->db.push_back(i);
  }
}

RecipeBook& RecipeBook::operator=(const RecipeBook& r) {
  this->db.clear();
  for (auto i : r.db) {
    this->db.push_back(i);
  }

  return *this;
}

Slot RecipeBook::find(const CraftingTable& ct) const {
  for (auto i : this->db) {
    if (ct == i) {
      return i.getResult();
    }
  }
  return this->toolRepair(ct);
}

Slot RecipeBook::toolRepair(const CraftingTable& ct) const {
  vector<Position> pos;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (ct[{i, j}].get_contents()->getType() == TOOLS) {
        pos.push_back({i, j});
      }
    }
  }
  if ((int)pos.size() == 2) {
    int h1 = dynamic_cast<ToolItem*>(ct[pos[0]].get_contents())->getHealth();
    int h2 = dynamic_cast<ToolItem*>(ct[pos[1]].get_contents())->getHealth();
    Item* t1 = ct[pos[0]].get_contents()->clone();
    Item* t2 = ct[pos[1]].get_contents()->clone();

    ToolItem* tmp = dynamic_cast<ToolItem*>(t1);
    ToolItem* tmp2 = dynamic_cast<ToolItem*>(t2);

    if (tmp->getItemId() == tmp2->getItemId()) {
      tmp->setHealth(min(h1 + h2, 10));
      return (Slot(tmp->getItemId(), new ToolItem(*tmp), 1));
    }
  }
  throw new NoRecipe();
}

void RecipeBook::insert(const Recipe& r) { this->db.push_back(r); }