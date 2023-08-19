#include <iostream>
using namespace std;

template <typename T>
class ArrayList
{
private:
    unsigned int count = 0;
    T *thisArray = nullptr;

    void allocate(T *helper)
    {
        delete[] thisArray;
        thisArray = helper;
    }

    void allocateAdd()
    {
        T *helper = new T[count];
        for (unsigned int i = 0; i < count; i++)
        {
            helper[i] = thisArray[i];
        }
        allocate(helper);
    }

    void allocateRemove(int index)
    {
        T *helper = new T[count];
        unsigned int i = 0, j = 0;
        while (i < count)
        {
            if (i == index)
            {
                j++;
            }
            helper[i] = thisArray[j];
            i++;
            j++;
        }
        allocate(helper);
    }

public:
    ArrayList()
    {
        thisArray = new T[1];
    }

    ~ArrayList()
    {
        delete[] thisArray;
    }

    void Add(T element)
    {
        ++count;
        allocateAdd();
        thisArray[count - 1] = element;
    }

    void Remove(T element)
    {
        --count;

        for (unsigned int i = 0; i < count; i++)
        {
            if (thisArray[i] == element)
            {
                allocateRemove(i);
                break;
            }
        }
    }

    void Print()
    {
        for (unsigned short i = 0; i < count; i++)
        {
            cout << thisArray[i] << " ";
        }
        cout << '\n';
    }

    T &operator[](unsigned int index)
    {
        if (index > count)
        {
            throw out_of_range("Index out of range");
        }
        return thisArray[index];
    }
};

int main()
{
    ArrayList<float> arrayFloat;
    arrayFloat.Add(3.4);
    arrayFloat.Add(6.3);
    arrayFloat.Print();
    arrayFloat.Add(120.9);
    arrayFloat.Print();
    arrayFloat.Remove(6.3);
    arrayFloat.Print();

    ArrayList<char> arrayChar;
    arrayChar.Add('s');
    arrayChar.Add('t');
    arrayChar.Print();
    arrayChar.Add('4');
    arrayChar.Print();
    arrayChar.Remove('t');
    arrayChar.Print();

    cout << arrayChar[1];
    return 0;
}