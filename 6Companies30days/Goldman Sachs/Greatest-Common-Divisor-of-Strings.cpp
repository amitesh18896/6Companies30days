//method-1
//tc-O(n)
class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        int length_s1=s1.length();
        int length_s2=s2.length();
        if(length_s1==length_s2)
        {
            if(s1==s2)
            {
                return s1;
            }
            else
            {
                return "";
            }
        }
        if(length_s1>length_s2)
        {
            if(s1.substr(0,length_s2)==s2)
            {
                return gcdOfStrings(s1.substr(length_s2),s2);
            }
            else
            {
                return "";
            }
        }
        else
        {
            return gcdOfStrings(s2,s1);
        }
    }
};


//compact version
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int s1 = str1.size(), s2 = str2.size();
        if (s1 < s2) 
            return gcdOfStrings(str2, str1);
        if (str2.empty()) 
            return str1;
        if (str1.substr(0, s2) != str2) 
            return "";
        return gcdOfStrings(str1.substr(s2), str2);
    }
};
