#include <stdio.h>
#include <assert.h>
#include <unistd.h>

int vitalsOk(float temperature, float pulseRate, float spo2) {
  if(temperature > 102 || temperature < 95) {
    printf("Temperature critical!\n");
    for (int i = 0; i < 6; i++)
    {
      printf("\r* ");
      fflush(stdout);
      sleep(1);
      printf("\r *");
      fflush(stdout);
      sleep(1);
    }

    return 0;
  } else if(pulseRate < 60 || pulseRate > 100) {
    printf("Pulse Rate is out of range!\n");
    for (int i = 0; i < 6; i++)
    {
      printf("\r* ");
      fflush(stdout);
      sleep(1);
      printf("\r *");
      fflush(stdout);
      sleep(1);
    }
    return 0;
  } else if(spo2 < 90) {
    printf("Oxygen Saturation out of range!\n");
    for (int i = 0; i < 6; i++)
    {
      printf("\r* ");
      fflush(stdout);
      sleep(1);
      printf("\r *");
      fflush(stdout);
      sleep(1);
    }
    return 0;
  }
  return 1;
}

int main() {
  assert(!vitalsOk(99, 102, 70));
  assert(vitalsOk(98.1, 70, 98));
  printf("Done\n");
}
