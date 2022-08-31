#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structures section
struct Race {
  int  numberOfLaps;
  int currentLaps;
  char* firstPlaceDriverName;
  char* firstPlaceRaceCarColor;
};

struct RaceCar {
  char* driverName;
  char* raceCarColor;
  int totalLapTime;
};

// Print functions section
const char* printIntro(){
  printf("Welcome to our main event digital race fans!I hope everybody has their snacks because we are about to begin!");
}
const char* printCountDown(){
  printf("Racers Ready! In...\n5\n4\n3\n2\n1\nRACE!\n");
} 
void printFirstPlaceAfterLap(struct Race race){
  printf("After lap number %d\n", race.currentLaps);
}
void printCongratulation(struct Race race){
  printf("Let's all congratulate Cosmo in the orange race car for an amazing performance.It truly was a great race and everybody have a goodnight!");
}

// Logic functions section
int calculateTimeToCompleteLap(){
  int speed = (rand() % 3) + 1;
  int acceleration = (rand() % 3) + 1;
  int nerves = (rand() % 3) + 1;
  return speed + acceleration + nerves;
} 
void updateRaceCar(struct RaceCar* raceCarPointer){
  raceCarPointer->totalLapTime += calculateTimeToCompleteLap();
}
void updateFirstPlace(struct Race* racePointer, struct RaceCar* raceCar1Pointer, struct RaceCar* raceCar2Pointer){
  if(raceCar1Pointer->totalLapTime <= raceCar2Pointer -> totalLapTime) {
    racePointer -> firstPlaceDriverName = raceCar1Pointer -> driverName;
    racePointer -> firstPlaceRaceCarColor = raceCar1Pointer -> raceCarColor;
  } else {
    racePointer -> firstPlaceDriverName = raceCar2Pointer -> driverName;
    racePointer -> firstPlaceRaceCarColor = raceCar2Pointer -> raceCarColor;
  }
} 
void startRace(struct RaceCar* raceCar1Pointer, struct RaceCar* raceCar2Pointer){
  struct Race race = {
    .numberOfLaps = 5,
    .currentLaps = 1,
    .firstPlaceDriverName = "",
    .firstPlaceRaceCarColor = ""
  };
  for(int i = 0; i <= race.numberOfLaps; i++){
    updateRaceCar(raceCar1Pointer);
    updateRaceCar(raceCar2Pointer);
    updateFirstPlace(&race, raceCar1Pointer, raceCar2Pointer);
    printFirstPlaceAfterLap(race);
  }
  printCongratulation(race);
} 

int main() {
	srand(time(0));

  struct RaceCar raceCar1 = {
    .driverName = "Senna",
    .raceCarColor = "Red",
    .totalLapTime = 0
  };
    struct RaceCar raceCar2 = {
    .driverName = "Shummy",
    .raceCarColor = "White",
    .totalLapTime = 0
  };
  printIntro();
  startRace(&raceCar1, &raceCar2);
};