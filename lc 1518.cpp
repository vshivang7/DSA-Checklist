// 1518. Water Bottles
// There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water bottles from the market with one full water bottle.
// The operation of drinking a full water bottle turns it into an empty bottle.
// Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.

// Input: numBottles = 15, numExchange = 4
// Output: 19
// Explanation: You can exchange 4 empty bottles to get 1 full water bottle. 
// Number of water bottles you can drink: 15 + 3 + 1 = 19.

// Optimised
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int filled=numBottles;
        int empty=0;
        int total=0;
        while(filled){
            total+=filled;
            empty+=filled;
            filled=empty/numExchange;
            empty=empty%numExchange;
        }
        return total;
    }
};

//brute force
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumedBottles = 0;

        while (numBottles >= numExchange) {
            // Consume numExchange full bottles.
            consumedBottles += numExchange;
            numBottles -= numExchange;

            // Exchange them for one full bottle.
            numBottles++;
        }

        // Consume the remaining numBottles (<numExchange).
        return consumedBottles + numBottles;
    }
};
