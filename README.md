# EmptyStringOps
## About

### This is an algorithm that performs recursively operations to make a string empty.

## Example

#### You are given a string "strng"
```
For every alphabet character from 'a' to 'z', remove the first occurrence of that character in "strng" (if it exists).
```

#### Example, let initially strng = "aabcbbca". We do the following operations:
```
Remove the underlined characters strng = "(a)a(b)(c)bbca". The resulting string is strng = "abbca".
Remove the underlined characters strng = "(a)(b)b(c)a". The resulting string is strng = "ba".
Remove the underlined characters strng = "(b)(a)". The resulting string is strng = "".
Return the value of the string strng right before applying the last operation. In the example above, answer is "ba".
```
