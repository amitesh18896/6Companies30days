//space complexity = O(N) -> N- length of string
//time complexity = O(N)
class Solution{
public:
    string decodedString(string s){
        stack<char>st;
        //iterating through the string
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=']')
            {
                st.push(s[i]);
            }
            else
            {
            // found a ']'
            // pop all elements till '['
            string current_string="";
            while(st.top()!='[')
            {
                current_string = st.top()+current_string;
                st.pop();
            }
            //found '['
            //pop '['
            st.pop();
            string number="";
            while(!st.empty() && isdigit(st.top()))
            {
                number = st.top() + number;
                st.pop();
            }
            int no_of_times = stoi(number);
            while(no_of_times--)
            {
                //push the current string between [ and ] for no. of times given outside the bracket, in the stack
                for(char ch : current_string)
                {
                    st.push(ch);
                }
            }
        }
        }
        string ans= "";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};
