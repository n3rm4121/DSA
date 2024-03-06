// Hash Table with Separate Chaining (Chaining)

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashMap{
private:
    // vector of linked lists
    vector<list<pair<int,int>>> table;
    int capacity;  // no. of buckets in hashmap

    int hashFunction(int key){
        return (key % capacity);
    }

public:
    HashMap(int size){
        capacity = size;
        table.resize(capacity); // initialize vector with specific size
    }

    void insert(int key, int value){
        int index = hashFunction(key);
        table[index].push_back({key, value});
    }

    int search(int key){
        int index = hashFunction(key);
        for(auto& val : table[index]){
            if(val.first == key){
                return val.second;
            }
        }
        return -1;  // key not found
    }

    void remove(int key){
        int index = hashFunction(key);
        for(auto it = table[index].begin(); it!=table[index].end(); it++){
            if(it->first == key){
                table[index].erase(it);
                return; // exit function after removal
            }
        }
    }

    void display(){
        for (int i = 0; i < capacity; i++)
        {
            cout << "Bucket " << i << ": ";

            for(const auto& j : table[i]){
                cout << "(" << j.first <<", " << j.second << ") " ;
            }
            cout << endl;
        }
    }
};

int main(){
    HashMap map(10); // create a hash map with 10 buckets

    // insert key-value pairs
    map.insert(1, 10);
    map.insert(2,20);
    map.insert(3,30);

    //display
    map.display();
    
    // search for a key

    cout << "Value associated with key 2: " << map.search(2) << endl;

    // remove a key
    map.remove(2);
    cout << "Value associated with key 2 after removal: " << map.search(2) << endl;

    map.insert(4,5);
    map.display();
}