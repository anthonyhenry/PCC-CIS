window.addEventListener("DOMContentLoaded", function () {
   document.querySelector("#fetchQuotesBtn").addEventListener("click", function () {

      // Get values from drop-downs
      const topicDropdown = document.querySelector("#topicSelection");
      const selectedTopic = topicDropdown.options[topicDropdown.selectedIndex].value;
      const countDropdown = document.querySelector("#countSelection");
      const selectedCount = countDropdown.options[countDropdown.selectedIndex].value;
   
      // Get and display quotes
      fetchQuotes(selectedTopic, selectedCount);	   
   });
});

// TODO: Modify to use Fetch API
async function fetchQuotes(topic, count) {
   // Get the api url
   let url = "https://wp.zybooks.com/quotes.php?topic=" + topic + "&count=" + count;
   
   // fetch(url)
   // .then(function(response){
   //    console.log(response);
   //    return response.text();
   // })
   // .then(function(text){
   //    // Convert the api response string to a JSON object
   //    console.log(text);
   //    quotes = JSON.parse(text);

   //    // Create a variable for storing html edits
   //    let html = "";

   //    // Check if the api response returned an error
   //    if(quotes.error)
   //    {
   //       // Display the error message
   //       html += quotes.error;
   //    }
   //    else
   //    {
   //       html += "<ol>"
   //       // Iterate through the quotes json
   //       for(let quote of quotes)
   //       {
   //          // Add list items for each quote
   //          html += "<li>" + quote.quote + " - " + quote.source + "</li>" 
   //       }
   //       html += "</ol>";
   //    }

   //    // Update the quotes div's inner html
   //    document.querySelector("#quotes").innerHTML = html;
   // })
   // .catch(function(error) {
   //    console.log("Request failed", error)
   // });


   // Fetch API
   let response = await fetch(url);
   // Get the text response from the api
   let quotes = await response.text();
   // Convert the api response string to a JSON object
   quotes = JSON.parse(quotes);

   // Create a variable for storing html edits
   let html = "";

   // Check if the api response returned an error
   if(quotes.error)
   {
      // Display the error message
      html += quotes.error;
   }
   else
   {
      html += "<ol>"
      // Iterate through the quotes json
      for(let quote of quotes)
      {
         // Add list items for each quote
         html += "<li>" + quote.quote + " - " + quote.source + "</li>" 
      }
      html += "</ol>";
   }

   // Update the quotes div's inner html
   document.querySelector("#quotes").innerHTML = html;
}

