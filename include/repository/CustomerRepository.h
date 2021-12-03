#include <iostream>
#include <vector>
#include "../../src/repository/Repository.cpp"
using namespace std;


class CustomerRepository : public Repository<Customer>{
public:
/**
 * @brief Get the Instance object
 * 
 * @return CustomerRepository* 
 */
static CustomerRepository *getInstance();

/**
 * @param name
 */
Customer searchByName(string name);

private:
/**
* Singleton class
*/
static CustomerRepository *_instance;
/**
 * private consturctor
 */
CustomerRepository();
};
