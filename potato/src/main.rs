#[macro_use]
extern crate serde_json;

use std::fs;
use std::process::Command;
use std::io::{self, Read};

fn get(key: String) {
    let output = Command::new("grep").arg(key).arg("./log").output()
        .expect("Fail to execute grep.");
    println!("{}", output.status);
    println!("{}", String::from_utf8_lossy(&output.stdout));
}

fn main() -> io::Result<()> {
    println!("Hello, world!");
    /*
    let j = json!({
        "key": "value",
        "key2": 43,
        "list_key": [1,2,3]
    });

    println!("key: {}", j["key"]);
    println!("{}", j.to_string());

    fs::write("./log", j.to_string()).expect("Unable to write file");
    */

    let mut stdin = io::stdin();
    let input = &mut String::new();

    loop {
        input.clear();
        stdin.read_line(input);
        if input.starts_with("get ") {
            get(String::from(&input[4..]));
        }

        println!("the input {}", input);
        if input == "exit" {
            println!("Bye.");
            break;
        }
    }

    Ok(())
}
