class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nearX = 0,nearY = 0;
        if(xCenter >= x2) nearX = x2;
        else if(xCenter <= x1) nearX = x1;
        else if(xCenter > x1 && xCenter <x2) nearX = xCenter;
        //similary nearY find krrrhe
        if(yCenter >= y2) nearY = y2;
        else if(yCenter <= y1) nearY = y1;
        else if(yCenter > y1 && yCenter <y2) nearY = yCenter;

        int x = nearX - xCenter;
        int y = nearY - yCenter;
        int dist = x*x + y*y;
        if(dist <= radius*radius){
            return true;
        }
        return false;
    }
};