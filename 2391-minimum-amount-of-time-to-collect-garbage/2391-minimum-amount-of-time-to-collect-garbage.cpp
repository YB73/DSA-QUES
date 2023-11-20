class Solution {
public:
    int garbageCollection(vector<string>& gar, vector<int>& travel) {
       int n = gar.size();
        vector<vector<int>> arr;
        int M = 0, P = 0, G = 0;
        for (auto v : gar)
        {
            int mc = 0, pc = 0, gc = 0;
            for (char ch : v)
            {
                if (ch == 'M')
                    mc++;
                else if (ch == 'P')
                    pc++;
                else
                    gc++;
            }
            M += mc;
            P += pc;
            G += gc;
            arr.push_back({gc, pc, mc});
        }
        int gc = 0, pc = 0, mc = 0;
        for (int i = 0; i < n; i++)
        {
            G -= arr[i][0];
            gc += arr[i][0];
            P -= arr[i][1];
            pc += arr[i][1];
            M -= arr[i][2];
            mc += arr[i][2];
            if (i < n - 1)
            {
                if (M != 0)
                    mc += travel[i];
                if (P != 0)
                    pc += travel[i];
                if (G != 0)
                    gc += travel[i];
            }
        }
        return mc + pc + gc;
        
        
    }
};