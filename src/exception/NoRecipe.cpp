#include <exception/NoRecipe.hpp>

NoRecipe::NoRecipe() : BaseException("NoRecipe") {}

ostream& NoRecipe::printError(ostream& os) {
  os << "No Recipe is found";
  return os;
}
