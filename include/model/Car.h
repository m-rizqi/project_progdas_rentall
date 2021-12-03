/**
 * Project Untitled
 */

#ifndef _CAR_H
#define _CAR_H

class Car
{
public:
    void Car();

    /**
     * @param id
     * @param name
     * @param police_number
     */
    void Car(long id, string name, string police_number);

    /**
     * Set the cars' id
     * @param id
     */
    void setId(long id);

    /**
     * Return cars' id
     */
    long getId();

    /**
     * Set the cars' name
     * @param name
     */
    void setName(string name);

    /**
     * Return cars' name
     */
    string getName();

    /**
     * Set the cars' police number
     * @param police_number
     */
    void setPoliceNumber(string police_number);

    /**
     * Return cars' police number
     */
    string getPoliceNumber();

    /**
     * @param rented
     */
    void setRented(bool rented);

    bool isRented();

    /**
     * Print the car information detail
     */
    void print();

    /**
     * Comparing two cars whether the same or not.
     */
    bool isEquals();

private:
    /**
     * Id will generated automatically
     */
    long id;
    /**
     * Name of car with the format :  Brand Type
     */
    string name;
    /**
     * Number police of the car
     */
    string police_number;
    bool rented;
};

#endif //_CAR_H