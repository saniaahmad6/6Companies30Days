class Solution {
    double r, x, y;
public:
    Solution(double radius, double x_center, double y_center) : r(radius), x(x_center), y(y_center) {
        srand(time(0));
    }
    double random(){
        return (double)rand() / RAND_MAX; //  random point between 0 to 1
    }
    vector<double> randPoint() {
        vector<double> randomPoint(2);
        double len = sqrt(random()) * r, deg = 2 * M_PI * random();
        randomPoint[0] = x + len * cos(deg);
        randomPoint[1] = y + len * sin(deg);
        return randomPoint;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
