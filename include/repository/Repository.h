#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Repository{
    private:
    vector<T> objectList;
    string filePath;
public:
    Repository(string filePath);
    vector<T> readObjectFile();
    void appendObjectFile(T object);
    void updateObject(T object);
    void deleteObject(T object);
    T findObject(long id);
    virtual string objectToString(T object);
    virtual T stringToObject(string data);
};