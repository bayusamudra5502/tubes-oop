#include <command.hpp>
void doExport(Inventory inventory){
    string outputPath;
    cin >> outputPath;
    ofstream outputFile(outputPath);
    ifstream checkfile(outputPath);
    if(checkfile.good()){
        outputFile << inventory;
        cout << "\nYour inventory has been exported to " << outputPath << "\n\n";
    }
    else{
        throw new WrongCommandException(INVALID_PARAMETER);
    }
}