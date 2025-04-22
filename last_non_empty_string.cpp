#include <string>
#include <vector>
#include <limits>

std::string last_non_empty_string(const std::string& str)
{
  // Store the number of times that a letter has occured
  std::vector<int> occurrence(26, 0);
  // Store the index of the last time that a letter has occured
  std::vector<int> lastOccurrence(26, -1);

  // Populate occurrence and lastOccurrence arrays
  for (size_t i = 0; i < str.size(); ++i) {
    occurrence[str[i] - 'a']++;
    lastOccurrence[str[i] - 'a'] = i;
  }

  // Find the maximum occurrence count among all characters
  int max = occurrence[0];
  for (int i = 1; i < 26; ++i) {
    if (max < occurrence[i]) {
      max = occurrence[i];
    }
  }

  // Build a temporary string with characters that have the maximum occurrence
  // and find the smallest lastOccurrence index among them
  int min = std::numeric_limits<int>::max();
  std::string new_strUnordered = "";
  for (size_t i = 0; i < 26; ++i) {
    if (occurrence[i] == max) {
      // Track the earliest last occurrence among characters with max frequency
      if (lastOccurrence[i] != -1 && min > lastOccurrence[i]) {
        min = lastOccurrence[i];
      }

      // Convert index to character and add to temporary string
      int asciiValue = i + 97;
      new_strUnordered += static_cast<char>(asciiValue);
    } else {
      // Invalidate characters that are not max frequency
      lastOccurrence[i] = -1;
    }
  }

  // Sort characters in new_strUnordered based on their last occurrence in input string
  std::string new_str = "";
  for (size_t j = 0; j < new_strUnordered.size(); ++j) {
    for (size_t i = 0; i < new_strUnordered.size(); ++i) {
      // If the current character has the earliest remaining last occurrence
      if (lastOccurrence[new_strUnordered[i] - 'a'] != -1 && lastOccurrence[new_strUnordered[i] - 'a'] == min) {
        // Find the next smallest lastOccurrence for the remaining characters
        min = std::numeric_limits<int>::max();

        // Invalidate this character so it doesn't get used again
        lastOccurrence[new_strUnordered[i] - 'a'] = -1;

        // Append it to the result string
        new_str += new_strUnordered[i];
        for (int i = 0; i < 26; ++i) {
          if (lastOccurrence[i] != -1 && lastOccurrence[i] < min) {min = lastOccurrence[i];}
        }
      }
    }
  }

  return new_str;
}

// Note: This could have been implemented more directly using a nested for-loop,
// but that approach would result in O(n^2) time complexity. 
// Instead, this version achieves linear time complexity O(n).
