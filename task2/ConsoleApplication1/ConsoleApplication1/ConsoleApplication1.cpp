#include <iostream>
#include <vector>

struct HeapNode {
    int id;
    int value;
};

class Heap {
private:
    std::vector<HeapNode> heap;
    bool isMaxHeap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if ((isMaxHeap && heap[index].value > heap[parentIndex].value) ||
                (!isMaxHeap && heap[index].value < heap[parentIndex].value)) {
                std::swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            }
            else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int top = index;

        if (isMaxHeap && leftChild < heap.size() && heap[leftChild].value > heap[top].value) {
            top = leftChild;
        }

        if (isMaxHeap && rightChild < heap.size() && heap[rightChild].value > heap[top].value) {
            top = rightChild;
        }

        if (!isMaxHeap && leftChild < heap.size() && heap[leftChild].value < heap[top].value) {
            top = leftChild;
        }

        if (!isMaxHeap && rightChild < heap.size() && heap[rightChild].value < heap[top].value) {
            top = rightChild;
        }

        if (top != index) {
            std::swap(heap[index], heap[top]);
            heapifyDown(top);
        }
    }

public:
    Heap(bool maxHeap = true) : isMaxHeap(maxHeap) {}

    void insert(int id, int value) {
        HeapNode newNode = { id, value };
        heap.push_back(newNode);
        heapifyUp(heap.size() - 1);
    }

    void remove(int id) {
        for (size_t i = 0; i < heap.size(); ++i) {
            if (heap[i].id == id) {
                heap[i] = heap.back();
                heap.pop_back();
                heapifyDown(i);
                break;
            }
        }
    }

    int find(int id) {
        for (size_t i = 0; i < heap.size(); ++i) {
            if (heap[i].id == id) {
                return heap[i].value;
            }
        }
        return -1; // Элемент не найден
    }

    void sortAscending() {
        for (int i = heap.size() / 2 - 1; i >= 0; --i) {
            heapifyDown(i);
        }
    }

    void sortDescending() {
        for (int i = heap.size() / 2 - 1; i >= 0; --i) {
            heapifyDown(i);
        }
        std::reverse(heap.begin(), heap.end());
    }

    void print() {
        for (const HeapNode& node : heap) {
            std::cout << "ID: " << node.id << ", Value: " << node.value << std::endl;
        }
    }
};

int main() {
    Heap minHeap(false); // Создание мин-кучи
    Heap maxHeap(true);  // Создание макс-кучи

    int choice;
    while (true) {
        std::cout << "Select an option:" << std::endl;
        std::cout << "1. Insert into Min-Heap" << std::endl;
        std::cout << "2. Remove from Min-Heap" << std::endl;
        std::cout << "3. Find in Min-Heap" << std::endl;
        std::cout << "4. Sort Min-Heap in Ascending Order" << std::endl;
        std::cout << "5. Sort Min-Heap in Descending Order" << std::endl;
        std::cout << "6. Print Min-Heap" << std::endl;
        std::cout << "7. Insert into Max-Heap" << std::endl;
        std::cout << "8. Remove from Max-Heap" << std::endl;
        std::cout << "9. Find in Max-Heap" << std::endl;
        std::cout << "10. Sort Max-Heap in Ascending Order" << std::endl;
        std::cout << "11. Sort Max-Heap in Descending Order" << std::endl;
        std::cout << "12. Print Max-Heap" << std::endl;
        std::cout << "0. Exit" << std::endl;

        std::cin >> choice;

        switch (choice) {
        case 1: {
            int id, value;
            std::cout << "Enter ID and value: ";
            std::cin >> id >> value;
            minHeap.insert(id, value);
            break;
        }
        case 2: {
            int id;
            std::cout << "Enter ID to remove: ";
            std::cin >> id;
            minHeap.remove(id);
            break;
        }
        case 3: {
            int id;
            std::cout << "Enter ID to find: ";
            std::cin >> id;
            int result = minHeap.find(id);
            if (result != -1) {
                std::cout << "Found in Min-Heap: " << result << std::endl;
            }
            else {
                std::cout << "Not found in Min-Heap." << std::endl;
            }
            break;
        }
        case 4: {
            minHeap.sortAscending();
            break;
        }
        case 5: {
            minHeap.sortDescending();
            break;
        }
        case 6: {
            std::cout << "Min-Heap:" << std::endl;
            minHeap.print();
            break;
        }
        case 7: {
            int id, value;
            std::cout << "Enter ID and value: ";
            std::cin >> id >> value;
            maxHeap.insert(id, value);
            break;
        }
        case 8: {
            int id;
            std::cout << "Enter ID to remove: ";
            std::cin >> id;
            maxHeap.remove(id);
            break;
        }
        case 9: {
            int id;
            std::cout << "Enter ID to find: ";
            std::cin >> id;
            int result = maxHeap.find(id);
            if (result != -1) {
                std::cout << "Found in Max-Heap: " << result << std::endl;
            }
            else {
                std::cout << "Not found in Max-Heap." << std::endl;
            }
            break;
        }
        case 10: {
            maxHeap.sortAscending();
            break;
        }
        case 11: {
            maxHeap.sortDescending();
            break;
        }
        case 12: {
            std::cout << "Max-Heap:" << std::endl;
            maxHeap.print();
            break;
        }
        case 0: {
            std::cout << "Exiting the program." << std::endl;
            return 0;
        }
        default: {
            std::cout << "Invalid choice. Please select a valid option." << std::endl;
            break;
        }
        }
    }

    return 0;
}
