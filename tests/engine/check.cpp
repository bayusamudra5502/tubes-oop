// checker file
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#define TEST_PATH "./tests/test_case"
#define ACTUAL_ANS_PATH "./tests/outputs/"

using namespace std;

int main() {
  int correct = 0, total = 0, skipped = 0;

  for (const auto &entry : filesystem::directory_iterator(TEST_PATH)) {
    string filename = entry.path().filename().string();
    if (filename.size() >= 3 && filename.substr(filename.size() - 3) == "ans" &&
        filename.substr(0, 8) != "DISABLE_") {
      total++;
      ifstream answerFile(entry.path());
      string answerPath =
          ACTUAL_ANS_PATH + entry.path().stem().string() + ".out";
      ifstream outputFile(answerPath);
      string answer, output;
      bool same = true;
      while (getline(answerFile, answer) && getline(outputFile, output)) {
        answer.erase(answer.find_last_not_of(" \n\r\t") + 1);
        output.erase(output.find_last_not_of(" \n\r\t") + 1);
        if (answer != output) {
          same = false;
        }
      }
      if (same && !getline(answerFile, answer) &&
          !getline(outputFile, output)) {
        correct++;
        cout << "\x1B[32mTest " << filename << " passed.\x1B[0m" << endl;
      } else {
        cout << "\x1B[31mTest " << filename << " failed.\x1B[0m" << endl;
      }
    } else if (filename.substr(0, 8) == "DISABLE_" &&
               filename.substr(filename.size() - 3) == "ans") {
      cout << "\x1B[33mTest " << filename << " skipped.\x1B[0m" << endl;
      skipped++;
      total++;
    }
  }

  cout << endl;
  cout << correct << " out of " << total << " tests passed." << endl;
  if (skipped > 0) {
    cout << skipped << " tests are skipped" << endl;
  }

  return correct == total ? 0 : total - skipped - correct;
}
