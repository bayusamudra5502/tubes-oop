#include <command.hpp>
void doExport(Inventory inventory) {
  string outputPath;
  cin >> outputPath;
  ofstream outputFile(outputPath);
  ifstream checkfile(outputPath);
  if (checkfile.good()) {
    outputFile << inventory;
    cout << "\nYour inventory has been exported to \x1B[32m" << outputPath
         << "\x1B[0m\n\n";
  } else {
    throw new WrongCommandException(INVALID_PARAMETER);
  }
}