#include <vector>
#include <memory>
#include <iostream>

class Item {
public: 
  // Define your Item class here
    ~Item() {
        std::cout << "Hello World!";
    }
};

int main() {
    {
        // best
        std::vector<std::unique_ptr<Item>> items;

        // Use move semantics to add a new item to the vector
        items.push_back(std::move(std::make_unique<Item>()));
    }

    {
        // ok
        std::vector<std::unique_ptr<Item>> items;

        // Use move semantics to add a new item to the vector
        items.push_back(std::make_unique<Item>());
    }

    {
        // memory leak
        std::vector<Item*> items;

        // Use move semantics to add a new item to the vector
        items.push_back(new Item());
    }
    
    return 0;
}
