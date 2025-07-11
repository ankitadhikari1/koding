class ParkingSystem {
public:
    int b, m, s;
    ParkingSystem(int big, int medium, int small) {
        this->b = big;
        this->m = medium;
        this->s = small;
    }

    bool addCar(int carType) {
        // b -> 1,m -> 2, s-> 3
        if (carType == 1) {
            if (b) {
                b -= 1;
                return true;
            } else {
                return false;
            }
        }

        if (carType == 2) {
            if (m) {
                m -= 1;
                return true;
            } else {
                return false;
            }
        }

        if (carType == 3) {
            if (s) {
                s -= 1;
                return true;
            }
        }

        return false; 
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */