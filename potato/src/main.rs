#[macro_use]
extern crate serde_json;

use std::fs;

fn main() {
    println!("Hello, world!");
    let j = json!({
        "key": "value",
        "key2": 43,
        "list_key": [1,2,3]
    });

    println!("key: {}", j["key"]);
    println!("{}", j.to_string());

    fs::write("./log", j.to_string()).expect("Unable to write file");
}
