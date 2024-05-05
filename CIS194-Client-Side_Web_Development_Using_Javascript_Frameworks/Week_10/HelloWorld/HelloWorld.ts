// 

// String
let message: string = 'Hello World';
console.log(message);

// Number
let i: number = 10;
console.log(i);

// Boolean
let fact: boolean = true;
console.log(fact);

// Any
    // Any is a special type that you can use whenver you don't want a particular value to cause typechecking errors
let obj: any = {
    x: 0
};

// Assigning types to function parameters
function greet(name: string)
{
    console.log("Hello, " + name + "!");
}

let me: string = "Anthony";

greet(me);

// Specifying function return types
function getFavoriteNumber(): number
{
    return 26;
}

// null and undefined
    // If you need a function to check for a specific type or null, you can use |
function doSomething(x: string | null)
{
    if(x === null)
    {
        // do something
    }
    else
    {
        console.log("Hello there, " + x);
    }
}

// Type assertions
    // You can use type assertion to specify a more specific type
// const myCanvas = document.getElementById("") as HTMLCanvasElement;

// Type aliases
    // When you want to use the same type more than once and refer to it by a single name you can create a type alias
type Point = {
    x: number;
    y: number;
};

function printPoint(pt: Point)
{
    console.log("(" + pt.x + ", " + pt.y + ")");
}

printPoint({x: 100, y: 100});

// Interfaces
    // An interface is another way to name an object type
    // The difference between interfaces and type aliaces is that interfaces can be re-opened to add new properties to them
interface Cord {
    x: number;
    y: number;
}

function printCord(cd: Cord)
{
    console.log(cd.x + ", " + cd.y);
}

printCord({ x: 10, y: 10});