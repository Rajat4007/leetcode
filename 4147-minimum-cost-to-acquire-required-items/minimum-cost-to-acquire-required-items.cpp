class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        //Function minimumCost(cost1, cost2, costBoth, need1, need2):
    
    // Step 1: Common requirements ke liye decide karo ki sasta kya padega.
    // Kya costBoth individual costs ke sum (cost1 + cost2) se sasta hai?
    // Agar haan, toh combination use karenge, nahi toh separate.
    long long effectiveCost1 = min(cost1, costBoth);
    long long effectiveCost2 = min(cost2, costBoth);
    
    // Step 2: Dono needs ka common part nikalo
    long long common = min(need1, need2);
    
    // Common part ko fulfill karne ka min cost
    // Yahan combo item (costBoth) ko dono individual costs ke sum se compare karna hai
    long long totalCost = common * min((long long )costBoth, (long long ) cost1 + cost2);
    
    // Step 3: Remaining needs ko handle karo
    if( need1 > need2){

        int rem = need1 - need2;
        // Bachi hui need1 ke liye choice: ya toh type1 lo ya type3 (jo bhi sasta ho)
        totalCost = totalCost + rem * effectiveCost1;
    }
    else{

        int rem = need2 - need1;
        // Bachi hui need2 ke liye choice: ya toh type2 lo ya type3 (jo bhi sasta ho)
        totalCost = totalCost + rem * effectiveCost2;
    }
        
    return totalCost;
    }
};