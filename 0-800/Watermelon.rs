use std::io;

fn main()
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed");
    let x : u32 = input.trim().parse().unwrap();
    if (x % 2 == 0) && (x > 2) {
        println!("YES");
    }
    else{
        println!("NO");
    }
}
