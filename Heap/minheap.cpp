#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
    int *arr;
    int capacity;
    int size;

public:
    MinHeap(int cap)
    {
        size = 0;
        capacity = cap;
        arr = new int[cap];
    }

    int parent(int x)
    {
        return ((x - 1) / 2);
    }

    int left(int x)
    {
        return (2 * x) + 1;
    }

    int right(int x)
    {
        return (2 * x) + 2;
    }

    void insertKey(int val)
    {
        if (size == capacity)
        {
            cout << "Heap full, cannot insert\n";
            return;
        }
        size++;
        int i = size - 1;
        arr[i] = val;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    void heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < size && arr[l] < arr[smallest])
        {
            smallest = l;
        }
        if (r < size && arr[r] < arr[smallest])
        {
            smallest = r;
        }
        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

    int extractMin()
    {
        if (size <= 0)
        {
            cout << "Heap Empty, Cannot Extract Minimum!\n";
            return INT_MAX;
        }
        if (size == 1)
        {
            size--;
            return arr[0];
        }

        int minele = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
        return minele;
    }

    void decreaseKey(int i, int x)
    {
        arr[i] = x;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }

    void heapsort()
    {
        while (size > 0)
        {
            cout << extractMin() << " ";
            heapify(0);
        }
    }

    void linearSearch(int key)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == key)
            {
                cout << key << " found in heap\n";
                return;
            }
        }
        cout << key << " not found in heap\n";
    }

    void printHeap()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int height()
    {
        return ceil(log2(size + 1)) - 1;
    }
};

int main()
{
    int s;
    cin >> s;
    MinHeap ob(s);
    ob.insertKey(5);
    ob.insertKey(3);
    ob.insertKey(7);
    ob.printHeap();
    // cout << ob.extractMin() << endl;
    // ob.deleteKey(1);
    ob.heapsort();
    // ob.printHeap();
    return 0;
}