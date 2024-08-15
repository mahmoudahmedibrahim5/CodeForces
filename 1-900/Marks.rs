use std::io;

fn main() {
    /* Input number of students and number of grades */
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed");
    let mut itr = input.split_whitespace();
    let n: u32 = itr.next().unwrap().parse().expect("Input is incomplete");
    let m: u32 = itr.next().unwrap().parse().expect("Input is incomplete");

    /* Input the marks */
    let mut marks: Vec<Vec<u8>> = Vec::with_capacity(n as usize);
    let mut student_marks = vec![0; m as usize];
    for _ in 0..n
    {
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Failed");
        let mut j: usize = 0;
        for c in input.chars()
        {
            if c >= '0' && c <= '9'{
                student_marks[j] = c.to_digit(10).unwrap() as u8;
            }
            j += 1;
        }
        marks.push(student_marks.clone());
    }

    /* Find Succesful students */
    let mut succesful: u32 = 0;
    let mut students_grade = vec![false; n as usize];
    for i in 0..m as usize
    {
        let mut greater: u8 = 0;
        for j in 0..n as usize
        {
            if marks[j][i] > greater{
                greater = marks[j][i];
            }
        }
        for j in 0..n as usize
        {
            if marks[j][i] == greater && students_grade[j] == false{
                succesful += 1;
                students_grade[j] = true;
            }
        }
    }
    println!("{}", succesful);
}
