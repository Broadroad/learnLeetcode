class MinStack {
public:
            // do intialization if necessary
    stack<int> numbers;
    stack<int> smallest;
    MinStack() {

    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        // write your code here
        numbers.push(number);

        if (smallest.empty() || smallest.top() >= number) {
            smallest.push(number);
        }
    }

    /*
     * @return: An integer
     */
    int pop() {
        std::cout << "pop smallest" << smallest.top() << std::endl;
        // write your code here
        if (smallest.top() == numbers.top()) {
            smallest.pop();
        }
        int result = numbers.top();
        numbers.pop();
        return result;
    }

    /*
     * @return: An integer
     */
    int min() {
        // write your code here
        return smallest.top();
    }
};