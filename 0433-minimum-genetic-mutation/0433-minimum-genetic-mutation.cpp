class Solution {
public:
    int diff(string& str1, string& str2)
    {
        int diff = 0;
        for(int i = 0 ; i < 8 ; i++)
            if(str1[i] != str2[i])
                diff++;
        return diff;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        int mutations  = 0;
        unordered_set<string> seen;
        
        queue<string> geneQueue;
        
        geneQueue.push(start);
        
        while(!geneQueue.empty())
        {
            int size = geneQueue.size();
            while(size > 0)
            {
                auto tmpGene = geneQueue.front();
                geneQueue.pop();
                
                if(tmpGene == end)
                    return mutations;
                
                for(auto gene : bank)
                {
                    if(seen.find(gene) == seen.end() && diff(tmpGene, gene) == 1)
                    {
                        geneQueue.push(gene);
                        seen.insert(gene);
                    }
                }
                
                size--;
            }
            mutations++;
        }
            
        return -1;

    }
};