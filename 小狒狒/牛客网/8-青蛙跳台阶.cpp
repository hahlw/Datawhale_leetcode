class Solution {
public:
    int jumpFloor(int number) {
        int a = number;
        if (a <= 2) return number;
        int jumpFloorMinusOne = 2;
        int jumpFloorMinusTwo = 1;
        int jumpFloorN = 0;
        for( int i=3; i<=a; i++){
            jumpFloorN = jumpFloorMinusOne + jumpFloorMinusTwo;
            jumpFloorMinusTwo = jumpFloorMinusOne;
            jumpFloorMinusOne = jumpFloorN;
        }    
        return jumpFloorN;
    }
};
