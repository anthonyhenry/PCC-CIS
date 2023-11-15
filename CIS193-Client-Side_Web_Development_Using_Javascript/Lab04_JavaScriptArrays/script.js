function divideArray(numbers)
{
    // Create empty arrays for even and odd numbers
    let evenNums = [];
    let oddNums = [];

    // Loop through the numbers array
    for(let i = 0; i < numbers.length; i++)
    {
        // Divide even and odd numbers to respective arrays
        if(numbers[i] % 2 == 0)
        {
            evenNums.push(numbers[i]);
        }
        else
        {
            oddNums.push(numbers[i]);
        }
    }

    // Sort arrays
    evenNums.sort(function(a, b){return a-b});
    oddNums.sort(function(a, b){return a-b});

    // Print Even Numbers
    console.log("Even numbers:");
    if(evenNums.length == 0)
    {
        console.log("None");
    }
    else
    {
        for(number of evenNums)
        {
            console.log(number);
        }
    }
    // Print odd numbers
    console.log("Odd numbers:")
    if(oddNums.length == 0)
    {
        console.log("None");
    }
    else
    {
        for(number of oddNums)
        {
            console.log(number);
        }
    }
}