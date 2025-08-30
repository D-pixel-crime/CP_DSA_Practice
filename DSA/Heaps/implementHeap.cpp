#include <iostream>
#include <vector>
using namespace std;

class MinHeap
{
public:
    vector<int> arr;

    MinHeap(int data)
    {
        this->arr = {-1, data};
    }

    MinHeap(vector<int> &nums)
    {
        nums.insert(nums.begin(), -1);
        arr = nums;
    }

    void printHeap()
    {
        for (auto i : arr)
            cout << i << " ";
    }

    void heapify(vector<int> &arr, int i, int n)
    {
        int left = 2 * i, right = 2 * i + 1, smallest = i;

        if (left <= n && arr[left] < arr[smallest])
        {
            smallest = left;
        }
        if (right <= n && arr[right] < arr[smallest])
        {
            smallest = right;
        }

        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            heapify(arr, smallest, n);
        }
    }

    void insertIntoHeap(int data)
    {
        arr.push_back(data);
        int n = arr.size() - 1;
        int curr = n;

        while (curr > 1)
        {
            int parent = curr / 2;
            if (arr[parent] > arr[curr])
            {
                swap(arr[parent], arr[curr]);
                curr = parent;
            }
            else
                break;
        }
    }

    void deleteFromHeap()
    {
        if (arr.size() <= 1)
            return;

        int n = arr.size() - 1;
        swap(arr[1], arr[n]);
        arr.pop_back();

        heapify(this->arr, 1, n - 1);
    }

    void buildHeap(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), -1);
        for (int i = n / 2; i >= 1; i--)
        {
            heapify(nums, i, n);
        }

        for (auto i : nums)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    void heapSort()
    {
        int n = arr.size() - 1;
        for (int i = n / 2; i >= 1; i--)
        {
            heapify(arr, i, n);
        }

        for (int i = n; i > 1; i--)
        {
            swap(arr[i], arr[1]);
            heapify(arr, 1, i - 1);
        }
    }
};

int main()
{
    MinHeap *heap = new MinHeap(10);
    heap->insertIntoHeap(43);
    heap->insertIntoHeap(454);
    heap->insertIntoHeap(143);
    heap->insertIntoHeap(435);
    heap->insertIntoHeap(4);
    heap->insertIntoHeap(9);

    heap->printHeap();

    heap->deleteFromHeap();

    heap->heapSort();
    cout << endl;

    heap->printHeap();

    cout << endl;
    vector<int> temp = {3, -43, INT_MIN, 431, 4331};
    heap->buildHeap(temp);

    delete heap;
    return 0;
}