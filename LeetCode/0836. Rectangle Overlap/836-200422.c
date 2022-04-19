// Hao Ren
// 20 April, 2022
// 836. Rectangle Overlap

bool isRectangleOverlap(int *rec1, int rec1Size, int *rec2, int rec2Size) {
    // False conditions:
    // Notice the negation (!) below.
    return !(rec1[0] >= rec2[2] ||        // R1x1 >= R2x2
             rec1[2] <= rec2[0] ||        // R1x2 <= R2x1
             rec1[1] >= rec2[3] ||        // R1y1 >= R2y2
             rec1[3] <= rec2[1]);         // R1y2 <= R2y1
    // Otherwise True.
}
