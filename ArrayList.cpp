#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#define DEFAULT_CAPACITY 10
// A: implementing ArrayList

class ArrayList{
public:
    ArrayList();
    ~ArrayList();
    void add(int value);
    int& operator[](int&& index);
    void insertValue(int index, int value);
    void removeValue(int value);
    bool contains(int value);
    std::set<int> findAllDuplicates();
    int getSize();
    void sort();
    int& getElement(int index) {
        return myElements[index];
    }
    void insertAt(int index, int value){
        myElements[index] = value;
    }
private:
    int* myElements;
    int _capacity;
    int _size;
    void grow();
    void fastRemove(int* es, int index);

};
int ArrayList::getSize(){
    return this->_size;
}

int& ArrayList::operator[](int&& index){
        return myElements[index];
}

void merge(ArrayList& arr, int start, int mid, int end);
void sortArrayList(ArrayList& arr, int start, int end);



// C: Finding duplicate elements in an ArrayList
std::set<int> ArrayList::findAllDuplicates(){
        std::unordered_set<int> set;
        std::set<int> solution;
        for(int i = 0; i < _size; ++i){
            bool added = set.insert(myElements[i]).second;
            if(!added){
                solution.insert(myElements[i]);
            }
        }
        return solution;
    }

ArrayList::ArrayList(){
    this->_capacity= DEFAULT_CAPACITY;
    this->_size = 0;
    this->myElements = new int[_capacity];
}

ArrayList::~ArrayList(){
    std::cout << "ArrayList destroyed!" << std::endl;
    if(myElements != nullptr){
        delete[] myElements;
    }
}

bool ArrayList::contains(int value){
    int i = 0;
    for(; i < _size; i++){
        if(this->myElements[i] == value){
            return true;
        }
    }
    return false;

}

void ArrayList::insertValue(int index, int value){
    if(this->_size == this->_capacity){
        grow();
    }
    for(int i = _size; i > index; --i){
        this->myElements[i] = this->myElements[i - 1];
    }
    this->myElements[index] = value;
    this->_size++;
}

void ArrayList::grow(){
    int oldCapacity  = _capacity;
    int newCapacity = oldCapacity * 2;
    int* aux_ptr = myElements;
    this->myElements = new int[newCapacity];
    std::copy(aux_ptr, aux_ptr + _size, myElements);
    this->_capacity = newCapacity;
    delete aux_ptr;
}
void ArrayList::fastRemove(int* es, int index){
    const int newSize = this->_size - 1;
    if(newSize > index){
        for(int i = index; i < this->_size; ++i){
            es[i] = es[i + 1];
        }
    }
    this->_size = newSize;
    es[_size] = 0;
}
void ArrayList::removeValue(int value){
    int i =0;
    for(; i < this->_size; i++){
        if(this->myElements[i] == value){
            break;
        }
    }
    fastRemove(this->myElements, i);
}

void ArrayList::add(int value){
    if(this->_size == this->_capacity){
        this->grow();
    }
    myElements[_size] = value;
    _size++;
}
// I: sorting an ArrayList
void sortArrayList(ArrayList& arr, int start, int end){
        if(start < end){
            int mid = start + (end - start)/2;
            sortArrayList(arr, start, mid);
            sortArrayList(arr, mid + 1, end);
            merge(arr, start, mid, end);
        }
}

void merge(ArrayList& arr, int start, int mid, int end) {
    int leftIndex = mid - start + 1;
    int rightIndex = end - mid;

    ArrayList left;
    ArrayList right;

    for (int i = 0; i < leftIndex; i++) {
        left.insertAt(i, arr.getElement(start + i));
    }
    for (int j = 0; j < rightIndex; j++) {
        right.insertAt(j, arr[mid + 1 + j]);
    }

    int i = 0;
    int j = 0;
    int k = start;

    ArrayList mergedValues;

    while (i < leftIndex && j < rightIndex) {
        if (left.getElement(i) <= right.getElement(j)) {
            mergedValues.add(left.getElement(i));
            i++;
        }
        else {
            mergedValues.add(right.getElement(j));
            j++;
        }
        k++;
    }

    while (j < rightIndex) {
        mergedValues.add(right.getElement(j));
        j++;
        k++;
    }

    while (i < leftIndex) {
        mergedValues.add(left.getElement(i));
        i++;
        k++;
    }


    for (int index = 0; index < mergedValues.getSize(); index++) {
        arr.insertAt(start + index, mergedValues.getElement(index));
    }
}

int main(){

    ArrayList myArr;
    myArr.add(1);

    myArr.add(10);
    myArr.add(10);
    myArr.add(2);
    myArr.add(5);
    myArr.add(2);
    myArr.add(2);
    myArr.add(3);
    myArr.add(2);
    myArr.add(2);
    myArr.add(5);
    myArr.add(2);


    for(int i = 0; i < myArr.getSize(); i++){
        std::cout << i << ": " << myArr[std::move(i)] << std::endl;
    }
    sortArrayList(myArr, 0, myArr.getSize());
    std:: cout << "\n";
    for(int i = 0; i < myArr.getSize(); i++){
        std::cout << i << ": " << myArr[std::move(i)] << std::endl;
    }


    return 0;
}
