#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void Ricart_Ararwaala() {
  int ns, ncs, timestamp, site;
  printf("Enter number of sites: ");
  scanf("%d", &ns);
  printf("Enter number of sites which want to enter critical section: ");
  scanf("%d", &ncs);

  int *ts = (int *)malloc(ns * sizeof(int));
  int *request = (int *)malloc(ncs * sizeof(int));

  for (int i = 0; i < ns; i++) {
    ts[i] = 0;
  }
  bool flag = false;
  for (int i = 0; i < ncs; i++) {
    printf("\nEnter timestamp: ");
    scanf("%d", &timestamp);
    printf("Enter site number: ");
    scanf("%d", &site);
    flag = false;
    for (int j = 0 && i > 0; j < ncs; j++) {
      if (timestamp == ts[j]) {
        printf("***Please Note: Ricart Agarwala mutual exclusion dosent deal with parallel processing or more than one process with same timestamp, process with this timestamp is already present on another site please enter diffrent value  ");
        i = i - 1;
        flag = true;
        continue;
      }
    }
    if (flag) continue;

    ts[site - 1] = timestamp;
    request[i] = site;
  }

  printf("\nSites and Timestamp:\n");
  for (int i = 0; i < ns; i++) {
    printf("%d %d\n", i + 1, ts[i]);
  }

  for (int i = 0; i < ncs; i++) {
    printf("\nRequest from site: %d\n", request[i]);
    for (int j = 0; j < ns; j++) {
      if (request[i] != (j + 1)) {
        if (ts[j] > ts[request[i] - 1] || ts[j] == 0)
          printf("%d Replied\n", j + 1);
        else
          printf("%d Deferred\n", j + 1);
      }
    }
  }

  printf("\n");

  int *mp_timestamps = (int *)malloc(ncs * sizeof(int));
  int *mp_sites = (int *)malloc(ncs * sizeof(int));

  for (int i = 0; i < ncs; i++) {
    mp_timestamps[i] = 0;
    mp_sites[i] = 0;
  }

  for (int i = 0; i < ncs; i++) {
    mp_timestamps[i] = ts[request[i] - 1];
    mp_sites[i] = request[i];
  }

  for (int i = 0; i < ncs; i++) {
    printf("Site %d entered Critical Section\n", mp_sites[i]);
    if (i == 0)
      printf("Similarly,\n\n");
  }

  free(ts);
  free(request);
  free(mp_timestamps);
  free(mp_sites);
}

int main() {
  Ricart_Ararwaala();
  return 0;
}