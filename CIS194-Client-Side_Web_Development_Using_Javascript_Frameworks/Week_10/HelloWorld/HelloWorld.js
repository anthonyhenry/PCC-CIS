// 
// String
var message = 'Hello World';
console.log(message);
// Number
var i = 10;
console.log(i);
// Boolean
var fact = true;
console.log(fact);
// Any
// Any is a special type that you can use whenver you don't want a particular value to cause typechecking errors
var obj = {
    x: 0
};
// Assigning types to function parameters
function greet(name) {
    console.log("Hello, " + name + "!");
}
var me = "Anthony";
greet(me);
// Specifying function return types
function getFavoriteNumber() {
    return 26;
}
// null and undefined
// If you need a function to check for a specific type or null, you can use |
function doSomething(x) {
    if (x === null) {
        // do something
    }
    else {
        console.log("Hello there, " + x);
    }
}
function printPoint(pt) {
    console.log("(" + pt.x + ", " + pt.y + ")");
}
printPoint({ x: 100, y: 100 });
function printCord(cd) {
    console.log(cd.x + ", " + cd.y);
}
printCord({ x: 10, y: 10 });
