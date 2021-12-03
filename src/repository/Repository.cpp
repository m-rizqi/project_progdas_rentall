/**
 * Project Untitled
 */


#include "Repository.h"

/**
 * Repository implementation
 */


/**
 * read file and then convert it into object of T
 * @return vector<T>
 */
vector<T> Repository::readAllData() {
    return null;
}

/**
 * add new line into data file
 * @param object
 */
void Repository::appendData(T object) {

}

/**
 * change line that represent the data
 * @param object
 */
void Repository::updateData(T object) {

}

/**
 * delete line that represent the data
 * @param id
 */
void Repository::deleteData(long id) {

}

/**
 * find line that match with id and then convert it into object of T
 * @param id
 * @return T
 */
T Repository::findData(long id) {
    return null;
}

/**
 * convert string (form read data) into object of T
 * @param line
 * @return T
 */
virtual T Repository::stringToData(string line) {
    return null;
}

/**
 * convert object of T into string to store it int file
 * @param object
 * @return string
 */
virtual string Repository::dataToString(T object) {
    return "";
}

/**
 * @return long
 */
long Repository::generateId() {
    return 0;
}