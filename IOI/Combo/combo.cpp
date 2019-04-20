#include "combo.h"
#include <bits/stdc++.h>
using namespace std;

string guess_sequence(int N) {
  string S = "";
  if (press("AB")) {
      if (press("A"))
          S += "A";
      else
          S += "B";
  }
  else {
      if (press("X"))
          S += "X";
      else
          S += "Y";
  }
  vector<char> rem = {'A', 'B', 'X', 'Y'};
  for (int i = 0; i < rem.size(); i++) {
      if (rem[i] == S[0]) {
          rem.erase(rem.begin() + i);
          break;
      }
  }
  for (int i = 1; i < N - 1; i++) {
      string P = S + rem[0] + S + rem[1] + rem[0] + S + rem[1] + rem[2] + S + rem[1] + rem[1];
      int coins = press(P);
      if (coins == S.size())
          S += rem[2];
      else if (coins == S.size() + 1)
          S += rem[0];
      else
          S += rem[1];
  }
  if (N > 1) {
      if (press(S + rem[0]) > S.size())
          S += rem[0];
      else if (press(S + rem[1]) > S.size())
          S += rem[1];
      else
          S += rem[2];
  }
  return S;
}
