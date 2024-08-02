/*You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.
Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
*/


class Solution {
public:

/*one more solution can be in a loop till(i>=j)
    initially we merge both arrays into one(called a) i=1, j=word1.size();
    temp <- a[j];
    shift (a[i]-> a(j));
    a[i]=temp; --> this stores the value of a[j] at its correct pos;
    i+=2; j++; as a[i+1] is already placed at the rigth index;
    continue;
*/    

    string mergeAlternately(string word1, string word2) {
        int n = (word1.size()+word2.size());
        char merged[n+1];
        merged[n] = '\0';

        int i=0,j=0,k=0;
        while(word1[i] != '\0' && word2[j] != 0){
            merged[k++] = word1[i++];
            merged[k++] = word2[j++];
        }
        while(word1[i]!='\0'){
            merged[k++]=word1[i++];
        }

        while(word2[j]!='\0'){
            merged[k++]=word2[j++];
        }

        return merged;
    }
};