// Given a string, return the string 
// with the order of the space-separated words reversed

// Technique: Stack
// Approach: Use a stack to store each word in the string
// Only push to the stack when a space is encountered, from a placeholder string
// When the end of the string is reached, push the placeholder string to the stack
// Pop from the stack and append to the result string
// Return the result string


// Time complexity: O(n)
// Space complexity: O(n)
// Time taken: 20 minutes

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reverseWords(string& input)
{
    stack<string> words;
    string res = "";

    for (int i = 0; i < input.length(); i++) {

        // if a space is encountered, push the placeholder string to the stack
        // and reset the placeholder string
        if (input[i] == ' ') {
            words.push(res);
            res = "";
        }
        else {
        // otherwise, add the current character to the placeholder string
            res += input[i];
        }
    }
    // push the last word to the stack
    words.push(res);
    res = "";
    
    // reverse the order of the words by popping from the stack
    while (!words.empty()) {
        res += words.top();
        res += " ";
        words.pop();
    }
    return res;
}

int main()
{
    string input = "Uber Career Prep";
    cout << reverseWords(input) << endl;
    // outputs "Prep Career Uber"

    string input2 = "Emma lives in Brooklyn, New York.";
    cout << reverseWords(input2) << endl;
    // outputs "York. New Brooklyn, in lives Emma"

}