def main():
    matrix = []
    max_col = -1
    for _ in range(5):
        row = input()
        matrix.append(row)
        max_col = max(max_col, len(row))
    
    for i in range(5):
        cur_n = len(matrix[i])
        for j in range(cur_n, max_col):
            matrix += " "
    
    for col in range(max_col):
        for row in range(5):
            if matrix[row][col] != " ":
                print(matrix[row][col], end = "")
        
        
    

if __name__ == "__main__":
    main()
