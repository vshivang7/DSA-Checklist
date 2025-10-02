// You are given two integers numBottles and numExchange.

// numBottles represents the number of full water bottles that you initially have. In one operation, you can perform one of the following operations:

// Drink any number of full water bottles turning them into empty bottles.
// Exchange numExchange empty bottles with one full water bottle. Then, increase numExchange by one.
// Note that you cannot exchange multiple batches of empty bottles for the same value of numExchange. For example, if numBottles == 3 and numExchange == 1, you cannot exchange 3 empty water bottles for 3 full bottles.

// Return the maximum number of water bottles you can drink.

// Approach 1
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int filled=numBottles, empty=0;
        int drunk=0;
        while(filled>0 || empty>=numExchange){
            drunk+=filled;
            empty+=filled;
            filled=0;
            if(empty>=numExchange){
                filled+=1;
                empty-=numExchange;
                numExchange++;
            }
        }
        return drunk;
    }
};

//Optimal
class Solution {
public:
    int maxBottlesDrunk(int nB, int nE) {
        int x=nB;
        int y=nE;
        int h=(((-2*y)+3+sqrt(4*y*y+8*x-12*y+1))/2);
        return x+h;
    }
};
