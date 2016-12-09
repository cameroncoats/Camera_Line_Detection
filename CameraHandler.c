// Cameron Coats / Group 3
// EN0627 / NXP Car
//
// Linescan Camera Handler (High Level)

#include "CameraHandler.h"
#include "MKL25Z4.h"
#include <stdbool.h>
#include <stdio.h>


int getLineOffset(void){
  unsigned short int i,k,maxIndex,minIndex;
  short int diff[110],maxValue,minValue;

  // ensure that buffers are not swapped while calculating diffs
  // as this would give an unpredictable result
  CalcInProgress = true;
  // calculate differences
  k=0;
  for(i=10;i<118;i++){
    diff[k] = image[safeBuffer][i] - image[safeBuffer][i+1];
    k++;
  }
  // we are now done with the image buffer so the buffers can now be swapped
  CalcInProgress = false;
  // get min
  minValue = diff[0];
  minIndex = 0;
  for(i=0;i<106;i++){
    if(diff[i] < minValue){
      minValue = diff[i];
      minIndex = i;
    }
  }

  // get max
  maxValue = diff[0];
  maxIndex = 0;
  for(i=0;i<106;i++){
    if(diff[i] > maxValue){
      maxValue = diff[i];
      maxIndex = i;
    }
  }

  // get center point
  return (minIndex + ((maxIndex - minIndex) / 2)) - 53;
}
