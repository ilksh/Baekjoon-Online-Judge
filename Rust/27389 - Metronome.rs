use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read line");
    
    let number: f32 = input.trim().parse().expect("Invalid input");
    let result = number / 4.0;
    
    println!("{:.2}", result);
}
