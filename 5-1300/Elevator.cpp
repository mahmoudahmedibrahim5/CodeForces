#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct
{
    int startFloor;     // The floor where the participant starts
    int endFloor;       // The floor that the participant wants to reach
    
    int startTime;      // The time when the participant starts on the startFloor
    int endTime;        // The minimum time for the participant to reach the endFloor (Required)
}Participants_t;

typedef enum
{
    UP,
    DOWN
}ElevatorDirection_t;

typedef struct
{
    int currentFloor;
    ElevatorDirection_t currentDirection;      
}Elevator_t;

void Elevator_getCurrentState(Elevator_t* elevator, int time, int floorsCount)
{
    if((time / (floorsCount - 1)) % 2 == 0)
    {
        elevator->currentDirection = UP;
        elevator->currentFloor = (time % (floorsCount - 1)) + 1; 
    }
    else
    {
        elevator->currentDirection = DOWN;
        elevator->currentFloor = floorsCount - (time % (floorsCount - 1));
    }
}

void Participant_getEndTime(Participants_t* participant, Elevator_t* elevator, int floorsCount)
{

    // Participant is already in the required floor
    if(participant->endFloor == participant->startFloor)
        participant->endTime = participant->startTime;

    // Participant Going up
    else if(participant->endFloor > participant->startFloor)
    {
        // Get the elevator status (Current floor and direction) at the start
        Elevator_getCurrentState(elevator, participant->startTime, floorsCount);
        
        // Elevator Going down
        if(elevator->currentDirection == DOWN)
            participant->endTime = participant->startTime 
                                 + elevator->currentFloor - 1  // Time for the elevator to reach first floor from current floor
                                 + participant->endFloor - 1;   // Time for the elevator to reach required floor from first floor
        

        // Elevator Going up
        else
        {
            // If the participant is upper the elevator
            if(participant->startFloor >= elevator->currentFloor)
                participant->endTime = participant->startTime
                                     + participant->endFloor - elevator->currentFloor; // Time for the elevator to reach required floor from current floor 

            // If the participant is down the elevator
            else
                participant->endTime = participant->startTime
                                     + floorsCount - elevator->currentFloor  // Time for the elevator to reach highest floor from current floor
                                     + floorsCount - 1                       // Time for the elevator to reach first floor from the highest floor
                                     + participant->endFloor - 1;            // Time for the elevator to reach required floor from first floor
        }
    }

    // Participant Going down
    else if(participant->endFloor < participant->startFloor)
    {
        // Get the elevator status (Current floor and direction) at the start
        Elevator_getCurrentState(elevator, participant->startTime, floorsCount);
        
        // Elevator Going up
        if(elevator->currentDirection == UP)
            participant->endTime = participant->startTime 
                                 + floorsCount - elevator->currentFloor  // Time for the elevator to reach highest floor from current floor
                                 + floorsCount - participant->endFloor;  // Time for the elevator to reach required floor from highest floor

        // Elevator Going down
        else
        {
            // If the participant is down the elevator
            if(participant->startFloor <= elevator->currentFloor)
                participant->endTime = participant->startTime
                                     + elevator->currentFloor - participant->endFloor; // Time for the elevator to reach required floor from current floor

            // If the participant is upper the elevator
            else
                participant->endTime = participant->startTime
                                     + elevator->currentFloor - 1               // Time for the elevator to reach first floor from current floor
                                     + floorsCount - 1                          // Time for the elevator to reach highest floor from first floor
                                     + floorsCount - participant->endFloor;     // Time for the elevator to reach required floor from highest floor
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    Participants_t* participant = new Participants_t;
    Elevator_t* elevator = new Elevator_t;

    for(int i = 0; i < n; i++)
    {
        cin >> participant->startFloor >> participant->endFloor >> participant->startTime;
        Participant_getEndTime(participant, elevator, m);
        cout << participant->endTime << endl;
    }
    
    delete participant;
    delete elevator;
}
