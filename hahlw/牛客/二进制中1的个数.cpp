class Solution {
public:
     int  NumberOf1(int n) {
         /*
         int flag=1,count=0;
         while(flag!=0){
             if(n&flag)count++;
             flag<<=1;
         }
         return count;
         */
         int count=0;
         while(n){
             count++;
             n=n&(n-1);
         }
         return count;
     }
};