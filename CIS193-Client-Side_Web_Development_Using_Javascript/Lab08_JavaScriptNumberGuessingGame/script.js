// Your solution goes here 
function playGuessingGame(numToGuess, numTriesAllowed = 10)
{
    // Initialize variables
    let guessCounter = 1;
    let userGuess = prompt("Enter a number between 1 and 100.");

    // Loop until the user guesses correctly, or the max number of tries has been reached
    while(userGuess != numToGuess && guessCounter < numTriesAllowed)
    {
        // Exit loop if the user hit cancel
        if(userGuess === null)
        {
            break;
        }

        // Convert the userGuess variable
        userGuess = parseInt(userGuess);

        console.log(userGuess);
        
        // Make sure the user guessed a number
        if(isNaN(userGuess) == true)
        {
            userGuess = prompt("Please enter a number.");
            continue;
        }
        // Guess is too small
        else if(userGuess < numToGuess)
        {
            userGuess = prompt(userGuess + " is too small. Guess a larger number.");
            guessCounter++;
            continue;
        }
        // Guess is too large
        else if(userGuess > numToGuess)
        {
            userGuess = prompt(userGuess + " is too large. Guess a smaller number.");
            guessCounter++;
            continue;
        }
    }

    // Return number of guesses if guessed correctly, 0 if not
    if(userGuess == numToGuess)
    {
        return guessCounter;
    }
    else
    {
        return 0;
    }
}