#include <string>
#include <vector>
#include <limits>

std::string last_non_empty_string(const std::string& str)
{
  std::vector<int> occurrence(26, 0);
  std::vector<int> lastOccurrence(26, -1);
  for (size_t i = 0; i < str.size(); ++i) {
    occurrence[str[i] - 'a']++;
    lastOccurrence[str[i] - 'a'] = i;
  }

  int max = occurrence[0];
  for (int i = 1; i < 26; ++i) {
    if (max < occurrence[i]) {
      max = occurrence[i];
    }
  }

  int min = std::numeric_limits<int>::max();
  std::string new_strUnordered = "";
  for (size_t i = 0; i < 26; ++i) {
    if (occurrence[i] == max) {
      if (lastOccurrence[i] != -1 && min > lastOccurrence[i]) {
        min = lastOccurrence[i];
      }
      int asciiValue = i + 97;
      new_strUnordered += static_cast<char>(asciiValue);
    } else {lastOccurrence[i] = -1;}
  }

  std::string new_str = "";
  for (size_t j = 0; j < new_strUnordered.size(); ++j) {
    for (size_t i = 0; i < new_strUnordered.size(); ++i) {
      if (lastOccurrence[new_strUnordered[i] - 'a'] != -1 && lastOccurrence[new_strUnordered[i] - 'a'] == min) {
        min = std::numeric_limits<int>::max();
        lastOccurrence[new_strUnordered[i] - 'a'] = -1;
        new_str += new_strUnordered[i];
        for (int i = 0; i < 26; ++i) {
          if (lastOccurrence[i] != -1 && lastOccurrence[i] < min) {min = lastOccurrence[i];}
        }
      }
    }
  }

  return new_str;
}
