#ifndef CAR_HPP
#define CAR_HPP

class Car
{
public:
    Car(unsigned int number_of_free_seats);
    bool hasFreeSeats() const;
    void reserveFreeSeat();

private:
    unsigned int free_seats;
};

#endif
