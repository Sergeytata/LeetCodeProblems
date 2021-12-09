#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


// Problem Description
// Given a string s, find the length of the longest substring without repeating characters.

// can we do this from a single pass??
// iterate thourh char and count if they dont exist. You map for verification and string for recording, start from the id with the last repeat
// 1) Iterate through the string character by character
// 2) Chech each character with the map if this character has alredy been added. if character is not there add it to the map and go to step 3)
// If character is inside the map go to 5)
// 3) Record the charater idx in the string
// 4) Append the element to the sequence. Record the length of the sequence, compare it to the the current max. If it is larget than current max, update hte current largest one
// 5) Set start of the new subsequence to the id + 1 where id is received received from the idx table using character as a key.

int lengthOfLongestSubstring(string s) {
        map <char, int> charId;
        int maxLength = 0;
        int minId = 0;

        for (int i = 0; i < s.length() ; i++){
            char ch = s[i];
            // check if character is in the string 
            // cout << (!charId.count(ch) || charId[ch] < minId ) << endl;
            // cout << (charId[ch] < minId || !charId.count(ch)) << endl;
            if((!charId.count(ch) || charId[ch] < minId )){
                charId[ch] = i; // record character id in the original string
                // cout << ch << " added to map" << endl;
                maxLength = max(maxLength, i - minId + 1); // update max Length
                // cout << "minId: " << minId << " maxLength: " << maxLength << " i: " << i << endl;
                
            }
            else{
                // cout << "Character " << ch << " is already in the substring" << endl;
                // is repeated => cut substring
                minId = max(charId[ch] + 1, minId); // new min id
                // cout << "minId: " << minId << endl;
                // reset all previous characters
                // cout << ch << " appeared at " << charId[ch] << " minId: " << minId << endl;
                // for(int j = 0; j < charId[ch]; j++){
                //     subStringChars[s[j]] = false;
                // }
                charId[ch] = i; // update to char id

                // cout << "new " << ch << " id is " << charId[ch] << endl;
            }
        }
        // cout << minId << endl;
        return maxLength;
    }

int main(int argc, char const *argv[])
{   
    string s = "tmmzuxt"; // should return 5
    // string s = "abcabcbb"; // should return 3
    // string s = "phjkug"; // shoiuld return 6

    // cout << "Hello World" << endl;

    int maxSubStrLength = lengthOfLongestSubstring(s);

    cout << "Max Substring Length: " << maxSubStrLength << endl;
    cout << "String Length: " << s.length() << endl;
    
    
    // 1)
    return 0;
}
