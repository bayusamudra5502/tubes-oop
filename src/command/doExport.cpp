#include <command.hpp>
void doExport(Inventory inventory){
    string outputPath;
    cin >> outputPath;
    ofstream outputFile(outputPath);
    outputFile << inventory;
}