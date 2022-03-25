#include <command.hpp>

void help(){
    cout << "\nThese are the list of commands and its parameter\n";
    cout << "========================================================\n";
    cout << "- EXPORT PATH : export inventory to PATH\n";
    cout << "- GIVE ITEMNAME ITEMQTY : Give ITEMQTY of ITEMNAME\n";
    cout << "- MOVE SRCID N DESTID1 DESTID2 ... DESTIDN : Moving N items to the N desired destination, divided equally\n"; 
    cout << "- MULTIMOVE SRCID N DESTID : Moving N items to one destination destinatio\n";
    cout << "- CRAFT : Crafting current state of crafting table\n";
    cout << "- MULTICRAFT : Crafting current state of crafting table all the way to non-recipe state\n";
    cout << "- DISCARD SRCID ITEMQTY : Delete ITEMQTY items from SRCID\n";
    cout << "- USE SRCID : Use tool item in SRCID\n";
    cout << "- SHOW : Show current inventory and crafting table\n";
    cout << "========================================================\n";
    cout << "SRCID and DESTID format is collection char concated with slot id, for example I0 for Inventory with slot id 0 as for\n";
    cout << "C10 is crafting table with slot id 10\n\n";
}