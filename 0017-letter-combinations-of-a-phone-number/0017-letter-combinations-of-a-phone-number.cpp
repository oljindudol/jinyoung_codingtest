class Solution {
public:
    void pushdata(string _s , int depth , 
                  vector<string>& _chars , vector<string>& _out )
    {
        if(depth == _chars.size())
        {
            _out.push_back(_s);
            return;
        }
        
        for(int i =0 ; i< _chars[depth].size(); ++i)
        {
            pushdata(_s+_chars[depth][i] , depth +1 , _chars , _out);
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        vector<string> chars;
        
        int sz = digits.size();
        
        if(0==sz)
            return ret;
        
        for(int i= 0 ; i< digits.size(); ++i)
        {
            auto d = digits[i];
            
            switch(d)
            {
                case '2':
                    chars.push_back("abc");
                    break;
                case '3':
                    chars.push_back("def");
                    break;
                case '4':
                    chars.push_back("ghi");
                    break;
                case '5':
                    chars.push_back("jkl");
                    break;
                case '6':
                    chars.push_back("mno");
                    break;
                case '7':
                    chars.push_back("pqrs");
                    break;
                case '8':
                    chars.push_back("tuv");
                    break;
                case '9':
                    chars.push_back("wxyz");
                    break;
            }
        }
        pushdata("" , 0 , chars , ret);
        return ret;
    }
};