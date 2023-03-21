use std::io;

fn main() {
    // Input number of test cases
    let mut t = String::new();
    io::stdin().read_line(&mut t).unwrap();
    let t: usize = t.trim().parse().unwrap();

    // Iterate over test cases
    for _ in 0..t {
        // Input an integer
        let mut n = String::new();
        io::stdin().read_line(&mut n).unwrap();
        let n: i32 = n.trim().parse().unwrap();

        // Print the integer twice
        println!("{} {}", n, n);
    }
}
