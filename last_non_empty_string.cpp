#include <string>
#include <vector>
#include <limits>

std::string last_non_empty_string(const std::string& str)
{
  // Store the number of times that a letter has occured
  std::vector<int> occurrence(26, 0);
  // Store the index of the last time that a letter has occured
  std::vector<int> lastOccurrence(26, -1);

  for (size_t i = 0; i < str.size(); ++i) {
    occurrence[str[i] - 'a']++;
    lastOccurrence[str[i] - 'a'] = i;
  }

  // Here we want to find the max(occurrence) so that we can know which letters should we return
  int max = occurrence[0];
  for (int i = 1; i < 26; ++i) {
    if (max < occurrence[i]) {
      max = occurrence[i];
    }
  }

  // And here we want to find the min(lastOccurrence) so that we can order the letters correctly later
  // Also we store in a string the characters that we want to order later
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

  // And last but not least we order the characters and update the min in every insertion
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

// Note: It can be also done in a nested loop but it would be very time consuming, still
// i'm pretty it can be done also a lot more effectively, especially in terms of memory space.
