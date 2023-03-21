use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let input: Vec<i32> = input.trim().split_whitespace().map(|x| x.parse().unwrap()).collect();
    let x = input[0];
    let y = input[1];
    if x * (100 - y) / 100 < 100 {
        println!("1");
    } else {
        println!("0");
    }
}
