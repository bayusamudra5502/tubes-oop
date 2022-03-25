#include <command.hpp>

void doMove(Inventory& inventory, CraftingTable& craftingTable){
    string src;
    int N;
    cin >> src >> N;
    if(N<=0 || (src[0]!='I'&&src[0]!='C')){
        throw new WrongCommandException(INVALID_PARAMETER);
    }
    vector<string> dest(N);
    for(int i=0; i<N; i++){
        cin >> dest[i];
    }
    if (src[0] == 'I') {
        inventory.moveItem(src, N, dest, &craftingTable);
    } else {
        craftingTable.moveItem(src, N, dest, &inventory);
    }
    cout << "\nYou successfully moved " << N << " item(s).\n\n";
}