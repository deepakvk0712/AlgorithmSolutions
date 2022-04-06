//Has code for heap data structure and the heap sort function

#include<vector>
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<climits> //Allows to use INT_MAX and INT_MIN
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

//Easier to manage heap data structure as a array.
class MinHeap{
    public:
        int * heapArray; //Pointer to the array of elements in heap array
        int capacity; // Maximum capacity of the min heap
        int heap_size; //Current occupied capacity of the min heap

        MinHeap(int cap){
            heap_size = cap; //Changed from 0 to capacity for the heap sort
            capacity = cap;
            heapArray = new int[capacity];
        }

        void linearSearch(int val){
            for(int i=0;i <heap_size; i++){
                if(val == heapArray[i]){
                    cout << "We have found the value at : " << i+1;
                    return;
                }
            }
            cout<<"Did not find value in the min heap! \n";
        }

        void printArray(){
            for(int i=0; i<heap_size; i++){
                cout << heapArray[i] << " ";
            }
            cout << endl;
        }

        int height(){
            return ceil(log2(heap_size+1)) - 1; //Standard formula
        }

        void insertKey(int val){
            if(heap_size==capacity){
                cout << "Reached capacity limit! Overflow!" <<endl;
                return;
            }
            heap_size++;
            int i = heap_size-1;
            heapArray[i] = val;
            while(i!=0 && heapArray[findParent(i)] > heapArray[i]){
                swap(heapArray[i], heapArray[findParent(i)]);
                i = findParent(i); //Setting new value for i
            }
            cout << "Successfully inserted the value : " << val << " into the min heap!" << endl;
        }

        int extractMin(){
            if(heap_size <= 0){
                return INT_MAX; //Basically this is a check to ensure the heap is not empty
            }

            if(heap_size == 1){
                heap_size--;
                return heapArray[0];
            }

            int root = heapArray[0];
            heapArray[0] = heapArray[heap_size - 1];
            heap_size--;
            minHeapify(0);
            return root;
        }

        void minHeapify(int k){
            int left = leftChild(k);
            int right = rightChild(k);
            int smallest = k;
            if(left < heap_size && heapArray[left] < heapArray[k]){
                smallest = left;
            }
            if(right < heap_size && heapArray[right] < heapArray[smallest]){
                smallest = right;
            }
            if(smallest!=k){
                swap(heapArray[k], heapArray[smallest]);
                minHeapify(smallest);
            }
        }

        int getMin(){
            if(heap_size >= 1){
                return heapArray[0];
            }
            else{
                return INT_MAX;
            }
        }

        void deleteKey(int k){
            decreaseKey(k, INT_MIN);
            extractMin();
            cout << "Successfully deleted key : " << k << endl;
        }

        void decreaseKey(int k, int min_val){
            heapArray[k] = min_val;
            while(k!=0 && heapArray[findParent(k)] > heapArray[k]){
                swap(heapArray[k], heapArray[findParent(k)]);
                k = findParent(k);
            }
        }

        int findParent(int key){
            return (key-1)/2;
        }

        int leftChild(int key){
            return (2*key + 1);
        }

        int rightChild(int key){
            return (2*key + 2);
        }

        void getUnsortedArray(){
            cout << "Enter " << capacity << " number of elements to sort using heap sort." << endl;
            for(int i=0; i< capacity; i++){
                cin >> heapArray[i];
            }
        }

        //Writing the heap sort algorithm here.
        void heapSort(){
            int temp[capacity];
            for(int i = 0; i<capacity; i++){
                temp[i] = extractMin();
                cout << temp[i] << " ";
            }
            cout << endl;
        }

};


int main(){
    int size;
    int option, val;
    int temp;
    cout << "Enter the size of the heap : " << endl;
    cin >> size;
    MinHeap minHeapObj(size);

    //Extra part that has to be done for heap sort
    minHeapObj.getUnsortedArray();
    cout << "The unsorted array is " << endl;
    minHeapObj.printArray();
    for(int i=(size/2) -1; i>=0; i--){
        minHeapObj.minHeapify(i);
    }

    cout << "Heap sorted array is : " << endl;
    minHeapObj.heapSort();

    // do{
    //     cout << "What operation do you want to perform? \n \n";
    //     cout << "Select the option number you want to perform. Enter 0 to exit.\n";
    //     cout << "1. Insert key/node" << endl;
    //     cout << "2. Search key/node" << endl;
    //     cout << "3. Delete key/node" << endl;
    //     cout << "4. Get minimum value" << endl;
    //     cout << "5. Extract the minimum" << endl;
    //     cout << "6. Get height of the min heap" << endl;
    //     cout << "7. Print heap values" << endl;
    //     cout << "8. Clear screen" << endl;
    //     cout << "9. Heap sort the array" <<endl;
    //     cout << "0. Exit the program" << endl;

    //     cin >> option;
    //     switch (option)
    //     {
    //     case 0:
    //         cout << "Exiting the program!" << endl;
    //         break;
        
    //     case 1:
    //         cout << "Inserting a key into the heap." << endl;
    //         cout << "Enter the val to insert into the heap" << endl;
    //         cin >> val;
    //         minHeapObj.insertKey(val);
    //         break;

    //     case 2:
    //         cout << "Searching for key in the heap." << endl;
    //         cout << "Enter the val to search in the heap" << endl;
    //         cin >> val;
    //         minHeapObj.linearSearch(val);
    //         break;

    //     case 3:
    //         cout << "Deleting a key in the heap." << endl;
    //         cout << "Enter the key index to be deleted in the heap" << endl;
    //         cin >> val;
    //         minHeapObj.deleteKey(val);
    //         break;
        
    //     case 4:
    //         cout << "Getting minimum value in the heap" << endl;
    //         temp = minHeapObj.getMin();
    //         if(temp == INT_MAX){
    //             cout << "The heap is empty!" << endl;
    //         }
    //         else{
    //             cout << "The minimum value at the root is  : " << temp << endl;
    //         }
    //         break;

    //     case 5:
    //         cout << "Extracting the minimum key in the heap." << endl;
    //         temp = minHeapObj.extractMin();
    //         if(temp == INT_MAX){
    //             cout << "The heap is empty!" << endl;
    //         }
    //         else{
    //             cout << "The extracted value is : " << temp << endl;
    //         }
    //         break;

    //     case 6:
    //         cout << "Getting the height of the min heap." << endl;
    //         temp = minHeapObj.height();
    //         cout << "The height of the min heap is : " << temp << endl;
    //         break;
        
    //     case 7:
    //         cout << "Printing the values in the heap" << endl;
    //         minHeapObj.printArray();
    //         break;

    //     case 8:
    //         system("cls");
    //         break;

    //     case 9:
    //         cout << "Heap sorted array is : " << endl;
    //         minHeapObj.heapSort();
        
    //     default:
    //         cout << "Enter proper option number!" << endl;
    //     }
    // }while(option!=0);
}