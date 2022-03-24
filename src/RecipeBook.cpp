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

  if (this->isToolRepair(ct)) {
    return this->getRepairedTools(ct);
  }

  throw new NoRecipe();
}

bool RecipeBook::isToolRepair(const CraftingTable& ct) const {
  Item* i = NULL;
  Position pos;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (ct[{i, j}].get_contents()->getType() == TOOLS) {
        i = ct[{i, j}].get_contents()->getType();
        pos = {i, j};
        break;
      }
    }
  }

  if (i) {
    int cnt = 0;

    for (int i = pos.col; i < 3; i++) {
      for (int j = pos.row; j < 3; j++) {
        if (ct[pos].get_contents() == ct[{i, j}].get_contents()) {
          cnt++;
        }
      }
    }

    if (cnt == 1) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

Slot RecipeBook::getRepairedTools(const CraftingTable& ct) const {
  Slot result;
  bool isFound = false;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (ct[{i, j}].get_contents()->getType() == TOOLS) {
        if (!isFound) {
          Slot tmp = ct[{i, j}];
          result = tmp;
          isFound = true;
        } else {
          ToolItem* t1 = dynamic_cast<ToolItem*>(result.get_contents());
          ToolItem* t2 = dynamic_cast<ToolItem*>(ct[{i, j}].get_contents());

          int newHealth = t1->getHealth() + t2->getHealth();
          newHealth = newHealth > 10 ? 10 : newHealth;
          t2->setHealth(newHealth);

          return Slot(result.get_id(), t2);
        }
      }
    }
  }

  throw new NoRecipe();
}

void RecipeBook::insert(const Recipe& r) { this->db.push_back(r); }