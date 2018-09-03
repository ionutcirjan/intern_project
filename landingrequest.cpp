#include "./landingrequest.h"

unsigned int LandingRequest::getFuel() const
{
    return fuel;
}

void LandingRequest::setFuel(unsigned int value)
{
    fuel = value;
}

LandingRequest::LandingRequest(unsigned int creationTime, int id, APlane *plane, unsigned int time,
                               bool urgent, unsigned int fuel, RequestType type) :
        PlaneRequest(creationTime, id, plane, time, urgent, type), fuel(fuel)
{
}

void LandingRequest::dump_request(std::ostream &ost) const
{
    ost << "Landing by id[" << getId() << "] on time " << getRequestTime() << " with priority " << isUrgent() << std::endl;
    ost << "\tWith plane: " << getPlaneInfo() << std::endl;
}

bool LandingRequest::checkFuel(unsigned int time) const
{
    unsigned int request_time = getRequestTime();
    unsigned int fuel = getFuel();
    unsigned int consumption = getPlaneInfo().getConsumption();
    return fuel > consumption * (time - request_time);
}

