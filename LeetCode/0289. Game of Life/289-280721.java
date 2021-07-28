class Solution {
    /**
     * Java solution for LeetCode problem No.289
     * Game of Life
     * 28 July, 2021
     * @author Hao Ren, hao.ren@student@unsw.edu.au
     */
    private int size_row;
    private int size_col;

    private int countNeighbours(int[][] board, int x, int y) {
        /**
         * Helper function which MUST run with gameOfLife().
         */
        int count = 0;
        int up = x - 1;
        int down = x + 1;
        int left = y - 1;
        int right = y + 1;

        if (up >= 0 && left >= 0 && board[up][left] == 1) count++;
        if (up >= 0 && y >= 0 && y <= size_col - 1 && board[up][y] == 1) count++;
        if (up >= 0 && right <= size_col - 1 && board[up][right] == 1) count++;
        if (x >= 0 && x <= size_row - 1 && left >= 0 && board[x][left] == 1) count++;
        if (x >= 0 && x <= size_row - 1 && right <= size_col - 1 && board[x][right] == 1) count++;
        if (down <= size_row - 1 && left >= 0 && board[down][left] == 1) count++;
        if (down <= size_row - 1 && y >= 0 && y <= size_col - 1 && board[down][y] == 1) count++;
        if (down <= size_row - 1 && right <= size_col - 1 && board[down][right] == 1) count++;

        return count;

    }

    public void gameOfLife(int[][] board) {
        this.size_row = board.length;
        this.size_col = board[0].length;
        int[][] next = new int[size_row][size_col];
        for (int i = 0; i < size_row; i++) {
            for (int j = 0; j < size_col; j++) {
                next[i][j] = board[i][j];
            }
        }

        for (int r = 0; r < size_row; r++) {
            for (int c = 0; c < size_col; c++) {
                int neighbours = countNeighbours(board, r, c);
                if (board[r][c] == 1 && neighbours < 2) {
                    next[r][c] = 0;
                } else if (board[r][c] == 1 && neighbours > 3) {
                    next[r][c] = 0;
                } else if (board[r][c] == 1 && (neighbours == 2 || neighbours == 3)) {
                    next[r][c] = 1;
                } else if (board[r][c] != 1 && neighbours == 3) {
                    next[r][c] = 1;
                } else {
                    next[r][c] = board[r][c];
                }
            }
        }

        for (int m = 0; m < size_row; m++) {
            for (int n = 0; n < size_col; n++) {
                board[m][n] = next[m][n];
            }
        }
    }
}
