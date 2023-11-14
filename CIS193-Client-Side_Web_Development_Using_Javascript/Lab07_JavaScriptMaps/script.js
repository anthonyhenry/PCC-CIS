function calcWordFrequencies() {
    // Prompt the user for input ans store the input in a variable
    let userInput = prompt("Provide a list of words seperated by spaces.")
    // Split the input into an array of seperate words
    userInput = userInput.split(" ");

    // Initialize a word frequencies map
    let wordFrequencies = new Map();

    // For loop that iterates through all the words in the input array
    for(let word of userInput)
    {
        // Check if a word is not already in the map
        if(wordFrequencies.has(word) == false)
        {
            wordFrequencies.set(word, 1);
        }
        // If a word is already in the map, increment it's value
        else
        {
            wordFrequencies.set(word, wordFrequencies.get(word) + 1);
        }
    }

    // Print the map to the console
    for(let [word, frequency] of wordFrequencies)
    {
        console.log(word + " " + frequency);
    }
}