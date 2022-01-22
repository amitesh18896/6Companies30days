class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        unordered_map<string,vector<string>>mapOfStringAndItsAnagrams;
        vector<vector<string>>grouped_anagrams;
        
        // mapping words and its anagrams 
        for(int i=0;i<string_list.size();i++)  // O(N) -> N- Size of the string list
        {
            string current_word = string_list[i];
            sort(current_word.begin(),current_word.end());  // O(SlogS) -> S->Size of words
         
            if(mapOfStringAndItsAnagrams.find(current_word)!=mapOfStringAndItsAnagrams.end())
            {
                mapOfStringAndItsAnagrams[current_word].push_back(string_list[i]);
            }
          
            else
            {
                vector<string>anagrams;
                anagrams.push_back(string_list[i]);
                mapOfStringAndItsAnagrams.insert({current_word,anagrams});
            }
        }
        
        // Pushing the anagrams from the map in the answer vector together
        for(auto anagrams : mapOfStringAndItsAnagrams)
        {
            grouped_anagrams.push_back(anagrams.second);
        }
        
        return grouped_anagrams;
    }
};

// Time complexity for the problem is  -> O(N*S*logS)
// Space Complexity for the problem is -> O(N*S)
