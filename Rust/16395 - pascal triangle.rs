use std::io;

// Function to calculate combination (n choose r) using dynamic programming and memoization
fn combination(n: i32, r: i32, memo: &mut Vec<Vec<i32>>) -> i32 {
    if n < r || n < 0 || r < 0 {
        return 0;
    }

    if memo[n as usize][r as usize] != -1 {
        return memo[n as usize][r as usize];
    }

    if r == 0 || n == r {
        memo[n as usize][r as usize] = 1;
    } else {
        memo[n as usize][r as usize] =
            combination(n - 1, r - 1, memo) + combination(n - 1, r, memo);
    }

    memo[n as usize][r as usize]
}

fn main() {
    // Read input values for n and r from the user
    let mut input_text = String::new();

    io::stdin().read_line(&mut input_text);

    let mut input_numbers = input_text
        .trim()
        .split_whitespace()
        .map(|s| s.parse::<i32>())
        .collect::<Vec<i32>>();


    let n = input_numbers[0];
    let r = input_numbers[1];

    let mut memo: Vec<Vec<i32>> = vec![vec![-1; (r + 1) as usize]; (n + 1) as usize];

    let result = combination(n - 1, r - 1, &mut memo);

    println!("{}", result);
}
