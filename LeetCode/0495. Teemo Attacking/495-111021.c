// Hao Ren
// 11 October, 2021
// 495. Teemo Attacking

int findPoisonedDuration(int *timeSeries, int timeSeriesSize, int duration) {
    int time = 0;
    for (int i = 0; i < timeSeriesSize - 1; i++) {
        if (timeSeries[i + 1] - timeSeries[i] < duration) {
            time += timeSeries[i + 1] - timeSeries[i];
        } else {
            time += duration;
        }
    }
    time += duration;
    return time;
}
