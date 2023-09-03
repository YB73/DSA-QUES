class Solution {
public:
//     12345678 + 12345678
//     1234567(8+1)2345678
//     1234567(8+12)345678
    
    // find the index of plus sign 
    int findPlus(string s,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(s[i]=='+')
                return i;
        }
        return -1;
    }
    
    //a(b+c)d , it will return the answer for this string
    long long int compute(string s)
    {
        int n = s.size();
        int i=0;
        long long int prev = 0LL , prevPlus = 0LL , nextPlus = 0LL,next=0LL;
        while(i<n)
        {
            if(s[i]=='(')
                break;
            prev = prev*10LL + s[i]-'0';
            i++;
        }
        
        i++;
        while(i<n)
        {
            if(s[i]=='+')
                break;
            prevPlus = prevPlus*10LL + s[i]-'0';
            i++;
        }
        i++;
        
        while(i<n)
        {
            if(s[i]==')')
                break;
            nextPlus = nextPlus*10LL + s[i]-'0';
            i++;
        }
        i++;
        
        while(i<n)
        {
            next = next*10LL + s[i]-'0';
            i++;
        }
        
        // (1+3) , (1+3)4 , 4(1+3) for this type of cases
        if(prev ==0)
            prev = 1;
        if(next==0)
            next=1;
        
        return (prev*1LL*(prevPlus+nextPlus)*1LL*next*1LL);
    }
    
    string minimizeResult(string s) {
        int n = s.size();
        int plusSign = findPlus(s,n);  
        string ansString  = "";
        long long int ans = 999999999999999999;
        for(int i=0;i<plusSign;i++)
        {
            string leftBracket = s;
            leftBracket.insert(i,"(");
            int herePlus = findPlus(leftBracket,leftBracket.size());
            for(int j=herePlus+2;j<=leftBracket.size();j++)
            {
                string rightBracket = leftBracket;
                rightBracket.insert(j,")");
                long long int comp = compute(rightBracket);
                if(ans > comp)
                {
                    ans = comp;
                    ansString  = rightBracket;
                }
                // cout<<rightBracket<<"->"<<comp<<endl;
            }
        }
        return ansString;
    }
};