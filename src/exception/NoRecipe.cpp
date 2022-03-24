#include <exception/NoRecipe.hpp>

NoRecipe::NoRecipe() : BaseException("NoRecipe") {}

string NoRecipe::what(){
  return "No Recipe is found";
}
