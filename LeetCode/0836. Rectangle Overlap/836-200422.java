class Solution {
    /**
     * Java solution for LeetCode problem No.836
     * 20 April, 2022
     * Rectangle Overlap
     * @author Hao Ren, hao.ren@student.unsw.edu.au
     */
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return !(rec1[0] >= rec2[2] ||
                    rec1[2] <= rec2[0] ||
                    rec1[1] >= rec2[3] ||
                    rec1[3] <= rec2[1]);
    }
}
