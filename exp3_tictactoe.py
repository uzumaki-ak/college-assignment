def print_board(board):
    for row in board:
        print(' | '.join(row))
        print('-' * 9)

def check_winner(board, player):
    for row in board:
        if all(cell == player for cell in row): return True
    for col in range(3):
        if all(board[row][col] == player for row in range(3)): return True
    if all(board[i][i] == player for i in range(3)): return True
    if all(board[i][2-i] == player for i in range(3)): return True
    return False

def tic_tac_toe():
    board = [[' ']*3 for _ in range(3)]
    players = ['X', 'O']
    moves = [(0,0), (1,1), (0,1), (2,0), (0,2)]
    turn = 0
    for r, c in moves:
        player = players[turn % 2]
        board[r][c] = player
        print(f"\nPlayer {player} plays at ({r},{c}):")
        print_board(board)
        if check_winner(board, player):
            print(f"Player {player} wins!")
            return
        turn += 1
    print("It's a Draw!")

tic_tac_toe()
