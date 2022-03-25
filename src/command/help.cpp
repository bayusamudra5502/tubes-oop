#include <command.hpp>

void help() {
  cout << "\nThese are the list of commands and its parameter\n";
  cout << "========================================================\n";
  cout << "- \x1B[36mEXPORT \x1B[33mPATH\x1B[0m : export inventory to PATH\n";
  cout << "- \x1B[36mGIVE \x1B[33mITEMNAME ITEMQTY\x1B[0m : Give ITEMQTY of "
          "ITEMNAME\n";
  cout << "- \x1B[36mMOVE \x1B[33mSRCID N DESTID1 DESTID2 ... DESTIDN\x1B[0m : "
          "Moving "
          "N items to the N desired destination, divided equally\n";
  cout << "- \x1B[36mMULTIMOVE \x1B[33mSRCID N DESTID\x1B[0m : "
          "Moving N "
          "items to one desired destination\n";
  cout << "- \x1B[36mCRAFT\x1B[0m : Crafting current state of crafting table\n";
  cout << "- \x1B[36mMULTICRAFT\x1B[0m : Crafting current state of crafting "
          "table all the way to non-recipe state\n";
  cout << "- \x1B[36mDISCARD \x1B[33mSRCID ITEMQTY\x1B[0m : Delete ITEMQTY "
          "items from "
          "SRCID\n";
  cout << "- \x1B[36mUSE \x1B[33mSRCID\x1B[0m : Use tool item in SRCID\n";
  cout << "- \x1B[36mSHOW\x1B[0m : Show current inventory and crafting table\n";
  cout << "========================================================\n";
  cout << "SRCID and DESTID format is collection char concated with slot id, "
          "for example I0 for Inventory with slot id 0 as for\n";
  cout << "C10 is crafting table with slot id 10\n\n";
}