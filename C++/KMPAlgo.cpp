#include<bits/stdc++.h>
using namespace std;

// This algorithm is very useful for coding interviews.
// This algorithm can can solve the searching problem in O(n+m) time, 
// where length of the pattern to be search is n and the string in which 
// it has to be search is of length m.

// How it works:

// Let us assume that a string s has to be searched in t.
// Now we build an array where we store the length of proper suffix
// ending at every index where the suffix is also equal to prefix.

// Let us assume that we have a string such as s+"#"+t, where # is just a delimeter.
// So further if we get a length of suffix at any position in t where the suffix
// is equal to prefix. Then we have found a pattern of s in t with position beginning at 
// pos - s.length() where pos is the last position where last character of s matched.



// Implementation begins:
// creating the suffix length array for s
vector<int> KMPpreprocessing (string s) {
    int n = s.length();
    // creating a vector to store the length of suffix which is also a prefix with 
    // respect to the very beginning of string s
    vector<int> P(n);
    // first position should be always assigned 0
     P[0]=0;
    for (int i=1; i<n; ++i) {
        int j = P[i-1];
        // moving back until an equal character is not found
        // with respect to current character
        while (j > 0 && s[i] != s[j])
            j = P[j-1];
        if (P[i] == P[j])  ++j;
        P[i] = j;
    }
    return P;
}

// Function for string searching
void KMPSearching(string s, string t) 
{ 
	// The vector which will get the suffix length
	// which is also a prefix.
    vector<int> v = KMPpreprocessing(s);
    int m = s.length();
    int n = t.length();
  
    int i = 0; // index for t 
    int j = 0; // index for s 
    while (i < t.length()) { 
        if (s[j] == t[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == m) { 
            printf("Found the pattern at index:  %d ", i - j); 
            j = v[j - 1]; 
        } 
  
        // mismatch after j matches 
        else if (i < n && s[j] != t[i]) { 
            // Do not match v[0..v[j-1]] characters, 
            // they will match anyway 
            if (j != 0) 
                j = v[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
} 

int main(){
    // sample inputs
    string t = "I Love HacktoberFest2020";
    string s = "Love";
    KMPSearching(s,t);
    return 0;
}