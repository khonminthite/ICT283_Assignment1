/**
 * @file VectorTest.cpp
 * @author Khon Min Thite
 * @brief Unit test for Vector.h
 * @version 0.1
 * @date 29-2-2024
 *
 */


#include "Vector.H"
#include <iostream>

using namespace std;

int main()
{
     //Check that Constructor can correctly initialize an empty Vector and Operator[] can return a NULL pointer

    Vector<string> testVector;
    cout << "Check Constructor" << endl;
    try
    {
        cout << "Try retrieve: " << testVector[0] << endl;
    }
    catch (exception e)
    {
        cout << "Unable to retrieve any elements" << endl;
    }
    cout << endl;

    //Check that the copy constructor can correctly deep copy another Vector
    string text = "test", text2 = "test 2", test3 = "test 3";
    testVector.Insert(0, text);
    testVector.Insert(1, text2);
    testVector.Insert(2, test3);
    Vector<string> copyVector(testVector);

    cout << "Test Copy Constructor" << endl;
    cout << "Retrieving test Vector: " << testVector[0] << "  pointer: " << &testVector[0] << endl;
    cout << "Retrieving test Vector: " << testVector[1] << "  pointer: " << &testVector[1] << endl;
    cout << "Retrieving test Vector: " << testVector[2] << "  pointer: " << &testVector[2] << endl;
    cout << endl;
    cout << "Retrieving copy Vector: " << copyVector[0] << "  pointer: " << &copyVector[0] << endl;
    cout << "Retrieving copy Vector: " << copyVector[1] << "  pointer: " << &copyVector[1] << endl;
    cout << "Retrieving copy Vector: " << copyVector[2] << "  pointer: " << &copyVector[2] << endl;
    cout << endl;

    //Check that Size function can correctly return the size of the vector
    cout << "Check Size of test vector: " << testVector.Size() << endl;
    cout << endl;

    //Check that Capacity function can correctly return the capacity of the vector
    cout << "Check Capacity of test Vector: " << testVector.Capacity() << endl;
    cout << endl;

    //Check that the destructor  can successfully delete the Vector
    cout << "Test destructor" << endl;
    cout << "Size of copy Vector before destructing: " << copyVector.Size() << endl;
    copyVector.~Vector();
    cout << "Size of copy Vector after destructing: " << copyVector.Size() << endl;
    cout << endl;

    //Check that Operator= can correctly deep copy another Vector
    cout << " Test Operator = " << endl;
    Vector<string> copyVector2;
    copyVector2 = testVector;
    cout << "Retrieve test Vector pointer: " << &testVector << endl;
    cout << "Retrieving test Vector[0]: " << testVector[0] << ", pointer: " << &testVector[0] << endl;
    cout << "Retrieving test Vector[1]: " << testVector[1] << ", pointer: " << &testVector[1] << endl;
    cout << "Retrieving test Vector[2]: " << testVector[2] << ", pointer: " << &testVector[2] << endl;
    cout << endl;
    cout << "Retrieve copy Vector pointer: " << &copyVector2 << endl;
    cout << "Retrieving copy Vector[0]: " << copyVector2[0] << ", pointer: " << &copyVector2[0] << endl;
    cout << "Retrieving copy Vector[1]: " << copyVector2[1] << ", pointer: " << &copyVector2[1] << endl;
    cout << "Retrieving copy Vector[2]: " << copyVector2[2] << ", pointer: " << &copyVector2[2] << endl;
    cout << endl;

    //Check that Resize function can correctly increase the capacity of the vector by multiple of 2 if it is not enough
    cout << "Check Resize(int) function" << endl;
    cout << "current size and capacity of vector, size(" << copyVector2.Size() << ") capacity(" << copyVector2.Capacity() << ")" << endl;
    copyVector2.Resize(5);
    cout << "size and capacity of vector after resizing to 5, size(" << copyVector2.Size() << ") capacity(" << copyVector2.Capacity() << ")" << endl;
    copyVector2.Resize(3);
    cout << "size and capacity of vector after resizing to 3, size(" << copyVector2.Size() << ") capacity(" << copyVector2.Capacity() << ")" << endl;
    cout << endl;

    //Check that Erase function can correctly remove an element in a vector while shifting all elements after the index to the left
    cout << "Check Erase(int)" << endl;
    cout << "Retrieving Vector index 0: " << copyVector2[0] << endl;
    cout << "Retrieving Vector index 1: " << copyVector2[1] << endl;
    cout << "Retrieving Vector index 2: " << copyVector2[2] << endl;
    cout << endl;
    copyVector2.Erase(1);
    cout << "After erasing element at index 1" << endl;
    cout << "Retrieving Vector index 0: " << copyVector2[0] << endl;
    cout << "Retrieving Vector index 1: " << copyVector2[1] << endl;
    cout << endl;

    //Check that Insert function can correctly insert an element in a vector while shifting all elements from the index to the right
    cout << "Check Insert(int,<T>)" << endl;
    cout << "Retrieving copy Vector index 0: " << copyVector2[0] << endl;
    cout << "Retrieving copy Vector index 1: " << copyVector2[1] << endl;
    cout << endl;

    copyVector2.Insert(1, "Test");
    cout << "Inserted new element at index 1" << endl;
    cout << "Retrieving Vector index 0: " << copyVector2[0] << endl;
    cout << "Retrieving Vector index 1: " << copyVector2[1] << endl;
    cout << "Retrieving Vector index 2: " << copyVector2[2] << endl;
    cout << endl;

    //Check that clear function can correctly remove all elements in a vector
    cout << "Check clear()" << endl;
    cout << "Size of Vector before clearing: " << copyVector2.Size() << endl;

    copyVector2.Clear();
    cout << "Size of Vector after clearing: " << copyVector2.Size() << endl;
    return 0;
}
