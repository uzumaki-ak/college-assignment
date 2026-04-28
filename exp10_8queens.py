def solve_queens(n=8):
    solutions = []

    def is_safe(board, row, col):
        for r in range(row):
            c = board[r]
            if c == col or abs(c - col) == abs(r - row):
                return False
        return True

    def backtrack(board, row):
        if row == n:
            solutions.append(board[:])
            return
        for col in range(n):
            if is_safe(board, row, col):
                board[row] = col
                backtrack(board, row + 1)
                board[row] = -1

    backtrack([-1]*n, 0)
    return solutions

solutions = solve_queens()
print(f"Total solutions for 8-Queens: {len(solutions)}\n")
print("First solution (column index per row):", solutions[0])
print("\nBoard:")
for row in range(8):
    line = ['.'] * 8
    line[solutions[0][row]] = 'Q'
    print(' '.join(line))
