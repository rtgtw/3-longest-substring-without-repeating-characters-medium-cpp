/*
Longest substring

We are going to have to iterate through the whole array

We can use a hash table and a count to possibly track non-repeating characters

we can use a for loop to iterate through the full array

through each iteration,
check if element is inside of the hashmap, if it is not increment count
and store it inside of the hashmap
increment max
and move to next element

we can have max and count

if we find an element within the hashmap
we clear the hashmap,
set the count to 1 
and move to the next element

*/


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


class Solution {
public:
	int lengthOfLongestSubstring(std::string s);
};


int Solution::lengthOfLongestSubstring(std::string s) {

	//Create a hash table
	std::unordered_map<char, int> substring;

	//Max and count variables
	int count = 0;
	int max = 0;
	int i = 0;


	//Use a while loop to iterate through the full array of strings
	//Until it gets to the null character
	while (s[i] != '\0') {

		//Check if the element is inside of the hashmap
		//if the char is not inside of the hashmap
		if (substring.find(s[i]) == substring.end()) {
			
			//Store it inside of the hashmap
			//with its index
			substring[s[i]] = i;

			//Increment count
			count++;

			//Move to the next element
			i++;


			if (count > max) {
				max = count;
			}
		}//If element is found within the hashmap
		else {

			

			//Iterate through hashmap looking for a specific value
			for (auto j = substring.begin(); j != substring.end();) {
				if (j->second < substring[s[i]]) {
					j = substring.erase(j);
				}
				else {
					j++;
				}
			}

			

			//remove it from the hashmap, insert the new occurrence
			substring.erase(s[i]);



			//insert the new occurence inside of the hashmap
			substring[s[i]] = i;

			//The count should be the size of the hashmap
			count = substring.size();

			//Move to the next element
			i++;

			//We want to set max here, check if count is greater than
			//the current max, if it is, update max
			if (count > max) {
				max = count;
			}

		}
	}

	//After we reach the end of the array we want to return the max
	return max;

}



int main() {

	Solution solution;

	std::string s = "abcabcbb";
	std::string s1 = "bbbbb";
	std::string s2 = "pwwkew";
	std::string s3 = " ";
	std::string s4 = "dvdf";
	std::string s5 = "dabcdf";

	std::cout << solution.lengthOfLongestSubstring(s4);



}



