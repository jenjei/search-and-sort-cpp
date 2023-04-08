

class NumberList {
private:
    int *arr; // Pointer to dynamic array
    int size; // Size of array
    int key; // Key value to search for

public:
    // Constructor
    NumberList(int size);

    // Destructor
    ~NumberList();

    // Generates a list of odd integers
    void generateList();

    // Prints the list of numbers
    void printList();

    // Sets the key value to search for
    void setKey(int key);

    // Searches for the key value using linear search
    int linearSearch();

    // Searches for the key value using binary search
    int binarySearch();

    // Generates a random key value between 1 and size*2
    int generateKey();

    // Runs the program
    void run();
};