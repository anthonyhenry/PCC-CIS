// Your solution goes here 
function playGuessingGame(numToGuess, numTriesAllowed)
{
    // Initialize variables
    let guessCounter = 1;
    let userGuess = prompt("Enter a number between 1 and 100");

    while(userGuess != numToGuess && guessCounter < numTriesAllowed)
    {
        userGuess = prompt("Try again.")
        guessCounter++;
    }

    if(userGuess == numToGuess)
    {
        return guessCounter;
    }
    else
    {
        return 0;
    }

    // if(userGuess < numToGuess)
    // {
    //     userGuess = prompt(userGuess + " is too small. Guess a larger number");
    // }
    // else if(userGuess > numToGuess)
    // {
    //     userGuess = prompt(userGuess + " is too large. Guess a smaller number");
    // }
    // else if(isNaN(userGuess) == true)
    // {
    //     userGuess = prompt("Please enter a number");
    // }
    // else if(userGuess === undefined)
    // {
    //     return 0;
    // }
    // else
    // {
    //     console.log(isNaN(userGuess));
    //     return 7;
    // }

    console.log(userGuess);
}

// console.log("Return value: " + playGuessingGame());

console.log(playGuessingGame(7,3));