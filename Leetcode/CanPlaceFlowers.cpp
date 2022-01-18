class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s = flowerbed.size();
        if(n==0){
            return true;
        }
        if(s==1 && !flowerbed[0]){
            return(n==1);
        }
        int count = 0;
        int i = ((flowerbed[0])? 1:0);
        while(i<s){
            if(i==0){
                if(!flowerbed[i] && !flowerbed[i+1]){
                    count++;
                    flowerbed[i] = 1;
                }
            }
            else if(i == s-1){
                if(!flowerbed[i] && !flowerbed[i-1]){
                    count++;
                    flowerbed[i]=1;
                    
                }
            }
            else{
                if(!flowerbed[i] && !flowerbed[i-1] && !flowerbed[i+1]){
                    count++;
                    flowerbed[i] = 1;
                }
            }
            i++;
        }
        return (count>=n);
        
    }
};