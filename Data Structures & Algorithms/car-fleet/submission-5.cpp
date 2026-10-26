
struct Car {
    int position;
    int speed;

    Car() {position = 0;speed = 0;}

    Car(int position, int speed) {
        this->position = position;
        this->speed = speed;
    }
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        Car cars[n];    // initialize cars array

        // add car objects to the array
        for (int i = 0; i < n; i++) {
            cars[i] = Car(position[i], speed[i]);
        }

        // sort by positions in desc car array
        std::sort(cars, cars + n, [](Car c1, Car c2) {return c1.position > c2.position;});

        stack<float> stack;
        for (int i = 0; i < n; i++) {
            float time = (float)(target - cars[i].position) / cars[i].speed;
            if (stack.empty()) {
                stack.push(time);
            }
            else {
                if (time <= stack.top()) {
                     // car join the same fleet
                }
                else {
                    stack.push(time);
                }
            }
        }
        return stack.size();
    }
};