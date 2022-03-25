#include <cstring>
#include <util.hpp>

string toUpperCase(const string& str) {
  string result;

  for (char i : str) {
    result.push_back(toupper(i));
  }

  return result;
}