class Solution {
public:
   int findPar(int * par,int x){
        while(par[x] != x)
        {
            x = par[x];
        }
        return x;
    }
    int findCircleNum(vector<vector<int>>& M) {
        int par[200];
        int szM = M.size(),res = 0;
        for(int i = 0; i < szM; i++){
            par[i] = i;
        }
        for(int i = 0; i < szM; i++){
            for(int j = i; j < szM; j++){
                if(M[i][j] == 1){
                    int x = findPar(par,i);
                    int y = findPar(par,j);
                    par[x] = y;
                }
            }
        }
        for(int i = 0; i < szM; i++){
            if(par[i] == i) 
                res++;
        }
        return res;
    }
};
