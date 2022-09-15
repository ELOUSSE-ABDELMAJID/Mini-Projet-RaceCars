#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

// Structures section
struct Race
{
    int numberOfLaps;
    int currentLap;
    char firstPlaceDriverName[20];
    char firstPlaceCarColor[20];
};

struct RaceCar
{
    char driverName[20];
    char raceCarColor[20];
    int totalLapTime;
};

// Print functions section
void    printIntro()
{
    printf("Bienvenue à notre événement principal, les fans de course numérique !\nJ'espère que tout le monde a pris son goûter car nous allons commencer !\n");
}

void    printCountDown()
{
    sleep(1);
    printf("Coureurs prêts ! Dans...\n");
    sleep(1);
    for (int i = 5; i > 0; i--)
    {
        printf("%d\n", i);
        sleep(1);
    }
    printf("Course !\n");
}

void    printFirstPlaceAfterLap(struct Race Race)
{
    printf("Après le tour numéro %d\nLa première place est occupée par : %s dans la voiture de course %s !\n", Race.currentLap, Race.firstPlaceDriverName, Race.firstPlaceCarColor);
}

void    printCongratulation(struct Race race)
{
    printf("Félicitons tous %s, dans la voiture de course %s, pour son incroyable performance.\nC'était vraiment une belle course et bonne nuit à tous !\n", race.firstPlaceDriverName, race.firstPlaceCarColor);
}

// Logic functions section
int calculateTimeToCompleteLap()
{
    int vitesse, acceleration, nerves;
    int sum;

    vitesse = rand() % (3 - 1 + 1) + 1;
    acceleration = rand() % (3 - 1 + 1) + 1;
    nerves = rand() % (3 - 1 + 1) + 1;
    sum = vitesse + acceleration + nerves;
    return (sum);
}

void    updateRaceCar(struct RaceCar *raceCar)
{
    raceCar->totalLapTime += calculateTimeToCompleteLap();
}

void    updateFirstPlace(struct Race *race, struct RaceCar *raceCar1, struct RaceCar *raceCar2)
{
    if (raceCar1->totalLapTime <= raceCar2->totalLapTime)
    {
        strcpy(race->firstPlaceDriverName, raceCar1->driverName);
        strcpy(race->firstPlaceCarColor, raceCar1->raceCarColor);
    }
    else
    {
        strcpy(race->firstPlaceDriverName, raceCar2->driverName);
        strcpy(race->firstPlaceCarColor, raceCar2->raceCarColor);
    }
}

void    startRace(struct RaceCar *raceCar1, struct RaceCar *raceCar2)
{
    struct Race race = {9, 1, "", ""};

    for (int i = 0; i < race.numberOfLaps; i++)
    {
        updateRaceCar(raceCar1);
        updateRaceCar(raceCar2);
        updateFirstPlace(&race, raceCar1, raceCar2);
        printFirstPlaceAfterLap(race);
        race.currentLap++;
        sleep(2);
    }
    printCongratulation(race);
}

int main()
{
    struct RaceCar raceCar1 = {"MJID", "BLACK", 0};
    struct RaceCar raceCar2 = {"AYOUB", "RED", 0};;

    printIntro();
    printCountDown();
    startRace(&raceCar1, &raceCar2);
    srand(time(0));
};