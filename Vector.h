/**
 * @file Vector.h
 * @author Khon Min Thite
 * @brief A template class of dynamic array
 * @version 0.1
 * @date 2024-02-18
 *
 */

#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

template<class T>
class Vector
{
public:

    /**
     * @brief Construct a new Vector object
     *
     */
    Vector();

    /**
     * @brief Construct a new Vector object and deep copies the elements of another Vector object into the new Vector
     *
     * @param other - Another Vector Object
     */
    //Vector(Vector& other);
    Vector(Vector<T>& other);

    /**
     * @brief Destroy the Vector object
     *
     */
    ~Vector();

    /**
     * @brief Get the current size
     *
     * @return unsigned int - The current size of the Vector
     */
    unsigned int Size() const
    {
        return m_size;
    }

    /**
     * @brief Get the current capacity
     *
     * @return unsigned int - The current capacity of the Vector
     */
    unsigned int Capacity() const
    {
        return m_capacity;
    }

    /**
     * @brief Deep copies another vector's elements into a existing Vector
     *
     * @param other - Another Vector Object
     *
     */
    //void operator = (Vector& other);
    Vector<T>& operator=(Vector<T>& other);

    /**
     * @brief Retrieve an element from a given index position
     *
     * @param index - The index position of the element to be retrieved
     * @return constant T& - The element data passed by reference
     */
    const T& operator[](const unsigned int& index) const;

    /**
     * @brief Change the size of the vector to match the given size
     *
     * @param newSize - The Vector size to change the Vector to
     */
    void Resize(const unsigned int& newSize);

    /**
     * @brief Removes an element from an index position and moves all elements on the right to the left to fill in the removed element's position
     *
     * @param index - the index of the element to be removed
     */
    //void Erase(const unsigned int& index);

    /**
     * @brief Inserts an element at the given index position and move all elements from the index to the right to make space for the element to be inserted
     *
     * @param position - index position of the element to be inserted
     * @param value - data value of the element
     */
    //void Insert(const unsigned int& position, const T& value);

    bool Erase(const unsigned int& index);

    bool Insert(const unsigned int& index, const T& value);

    bool add(const T& value);

    bool remove(const T& value);

    /**
     * @brief Sets the size to 0. Make the Vector empty
     *
     */
    void Clear();

private:
    //The pointer of the Vector
    T* m_pointer;
    //The number of elements in the Vector
    unsigned int m_size;
    //The max number of element the Vector is expected to hold
    unsigned int m_capacity;

    /**
     * @brief Increase the capacity of Vector by 2 times if capacity is maxed
     *
     * @param newCapacity - The current capacity of the Vector
     */
    void Reserve(unsigned int newCapacity);

    /**
     * @brief Multiply a int by 2
     *
     * @param size - The current capacity
     * @return unsigned int - The multiplied capacity
     */
    unsigned int MultiplyBy2(const unsigned int& size)
    {
        return m_size * 2;
    }

    /**
     * @brief Deep copies a Vector into result given the first element and the last element memory position
     *
     * @param first - The pointer of the first element of a Vector being copied
     * @param last - The pointer of the last element of a Vector being copied
     * @param result - The pointer of the Vector being copied to
     * @return T* - Returns result
     */
    T* DeepCopy(T* first, T* last, T* result);

    void DeepCopy(const Vector<T>& other);
};

//default constructor
template<class T>
Vector<T>::Vector(): m_pointer(NULL), m_size(0), m_capacity(0) {}


//copy constructor for vector object
/**
template<class T>
Vector<T>::Vector(Vector& other)
{
    //Creates a Vector in the other Vector's capacity
    m_pointer = new T[other.Capacity()];
    DeepCopy(other.m_pointer, other.m_pointer+other.Size(), m_pointer);

    //Sets this Vector to the other vector's size and capacity
    m_size = other.m_size;
    m_capacity = other.m_capacity;
}
**/

//**
template<class T>
Vector<T>::Vector(Vector<T>& other)
{
    DeepCopy(other);
}
/**/

//destroy vector object
template<class T>
Vector<T>::~Vector()
{
    //If Vector pointer is not null then delete it and set to null
    if(m_pointer != nullptr)
    {
        delete[] m_pointer;
        m_pointer = nullptr;
    }

    //Set size and capacity of this vector to 0
    m_size = 0;
    m_capacity = 0;
}
/**
template<class T>
void Vector<T>::operator=(Vector& other)
{
    //Increase this vector's capacity to to capable to holding the other vector's element
    m_pointer=new T[other.Capacity()];
    DeepCopy(other.m_pointer,other.m_pointer+other.Size(),m_pointer);

    //Sets this vector's size to be the same
    m_size = other.m_size;
    m_capacity = other.m_capacity;
}
**/
//**
template<class T>
Vector<T>& Vector<T>::operator=(Vector<T>& other)
{
    if (this != &other) // Check for self-assignment
    {
        DeepCopy(other);
    }
    return *this;
}
/**/
// Element read only access
template<class T>
const T& Vector<T>::operator[](const unsigned int& index) const
{
    //Checks if index is greater than or equal to the size of vector
    if(index >= m_size)
        throw out_of_range("");
    else
        return m_pointer[index];
}

template<class T>
void Vector<T>::Resize(const unsigned int& newSize)
{
    //Checks if the new size is greater than the capacity of Vector before trying to reserve more capacity
    if(newSize > m_capacity)
    {
        Reserve(newSize);
    }

    //Sets vector size to be the new size
    m_size=newSize;
}

/**
template<class T>
void Vector<T>::Erase(const unsigned int& index)
{
    //Checks if index is valid for the Vector
    if (index < 0 || index > m_size)
    {
        cout << "The location of the item to be removed is out of range." << endl;
    }
    else
    {
        //  Shift all the elements one step left, beginning from "index+1"
        for(unsigned int i = index; i < m_size-1; i++)
        {
            m_pointer[i] = m_pointer[i+1];
        }

        --m_size;
    }
}

template<class T>
void Vector<T>::Insert(const unsigned int& index, const T& value)
{
    // Create some space if it does not have enough to take another element
    if(m_capacity <= m_size)
    {
        Reserve(m_size);
    }
    m_size++;

    //  Shift all the elements one step towards right, beginning from "index"+1..
    for(unsigned int i = m_size-1; i > index; i--)
    {
        m_pointer[i] = m_pointer[i-1];
    }
    m_pointer[index] = value;
}
**/

template<class T>
bool Vector<T>::Insert(const unsigned int& index, const T& value)
{
    // Check if the index is within the valid range
    if (index > m_size)
    {
        return false; // Index out of range
    }

    // Check if the vector needs to resize
    if (m_size <= m_capacity)
    {
        Reserve(m_size); // Reserve space for one more element
    }
    m_size++;

    // Shift all the elements one step towards right, beginning from "index"+1..
    for(unsigned int i = m_size-1; i > index; i--)
    {
        m_pointer[i] = m_pointer[i-1];
    }
    m_pointer[index] = value;

    return true; // Return true to indicate success
}


template<class T>
bool Vector<T>::Erase(const unsigned int& index)
{
    // Check if the index is within the valid range
    if (index >= m_size)
    {
        return false; // Index out of range
    }

    // Shift all the elements one step left, beginning from "index+1"
    for(unsigned int i = index; i < m_size-1; i++)
    {
        m_pointer[i] = m_pointer[i+1];
    }

    m_size--; // Decrement the size

    return true; // Return true to indicate success
}

template<class T>
bool Vector<T>::add(const T& value)
{
    // Check if the vector needs to resize
    if (m_size == m_capacity)
    {
        Reserve(m_size + 1); // Reserve space for one more element
    }
    m_pointer[m_size] = value; // Add the new element at the end
    m_size++; // Increment the size
    return true; // Return true to indicate success
}

template<class T>
bool Vector<T>::remove(const T& value)
{
    for (unsigned int i = 0; i < m_size; i++)
    {
        if (m_pointer[i] == value)   // If the value is found
        {
            // Shift all elements to the left to fill the gap
            for (unsigned int j = i; j < m_size - 1; j++)
            {
                m_pointer[j] = m_pointer[j + 1];
            }
            m_size--; // Decrement the size
            return true; // Return true to indicate success
        }
    }
    return false; // Return false if the value was not found
}

template<class T>
void Vector<T>::Clear()
{
    m_size=0;
}

template<class T>
void Vector<T>::Reserve(unsigned int newCapacity)
{
    if( newCapacity == 0)
    {
        newCapacity = 1;
    }
    else
    {
        // Keep the capacity of the vector as a power of 2 to avoid space wastage
        newCapacity = MultiplyBy2(newCapacity);
    }
    if(newCapacity > m_capacity)
    {
        T* temp=new T[newCapacity];
        DeepCopy( m_pointer,m_pointer + m_capacity,temp );
        delete[] m_pointer;
        m_pointer = temp;
        m_capacity = newCapacity;
    }
}

// deep copy
template<class T>
T* Vector<T>::DeepCopy(T* first, T* last, T* result)
{
    //For the range from first to last copy to result
    while (first != last)
    {
        *result = *first;
        ++result;
        ++first;
    }
    return result;
}

///**
template<class T>
void Vector<T>::DeepCopy(const Vector<T>& other)
{
    // Allocate new memory for the vector being copied to
    T* temp = new T[other.m_capacity];

    // Perform the deep copy
    T* result = temp;
    T* first = other.m_pointer;
    T* last = other.m_pointer + other.m_size;
    while (first != last)
    {
        *result = *first;
        ++result;
        ++first;
    }

    // Set the size and capacity of the vector being copied to
    m_size = other.m_size;
    m_capacity = other.m_capacity;

    // Delete the old memory and assign the new memory to the vector being copied to
    delete[] m_pointer;
    m_pointer = temp;
}
//**/

#endif

