// std::queue in cpp

#include <iostream>
#include <queue>

void showQueue(std::queue<int> q){
    std::queue<int> temp = q;
    std::cout << "The queue list is: ";
    while(!temp.empty()){
        std::cout << '\t' << temp.front();
        temp.pop();
    }
    std::cout << "\n";
}
int main(){
    std::queue<int> q;
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);

    std::cout << "Front element: " << q.front() 
              << "\nRear Element: " << q.back() << std::endl;

    showQueue(q);

    std::cout << "Deleted: "<< q.front() << std::endl;
    q.pop();
    
    showQueue(q);

}
