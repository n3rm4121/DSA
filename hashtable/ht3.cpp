// Hash Table with Open Addressing (Linear Probing)

#include <iostream>
#include <vector>
using namespace std;

class HashMap{
private:
	int capacity;
	vector<pair<int,int>> table;

	int hashFunction(int key){
		return key % capacity;
	}

	int probe(int index){
		return (index + 1) % capacity; // linear probing
	}

public:
	HashMap(int size) : capacity(size){
		table.resize(capacity, {-1,-1}); // initialize all slot with -1 indicating empty

	}

	void insert(int key, int value){
		int index = hashFunction(key);
		while(table[index].first!= -1){
			index = probe(index);
		}
		table[index] = {key,value};
	}


    int search(int key) {
        int index = hashFunction(key);
        int originalIndex = index;
        while (table[index].first != key && table[index].first != -1) {
            index = probe(index);
            if (index == originalIndex) {
                return -1; // Key not found or table is full
            }
        }
        return table[index].first == key ? table[index].second : -1;
    }

    void remove(int key) {
        int index = hashFunction(key);
        int originalIndex = index;
        while (table[index].first != key && table[index].first != -1) {
            index = probe(index);
            if (index == originalIndex) {
                return; // Key not found
            }
        }
        if (table[index].first == key) {
            table[index] = {-1, -1}; // Mark slot as empty
        }
    }

	void display(){
		for (int i = 0; i < capacity; i++)
		{
			if(table[i].first != -1){
				cout << "Bucket " << i << ": (" << table[i].first<< ", " << table[i].second << ")" << endl;

			}
		}
	}
};

int main(){
    HashMap map(10);

    map.insert(1, 10);
    map.insert(2, 20);
    map.insert(3, 30);
    map.insert(11, 110);
    map.insert(21, 220);
    map.insert(31, 330);

    map.display();

    std::cout << "Value associated with key 2: " << map.search(2) << std::endl;

    map.remove(2);

    map.display();

    return 0;
}

