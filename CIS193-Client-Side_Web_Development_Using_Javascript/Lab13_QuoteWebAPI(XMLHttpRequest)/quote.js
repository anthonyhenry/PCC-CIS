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

function fetchQuotes(topic, count) {
   // TODO: Modify to use XMLHttpRequest
   const ajax = new XMLHttpRequest();
   ajax.responseType = "json";
   // console.log(ajax);
   ajax.addEventListener("load", responseReceivedHandler);
   // Create the api request url using the topic and count parameters
   const apiRequest = "https://wp.zybooks.com/quotes.php?topic=" + topic + "&count=" + count;
   ajax.open("GET", apiRequest);
   ajax.send();

   // let html = "<ol>";
   // for (let c = 1; c <= count; c++) {
   //    html += `<li>Quote ${c} - Anonymous</li>`;
   // }
   // html += "</ol>";

   // document.querySelector("#quotes").innerHTML = html;
}

// TODO: Add responseReceivedHandler() here
function responseReceivedHandler()
{
   // Create a variable for holding all the html changes
   let html = "";

   // Check if an error is present
   if(this.response.error)
   {
      // Display the error message
      html += this.response.error;
   }
   else
   {
      // Create an html ordered list
      html += "<ol>";

      // Add the quotes and sources to the ordered list
      for(let i = 0; i < this.response.length; i++)
      {
         html += "<li>" + this.response[i].quote + " - " + this.response[i].source + "</li>";
      }

      // Close the ordered list
      html += "</ol>"
   }
   
   // Update the html in the #quotes div
   document.querySelector("#quotes").innerHTML = html;
}