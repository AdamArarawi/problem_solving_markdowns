def solve_n_queens(n):
    result = []  
    columns = set()        
    pos_diagonals = set()  
    neg_diagonals = set()  
    board = [["."] * n for _ in range(n)] 

    def backtrack(row):
        if row == n:
            result.append(["".join(r) for r in board])
            return
        
        for col in range(n):
            if col in columns or (row + col) in pos_diagonals or (row - col) in neg_diagonals:
                continue  
            
            board[row][col] = "Q"
            columns.add(col)
            pos_diagonals.add(row + col)
            neg_diagonals.add(row - col)
            
            backtrack(row + 1)
            
            board[row][col] = "."
            columns.remove(col)
            pos_diagonals.remove(row + col)
            neg_diagonals.remove(row - col)
    
    backtrack(0)
    return result

n = int(input())
solutions = solve_n_queens(n)
for sol in solutions:
    for row in sol:
        print(row)
    print()  
