#ifndef ARRAY_TEMPLATE_CLASS_SPLITTING_H
#define ARRAY_TEMPLATE_CLASS_SPLITTING_H


template <class T>
class Array
{
private:
    int m_length;
    T *m_data;

public:
    Array()
    {
        m_length = 0;
        m_data = nullptr;
    }

    Array(int length)
    {
        m_data = new T[length];
        m_length = length;
    }

    ~Array()
    {
        delete[] m_data;
    }

    void Erase();
    T& operator[](int index);
    int getLength();
};


#endif // ARRAY_TEMPLATE_CLASS_SPLITTING_H
